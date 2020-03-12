#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cmath>
#include "Mesh.h"
#include "Clock.h"
#include "util.h"
#include "Properties.h"
#include "HarrisDetector.h"

using namespace std;

string getOutputPath(string filename){
  string outputPath(filename);
  size_t pos;
  string directory = "";

  if((pos = filename.find_last_of('/')) != string::npos){
	directory = filename.substr(0, pos + 1);
    outputPath = filename.substr(pos + 1);
  }

  pos = outputPath.find_last_of('.');

  outputPath = outputPath.substr(0, pos);

  outputPath = directory + outputPath + ".int";

  return outputPath;
}

int main(int argc, char *argv[])
{
    //if(argc < 3){
    //	cout<<"Usage: ./Harris3D_demo off-file options-file"<<endl;
    //	exit(-1);
    //}

	string offFilename = argv[1];

	string optFilename;
	if(argc == 3)
		optFilename = argv[2];

    cout<<"File:"<<offFilename;

    string outfilename = getOutputPath(offFilename);

    ifstream inp;
    inp.open(outfilename.c_str(), ifstream::in);
    inp.close();

    if(inp.fail()){
		inp.clear(ios::failbit);


		int i = 0;
		Util::Clock r;
		r.tick();
		Harris3D::Mesh mesh(argv[1]);
		r.tick();
		cout<<"->Loaded";
		cout<<"->Loading time:"<<r.getTime()<<"s."<<endl;


		Util::Properties prop;
		if(argc == 3)
			prop.load(optFilename);

		Harris3D::HarrisDetector hd(&mesh, &prop);

		vector<int> interestPoints;
		interestPoints.clear();
		Harris3D::Vertex* vertices = mesh.getVertices();

		Util::Clock r1;
		r1.tick();
		cout<<"->Interest points"<<endl;
		hd.detectInterestPoints(interestPoints);
		r1.tick();
		cout<<"->Calculation time:"<<r1.getTime()<<"s."<<endl;

		cout<<"->Saving"<<endl;
		ofstream out(outfilename.c_str());
		//for(int i = 0; i < interestPoints.size(); i++)
		//	cout << interestPoints[i] << endl;
		//cout << "Interest points:" <<interestPoints.size() << endl;

		out<<interestPoints.size()<<endl;
		for(register int i = 0; i < interestPoints.size(); i++) {
			out<<interestPoints[i]<<endl;
			//int index = interestPoints[i].getIndice();
			//out<<vertices[index].getNumFace()+1<<" ";
			//if(vertices[index].getPosBarycentric()==0){
			//	out<<"1.0000 0.0000 0.0000"<<endl;
			//}else if(vertices[index].getPosBarycentric()==1){
			//	out<<"0.0000 1.0000 0.0000"<<endl;
			//}else if(vertices[index].getPosBarycentric()==2){
			//	out<<"0.0000 0.0000 1.0000"<<endl;
			//}
		}
		out.close();
		interestPoints.clear();

		cout<<"File saved."<<endl;
	}else{
		cout << "Interest points already exist - Skipped" << endl;
    }

	return EXIT_SUCCESS;
}
