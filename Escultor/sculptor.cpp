#include "sculptor.h"
#include "math.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    this->nx = _nx;
    this->ny = _ny;
    this->nz = _nz;

    v = new Voxel**[nx];
    for(int i=0; i<nx; i++){
        v[i] = new Voxel*[ny];
        for(int j=0; j<ny; j++){
            v[i][j] = new Voxel[nz];
        }
    }
}

Sculptor::~Sculptor()
{
    for(int i = 0;i < nx; ++i){
        for(int j = 0;j < ny; j++){
            delete []v[i][j];
        }
    }

    for(int i = 0;i < nx; i++){
        delete []v[i];
    }

    delete []v;
}


void Sculptor::setColor(float r, float g, float b, float alpha){
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = alpha;
}

void Sculptor::putVoxel(int x, int y, int z){
    if ((x > nx) || (y > ny) || (z > nz)){
        return;
    }
    if ((x < 0) || (y < 0) || (z < 0)){
        return;
    }

    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
}

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
}

void Sculptor::writeOFF(const char *filename){
    ofstream arquivo;
    arquivo.open(filename);

    if(arquivo.is_open() == true){
        cout << "Iniciando" << endl;
    }

    arquivo << "OFF" << endl;

    int numVox = 0;
    int numFace = 0;

    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if (v[i][j][k].isOn == true){
                    numVox++;
                }
            }
        }
    }

    arquivo << 8*numVox << " " << 6*numVox << " " << 0 << endl;

    for(int k = 0; k < nz; k++){
        for(int j = 0; j < ny; j++){
            for (int i = 0; i < nx; i++) {
                if(v[i][j][k].isOn == true){
                    arquivo<<-0.5+i<<" "<<0.5+j<<" "<<-0.5+k<<endl;
                    arquivo<<-0.5+i<<" "<<-0.5+j<<" "<<-0.5+k<<endl;
                    arquivo<<0.5+i<<" "<<-0.5+j<<" "<<-0.5+k<<endl;
                    arquivo<<0.5+i<<" "<<0.5+j<<" "<<-0.5+k<<endl;
                    arquivo<<-0.5+i<<" "<<0.5+j<<" "<<0.5+k<<endl;
                    arquivo<<-0.5+i<<" "<<-0.5+j<<" "<<0.5+k<<endl;
                    arquivo<<0.5+i<<" "<<-0.5+j<<" "<<0.5+k<<endl;
                    arquivo<<0.5+i<<" "<<0.5+j<<" "<<0.5+k<<endl;
                }
            }
        }
    }

    for(int k = 0; k < nz; k++){
        for(int j = 0; j < ny; j++){
            for (int i = 0; i < nx; i++) {
                if(v[i][j][k].isOn == true){
                     arquivo<<"4 "<<0+numFace*8<<" "<<3+numFace*8<<" "<<2+numFace*8<<" "<<1+numFace*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                            <<"4 "<<4+numFace*8<<" "<<5+numFace*8<<" "<<6+numFace*8<<" "<<7+numFace*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                            <<"4 "<<0+numFace*8<<" "<<1+numFace*8<<" "<<5+numFace*8<<" "<<4+numFace*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                            <<"4 "<<0+numFace*8<<" "<<4+numFace*8<<" "<<7+numFace*8<<" "<<3+numFace*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                            <<"4 "<<3+numFace*8<<" "<<7+numFace*8<<" "<<6+numFace*8<<" "<<2+numFace*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl
                            <<"4 "<<1+numFace*8<<" "<<2+numFace*8<<" "<<6+numFace*8<<" "<<5+numFace*8<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    numFace++;
                }
            }
        }
    }

    arquivo.close();
}























