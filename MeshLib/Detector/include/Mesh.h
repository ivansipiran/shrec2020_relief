#ifndef __MESH_H_
#define __MESH_H_

#include "harris_global.h"
#include "Vertex.h"
#include "Face.h"
#include <vector>

namespace MeshLib{

class HARRIS_API Mesh{

      //Topological information
      Vertex* vertices;
      Face* faces;

      int numVertices;
      int numFaces;

      float** D;

      //BBox Information
      double xmin, xmax, ymin, ymax, zmin, zmax;
      double diag;


  public:
      void cleanMesh();

      Mesh();
      Mesh(const char* nombreArchivo);
      ~Mesh();

      void loadFromFile(const char* filename);

      friend HARRIS_API std::ostream& operator<<(std::ostream& os, Mesh &obj);
      inline Vertex* getVertices(){return vertices;}
      inline Face* getFaces(){return faces;}

      inline  int getNumberVertices(){return numVertices;}
      inline  int getNumFaces(){return numFaces;}

      inline  double getDiagonal(){return diag;}
      inline  double getArea();
      void getPatch(int seed, std::vector<int> indices, double radius, Vertex center, Mesh* patch, std::set<int>& vertReturned);
      void getSpatialPatch(Mesh* patch, Vertex center, double radius);

      void setNumberVertices(int nv);
      void setNumberFaces(int nf);

      void insertVertex(int pos, double x, double y, double z);
      void insertFace(int pos, int p1, int p2, int p3);

      void samplePoints(int numPoints, std::vector<Vertex>& vertRet);
      void sampleSurfacePoints(int numPoints, std::vector<int>& vertRet);

};

}
#endif
