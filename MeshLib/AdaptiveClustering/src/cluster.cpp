#include <cfloat>
#include "cluster.h"
#include "PointND.h"

namespace AdaptiveClustering{

void Cluster :: computeCentroid(){
	int numPoints = points.size();

	centroid.descriptor.clear();
	centroid.descriptor.resize(dim);

	for(int i = 0; i < numPoints; i++){
		for(int j = 0; j < dim; j++){
			centroid.descriptor[j] += points[i].descriptor[j];
		}
	}

	for(int j = 0; j < dim; j++){
		centroid.descriptor[j] /= numPoints;
	}
}

void Cluster :: computeMedoid(double* distances, int N){

	int numPoints = members.size();
	double factor = DBL_MAX;
	int pos = -1;

	for(int i = 0; i < numPoints; i++){
		double sum = 0.0;
		for(int j = 0; j < numPoints; j++){
			sum += distances[members[i]*N + members[j]];
		}

		if(sum < factor){
			factor = sum;
			pos = i;
		}
	}

	indexCentroid = members[pos];
}

void Cluster :: removePoints(vector< PointND >& p){
	for(int i = 0; i < points.size(); i++){
		p.push_back(points[i]);
	}
}

void Cluster :: removeIndex(vector<int>& marks){
	for(int i = 0; i < members.size(); i++){
		marks[members[i]] = 0;
	}
}

int Cluster :: getCloser(){

	int index = -1;
	double mindist = DBL_MAX;

	PointND cen = getCentroid();

	for(int i = 0; i < points.size(); i++){
		double dist = computeDistance(points[i], cen);
		if(dist < mindist){
			mindist = dist;
			index = points[i].index;
		}
	}

	return index;
}

double Cluster::computeDistance(PointND a, PointND b){
	double sum = 0.0;

	for(int i = 0; i < a.descriptor.size(); i++){
		sum += (a.descriptor[i] - b.descriptor[i])*(a.descriptor[i] - b.descriptor[i]);
	}

	return sqrt(sum);
}


}
