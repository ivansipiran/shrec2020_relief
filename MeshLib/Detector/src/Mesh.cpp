#include <map>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <cassert>
#include <cfloat>
#include "Mesh.h"
#include "util.h"
#include "Clock.h"

namespace MeshLib{

Mesh::Mesh(){
       vertices = NULL;
       faces = NULL;
       numVertices = 0;
       numFaces = 0;
}

Mesh::Mesh(const char* filename)
{
	   vertices = NULL;
	   faces = NULL;
	   numVertices = 0;
	   numFaces = 0;

	   xmin = xmax = ymin = ymax = zmin = zmax = 0.0;

	   loadFromFile(filename);

       //Finding bounding box...
       for(register int i = 0; i < getNumberVertices(); i++){
       		if(vertices[i].getX() < xmin)
       			xmin = vertices[i].getX();
       		else if(vertices[i].getX() > xmax)
       			xmax = vertices[i].getX();

       		if(vertices[i].getY() < ymin)
       			ymin = vertices[i].getY();
       		else if(vertices[i].getY() > ymax)
       			ymax = vertices[i].getY();

       		if(vertices[i].getZ() < zmin)
       			zmin = vertices[i].getZ();
       		else if(vertices[i].getZ() > zmax)
       			zmax = vertices[i].getZ();
       }

       diag = sqrt((xmax - xmin)*(xmax - xmin) + (ymax - ymin)*(ymax - ymin) + (zmax - zmin)*(zmax - zmin));
}


Mesh::~Mesh(){
    	cleanMesh();
}

void Mesh::setNumberVertices(int nv){
	numVertices = nv;

	vertices = new Vertex[numVertices];
}

void Mesh::setNumberFaces(int nf){
	numFaces = nf;

	faces = new Face[numFaces];
}

//Clean up the object
void Mesh::cleanMesh(){
	if(faces){
	           delete[] faces;
			   faces = NULL;
	     }
	if(vertices){
	           delete[] vertices;
			   vertices = NULL;
	     }
}


void Mesh::loadFromFile(const char* filename){

	int numEdges;

	std::ifstream in(filename);

	std::string format;
	std::getline(in, format);
	assert(format.find("OFF") != std::string::npos);

	in>>numVertices>>numFaces>>numEdges;
	Util::skipline(in);

	vertices = new Vertex[numVertices];
	faces = new Face[numFaces];


	for(register int i = 0; i < numVertices; i++){
		double x, y, z;
		in>>x>>y>>z;
		Util::skipline(in);

		vertices[i].setX(x);	vertices[i].setY(y);	vertices[i].setZ(z);
		vertices[i].setIndex(i);
	}


	for(register int i = 0;  i < numFaces; i++){
		int numVert;
		in >> numVert;

		assert(numVert == 3);

		int p1, p2, p3;

		in>>p1>>p2>>p3;
		Util::skipline(in);

		if(p1==p2 || p2 == p3 || p1 == p3)
			std::cout << "Warning: face " << i << " contains a zero-length edge" << std::endl;

		faces[i].addVertex(p1);				faces[i].addVertex(p2);				faces[i].addVertex(p3);

		vertices[p1].addFace(i);			vertices[p2].addFace(i);			vertices[p3].addFace(i);

		vertices[p1].setNumFace(i);			vertices[p2].setNumFace(i);			vertices[p3].setNumFace(i);
		vertices[p1].setPosBarycentric(0);	vertices[p2].setPosBarycentric(1);	vertices[p3].setPosBarycentric(2);

		vertices[p1].addVertex(p2);	vertices[p1].addVertex(p3);
		vertices[p2].addVertex(p1);	vertices[p2].addVertex(p3);
		vertices[p3].addVertex(p1);	vertices[p3].addVertex(p2);
	}

	in.close();

}

void Mesh :: insertVertex(int pos, double x, double y, double z){
	vertices[pos].setX(x);	vertices[pos].setY(y);	vertices[pos].setZ(z);
	vertices[pos].setIndex(pos);
}

void Mesh :: insertFace(int pos, int p1, int p2, int p3){
	faces[pos].addVertex(p1);	faces[pos].addVertex(p2); 	faces[pos].addVertex(p3);

	vertices[p1].addFace(pos);			vertices[p2].addFace(pos);			vertices[p3].addFace(pos);
	vertices[p1].setNumFace(pos);		vertices[p2].setNumFace(pos);		vertices[p3].setNumFace(pos);
	vertices[p1].setPosBarycentric(0);	vertices[p2].setPosBarycentric(1);	vertices[p3].setPosBarycentric(2);
	vertices[p1].addVertex(p2);	vertices[p1].addVertex(p3);
	vertices[p2].addVertex(p1);	vertices[p2].addVertex(p3);
	vertices[p3].addVertex(p1);	vertices[p3].addVertex(p2);
}

void Mesh :: getPatch(int seed, std::vector<int> indices, double radius, Vertex center, Mesh* patch, std::set<int>& vertReturned){
	//set<int> vertReturned;
	std::set<int> faceReturned;

	//std::cout << "Before the patch extraction" << std::endl;
	vertices[seed].getPatch(vertices, indices, vertReturned, faceReturned, radius, center);
	//std::cout << "After the patch extraction" << std::endl;

	//Chequear que todos los vertices contenidos en faceReturned esten en vertReturned
	std::set<int>::iterator it;
	for(it = faceReturned.begin(); it!=faceReturned.end(); it++){
		int faceInd = *it;
		int ind1 = faces[faceInd].getVertex(0);
		int ind2 = faces[faceInd].getVertex(1);
		int ind3 = faces[faceInd].getVertex(2);

		vertReturned.insert(ind1);
		vertReturned.insert(ind2);
		vertReturned.insert(ind3);
	}

	patch->setNumberVertices(vertReturned.size());
	patch->setNumberFaces(faceReturned.size());

	std::map<int, int> mapping;
	it = vertReturned.begin();

	int i = 0;
	while(it!=vertReturned.end()){
		int ind = *it;
		mapping.insert( std::pair<int, int> (ind, i) );
		patch->insertVertex(i, vertices[ind].x(), vertices[ind].y(), vertices[ind].z());
		it++;
		i++;
	}

	it = faceReturned.begin();
	i = 0;
	while(it!=faceReturned.end()){
		int faceInd = *it;
		int ind1 = faces[faceInd].getVertex(0);
		int ind2 = faces[faceInd].getVertex(1);
		int ind3 = faces[faceInd].getVertex(2);

		patch->insertFace(i, mapping[ind1], mapping[ind2], mapping[ind3]);
		i++;
		it++;
	}



	//cout << "Size:" << vertReturned.size() << " - " << faceReturned.size() << endl;

}

void Mesh::getSpatialPatch(Mesh* patch, Vertex center, double radius){
	std::set<int> vertReturned;
	std::set<int> faceReturned;

	for(int i = 0; i < numFaces; i++){
		std::vector<int> vert = faces[i].getVertices();

		double x1 = vertices[vert[0]].x();
		double y1 = vertices[vert[0]].y();
		double z1 = vertices[vert[0]].z();
		double dist1 = sqrt((x1 - center.x())*(x1 - center.x()) + (y1 - center.y())*(y1 - center.y()) + (z1 - center.z())*(z1 - center.z()));

		double x2 = vertices[vert[1]].x();
		double y2 = vertices[vert[1]].y();
		double z2 = vertices[vert[1]].z();
		double dist2 = sqrt((x2 - center.x())*(x2 - center.x()) + (y2 - center.y())*(y2 - center.y()) + (z2 - center.z())*(z2 - center.z()));

		double x3 = vertices[vert[2]].x();
		double y3 = vertices[vert[2]].y();
		double z3 = vertices[vert[2]].z();
		double dist3 = sqrt((x3 - center.x())*(x3 - center.x()) + (y3 - center.y())*(y3 - center.y()) + (z3 - center.z())*(z3 - center.z()));

		if(dist1 < radius && dist2 < radius && dist3 < radius){
			vertReturned.insert(vert[0]);
			vertReturned.insert(vert[1]);
			vertReturned.insert(vert[2]);
			faceReturned.insert(i);
		}
	}

	std::set<int>::iterator it;
	for(it = faceReturned.begin(); it!=faceReturned.end(); it++){
		int faceInd = *it;
		int ind1 = faces[faceInd].getVertex(0);
		int ind2 = faces[faceInd].getVertex(1);
		int ind3 = faces[faceInd].getVertex(2);

		vertReturned.insert(ind1);
		vertReturned.insert(ind2);
		vertReturned.insert(ind3);
	}

	patch->setNumberVertices(vertReturned.size());
	patch->setNumberFaces(faceReturned.size());

	std::map<int, int> mapping;
	it = vertReturned.begin();

	int i = 0;
	while(it!=vertReturned.end()){
		int ind = *it;
		mapping.insert( std::pair<int, int> (ind, i) );
		patch->insertVertex(i, vertices[ind].x(), vertices[ind].y(), vertices[ind].z());
		it++;
		i++;
	}

	it = faceReturned.begin();
	i = 0;
	while(it!=faceReturned.end()){
		int faceInd = *it;
		int ind1 = faces[faceInd].getVertex(0);
		int ind2 = faces[faceInd].getVertex(1);
		int ind3 = faces[faceInd].getVertex(2);

		patch->insertFace(i, mapping[ind1], mapping[ind2], mapping[ind3]);
		i++;
		it++;
	}
}

double Mesh::getArea(){
	double area = 0.0;

	for(int i = 0; i < numFaces; i++){
		std::vector<int> indices = faces[i].getVertices();
		double x1 = vertices[indices[0]].x();
		double y1 = vertices[indices[0]].y();
		double z1 = vertices[indices[0]].z();

		double x2 = vertices[indices[1]].x();
		double y2 = vertices[indices[1]].y();
		double z2 = vertices[indices[1]].z();

		double x3 = vertices[indices[2]].x();
		double y3 = vertices[indices[2]].y();
		double z3 = vertices[indices[2]].z();

		double det1 = x1*y2 + x2*y3 + x3*y1 - x3*y2 - x2*y1 - x1*y3;
		double det2 = y1*z2 + y2*z3 + y3*z1 - y3*z2 - y2*z1 - y1*z3;
		double det3 = z1*x2 + z2*x3 + z3*x1 - z3*x2 - z2*x1 - z1*x3;

		area = area + 0.5*sqrt(det1*det1 + det2*det2 + det3*det3);
	}

	return area;
}

int binarySearch(double* accum, int length, double value){
	int ini = 0;
	int fin = length - 1;

	while(ini < fin){
		int mid = (ini + fin)/2;
		if(accum[mid] >= value)
			fin = mid;
		else
			ini = mid + 1;
	}

	return ini;
}

void Mesh::samplePoints(int numPoints, std::vector<Vertex>& vertRet){
	double accum[numFaces];
	double x1, y1, z1;
	double x2, y2, z2;
	double x3, y3, z3;
	double det1, det2,det3;
	double areaFace;
	double x, y, z;

	for (int i = 0; i < numFaces; i++){
		std::vector<int> indices = faces[i].getVertices();
		x1 = vertices[indices[0]].x();
		y1 = vertices[indices[0]].y();
		z1 = vertices[indices[0]].z();

		x2 = vertices[indices[1]].x();
		y2 = vertices[indices[1]].y();
		z2 = vertices[indices[1]].z();

		x3 = vertices[indices[2]].x();
		y3 = vertices[indices[2]].y();
		z3 = vertices[indices[2]].z();

		det1 = x1*y2 + x2*y3 + x3*y1 - x3*y2 - x2*y1 - x1*y3;
		det2 = y1*z2 + y2*z3 + y3*z1 - y3*z2 - y2*z1 - y1*z3;
		det3 = z1*x2 + z2*x3 + z3*x1 - z3*x2 - z2*x1 - z1*x3;

		areaFace = 0.5*sqrt(det1*det1 + det2*det2 + det3*det3);

		if(i == 0)
			accum[i] = areaFace;
		else
			accum[i] = accum[i-1] + areaFace;
	}

	double totalArea = accum[numFaces - 1];

	int np = 0;
	vertRet.clear();
	double r1, r2;

	while(np < numPoints){
		double randomValue = (double(rand())/RAND_MAX)*totalArea;
		int indexFace = binarySearch(accum, numFaces, randomValue);

		std::vector<int> indices = faces[indexFace].getVertices();

		x1 = vertices[indices[0]].x();
		y1 = vertices[indices[0]].y();
		z1 = vertices[indices[0]].z();

		x2 = vertices[indices[1]].x();
		y2 = vertices[indices[1]].y();
		z2 = vertices[indices[1]].z();

		x3 = vertices[indices[2]].x();
		y3 = vertices[indices[2]].y();
		z3 = vertices[indices[2]].z();

		r1 = double(rand())/RAND_MAX;
		r2 = double(rand())/RAND_MAX;

		x = (1.0 - sqrt(r1)) * x1 + sqrt(r1)*(1.0 - r2) * x2 + sqrt(r1) * r2 * x3;
		y = (1.0 - sqrt(r1)) * y1 + sqrt(r1)*(1.0 - r2) * y2 + sqrt(r1) * r2 * y3;
		z = (1.0 - sqrt(r1)) * z1 + sqrt(r1)*(1.0 - r2) * z2 + sqrt(r1) * r2 * z3;

		vertRet.push_back(Vertex(x, y, z));
		np++;
	}
}

void Mesh::sampleSurfacePoints(int numPoints, std::vector<int>& vertRet){

	double accum[numFaces];
	double x1, y1, z1;
	double x2, y2, z2;
	double x3, y3, z3;
	double det1, det2,det3;
	double areaFace;
	double x, y, z;

	for (int i = 0; i < numFaces; i++){
		std::vector<int> indices = faces[i].getVertices();
		x1 = vertices[indices[0]].x();
		y1 = vertices[indices[0]].y();
		z1 = vertices[indices[0]].z();

		x2 = vertices[indices[1]].x();
		y2 = vertices[indices[1]].y();
		z2 = vertices[indices[1]].z();

		x3 = vertices[indices[2]].x();
		y3 = vertices[indices[2]].y();
		z3 = vertices[indices[2]].z();

		det1 = x1*y2 + x2*y3 + x3*y1 - x3*y2 - x2*y1 - x1*y3;
		det2 = y1*z2 + y2*z3 + y3*z1 - y3*z2 - y2*z1 - y1*z3;
		det3 = z1*x2 + z2*x3 + z3*x1 - z3*x2 - z2*x1 - z1*x3;

		areaFace = 0.5*sqrt(det1*det1 + det2*det2 + det3*det3);

		if(i == 0)
			accum[i] = areaFace;
		else
			accum[i] = accum[i-1] + areaFace;
	}

	double totalArea = accum[numFaces - 1];

	int np = 0;
	vertRet.clear();
	double r1, r2;
	double d1, d2, d3, minDis;
	int ind;

	while(np < numPoints){
		double randomValue = (double(rand())/RAND_MAX)*totalArea;
		int indexFace = binarySearch(accum, numFaces, randomValue);

		std::vector<int> indices = faces[indexFace].getVertices();

		x1 = vertices[indices[0]].x();
		y1 = vertices[indices[0]].y();
		z1 = vertices[indices[0]].z();

		x2 = vertices[indices[1]].x();
		y2 = vertices[indices[1]].y();
		z2 = vertices[indices[1]].z();

		x3 = vertices[indices[2]].x();
		y3 = vertices[indices[2]].y();
		z3 = vertices[indices[2]].z();

		r1 = double(rand())/RAND_MAX;
		r2 = double(rand())/RAND_MAX;

		x = (1.0 - sqrt(r1)) * x1 + sqrt(r1)*(1.0 - r2) * x2 + sqrt(r1) * r2 * x3;
		y = (1.0 - sqrt(r1)) * y1 + sqrt(r1)*(1.0 - r2) * y2 + sqrt(r1) * r2 * y3;
		z = (1.0 - sqrt(r1)) * z1 + sqrt(r1)*(1.0 - r2) * z2 + sqrt(r1) * r2 * z3;

		d1 = (x - x1)*(x - x1) + (y - y1)*(y - y1) + (z - z1)*(z - z1);
		d2 = (x - x2)*(x - x2) + (y - y2)*(y - y2) + (z - z2)*(z - z2);
		d3 = (x - x3)*(x - x3) + (y - y3)*(y - y3) + (z - z3)*(z - z3);

		minDis = d1;	ind = 0;

		if(d2 < minDis){
			minDis = d2;	ind = 1;
		}

		if(d3 < minDis){
			minDis = d3;	ind = 2;
		}

		vertRet.push_back(indices[ind]);
		np++;
	}
}
std::ostream& operator<<(std::ostream& os, Mesh& obj){
         os<<"OFF"<<std::endl;
         os<<obj.getNumberVertices()<<" "<<obj.getNumFaces()<<" "<<0<<std::endl;
         for(int i = 0; i<obj.getNumberVertices(); i++){
             os<<obj.vertices[i].getX()<<" "<<obj.vertices[i].getY()<<" "<<obj.vertices[i].getZ()<<std::endl;
         }
		 for(int i = 0; i < obj.getNumFaces(); i++){
				os<<3<<" ";
				std::vector<int> vert = obj.faces[i].getVertices();
				for(int j = 0; j < (vert.size() - 1); j++){
					os<<vert[j]<<" ";
				}
				os<<vert[vert.size()-1]<<std::endl;
		 }
		 return os;
 }

}
