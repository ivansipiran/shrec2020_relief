#ifndef __FACE_H_
#define __FACE_H_

#include "harris_global.h"
#include <vector>

namespace MeshLib{

class HARRIS_API Face{
 private:
     std::vector<int> vertices;
 public:
     Face();
     void addVertex(int vertex);
     std::vector<int>& getVertices();
     int getVertex(int pos);
     int index(int v);
};

}
#endif
