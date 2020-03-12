#ifndef __VERTEX_H_
#define __VERTEX_H_

#include "harris_global.h"
#include "Face.h"
#include <iostream>
#include <vector>
#include <queue>
#include <set>

namespace MeshLib{

class Face;


class HARRIS_API Vertex{
 private:

      int index;
      bool mark;
      bool isInterest;
      std::vector<int> faces;
      std::set<int> adjacentVertices;

      int depth;
      double response;
      int numNeighbors;

      //For barycentric representation
      int numFace;
      int posBarycentric;

 public:
	double v[3];
      Vertex() {v[0] = v[1] = v[2] = 0; mark = false; depth = 0;isInterest = 0;}
      Vertex(double x1, double y1, double z1) {v[0] = x1; v[1] = y1; v[2] = z1;mark = false; depth = 0;isInterest = 0;}

      inline double x() const { return v[ 0 ]; }
      inline double y() const { return v[ 1 ]; }
      inline double z() const { return v[ 2 ]; }

      inline double& x() { return v[ 0 ]; }
      inline double& y() { return v[ 1 ]; }
      inline double& z() { return v[ 2 ]; }

      inline double getX() {return v[0];}
      inline double getY() {return v[1];}
      inline double getZ() {return v[2];}

      inline void setX(double x1) {v[0] = x1;}
      inline void setY(double y1) {v[1] = y1;}
      inline void setZ(double z1) {v[2] = z1;}

      inline bool operator==(const Vertex& p) const { return (x() == p.x()) && (y() == p.y()) && (z() == p.z()); }
      inline bool  operator!=(const Vertex& p) const { return ! (*this == p); }

      friend std::ostream& operator<<(std::ostream& out, Vertex& point);

      inline void setVertex(double x1, double y1, double z1){v[0] = x1; v[1] = y1; v[2] = z1;}
      inline void setIndex(int ind){index = ind;}
      inline int getIndex(){return index;}
      inline bool isMarked(){return mark;}
      inline void setMark(bool mark1){mark = mark1;}
      inline int getDepth(){ return depth;}
      inline void setDepth(int dep){ depth = dep;}
      inline double getResponse(){return response;}
      inline void setResponse(double resp){response = resp;}
      inline bool getInterest(){return isInterest;}

      void getNeighborhood(int rad, std::vector<Vertex*>& V, Vertex* vertices);
      int getRadius(Vertex* vertices, double radius, std::vector<Vertex*>& V);

      void addVertex(int vertex){ adjacentVertices.insert(vertex);}
      void addFace(int face){ faces.push_back(face); }
      void processMaximum(Vertex* vertices, int numRings);

      inline std::vector<int>& getFaces(){ return faces;}
      inline std::set<int>& getAdjacentVertices() { return adjacentVertices;}
      inline int getNumberAdjacentFaces(){return faces.size();}

      void getPatch(Vertex* vertices, std::vector<int> indices, std::set<int>& returned, std::set<int>& faceR, double radius, Vertex center);

      inline void setNumFace(int num){numFace = num;}
      inline int getNumFace(){return numFace;}

      inline void setPosBarycentric(int pos){posBarycentric = pos;}
      inline int getPosBarycentric(){return posBarycentric;}
	double distanceL2(Vertex* v1);
  };
}

#endif