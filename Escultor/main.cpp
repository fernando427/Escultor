#include <iostream>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "sculptor.h"
#include <cstring>
#include "math.h"
#include "figurageometrica.h"
#include "putbox.h"
#include "cutbox.h"
#include "cutvoxel.h"
#include "putvoxel.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"
#include "vector"
#include <string>
#include "sstream"

using namespace std;

int main()
{
    Sculptor *s;
    string String, comando;
    vector<FiguraGeometrica*> f;
    ifstream fileoff;
    fileoff.open("C:/Users/PICHAU/Desktop/testinho.txt");

    if(fileoff.is_open() == true){
        cout << "Ok" << endl;
    }

    stringstream ss;

    while (fileoff.good()) {
        getline(fileoff, String);
        if(fileoff.good()){
            stringstream ss(String);
            ss >> comando;
            cout << comando << endl;
            if(comando.compare("dim") == 0){
                int nx, ny, nz;
                ss >> nx >> ny >> nz;
                s = new Sculptor(nx, ny, nz);
            }

            else if (comando.compare("putvoxel")==0) {
                int pos[3];
                float color[4];
                ss >> pos[0] >> pos[1] >> pos[2];
                ss >> color[0] >> color[1];
                ss >> color[2] >> color[3];
                f.push_back(new PutVoxel(pos[0], pos[1], pos[2], color[0], color[1], color[2], color[3]));
            }

            else if (comando.compare("cutvoxel")==0) {
                int pos[3];
                ss >> pos[0] >> pos[1] >> pos[2];
                f.push_back(new CutVoxel(pos[0], pos[1], pos[2]));
            }

            else if (comando.compare("putbox")==0) {
                int pos[6];
                float color[4];
                ss >> pos[0] >> pos[1] >> pos[2] >> pos[3] >> pos[4] >> pos[5];
                ss >> color[0] >> color[1];
                ss >> color[2] >> color[3];
                f.push_back(new PutBox(pos[0], pos[1], pos[2], pos[3], pos[4], pos[5], color[0], color[1], color[2], color[3]));
            }

            else if (comando.compare("cutbox")==0) {
                int pos[6];
                ss >> pos[0] >> pos[1] >> pos[2] >> pos[3] >> pos[4] >> pos[5];
                f.push_back(new CutBox(pos[0], pos[1], pos[2], pos[3], pos[4], pos[5]));
            }

            else if (comando.compare("putsphere")==0) {
                int pos[4];
                float color[4];
                ss >> pos[0] >> pos[1] >> pos[2] >> pos[3];
                ss >> color[0] >> color[1];
                ss >> color[2] >> color[3];
                f.push_back(new PutSphere(pos[0], pos[1], pos[2], pos[3], color[0], color[1], color[2], color[3]));
            }

            else if (comando.compare("cutsphere")==0) {
                int pos[4];
                ss >> pos[0] >> pos[1] >> pos[2] >> pos[3];
                f.push_back(new CutSphere(pos[0], pos[1], pos[2], pos[3]));
            }

            else if (comando.compare("putellipsoid")==0) {
                int pos[6];
                float color[4];
                ss >> pos[0] >> pos[1] >> pos[2] >> pos[3] >> pos[4] >> pos[5];
                ss >> color[0] >> color[1];
                ss >> color[2] >> color[3];
                f.push_back(new PutEllipsoid(pos[0], pos[1], pos[2], pos[3], pos[4], pos[5], color[0], color[1], color[2], color[3]));
            }

            else if (comando.compare("cutellipsoid")==0) {
                int pos[6];
                ss >> pos[0] >> pos[1] >> pos[2] >> pos[3] >> pos[4] >> pos[5];
                f.push_back(new CutEllipsoid(pos[0], pos[1], pos[2], pos[3], pos[4], pos[5]));
            }
        }
    }

    for (unsigned i=0; i<f.size(); i++) {
        f[i]->draw(*s);
    }
    cout << "\n";

    for (unsigned i=0; i<f.size(); i++) {
        delete f[i];
    }

    s->writeOFF("C:/Users/PICHAU/Desktop/elipsoide.off");

    fileoff.close();

    return 0;
}
