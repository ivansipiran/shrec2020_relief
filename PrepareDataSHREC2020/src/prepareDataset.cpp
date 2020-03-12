#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "Mesh.h"

using namespace std;
using namespace MeshLib;

string getOutputPath(string filename, int idx){
    string outputPath = filename;
    size_t pos;

    string directory = "";

    if((pos=filename.find_last_of('/'))!= string::npos){
        directory = filename.substr(0, pos+1);
        outputPath = filename.substr(pos+1);
    }

    pos = outputPath.find_last_of('.');
    outputPath = outputPath.substr(0, pos);

    outputPath = directory + outputPath + "_" + to_string(idx) + ".xyz";
    return outputPath;
}

int main(int argc, char *argv[]){
    string filename(argv[1]);

    // Leemos la malla
    Mesh mesh(filename.c_str());
    
    //Sampleamos puntos en la superficie
    vector<int> indices;
    mesh.sampleSurfacePoints(200, indices);

    //Para cada punto, generamos una malla y sampleamos puntos en cada malla
    int cont = 0;
    for (auto index: indices){
        vector<int> dumb;
        set<int> vdumb;

        Mesh* patch = new Mesh();
        mesh.getPatch(index, dumb, mesh.getDiagonal()*0.1, mesh.getVertices()[index], patch, vdumb);

        vector<Vertex> vertices;
        patch->samplePoints(3000, vertices);

        string name = getOutputPath(filename, cont);

        ofstream output(name.c_str());

        for(auto v : vertices){
            output << v.x() << " " << v.y() << " " << v.z() << endl;
        }

        output.close();

        delete patch;
        cont++;
    }

    return EXIT_SUCCESS;

}