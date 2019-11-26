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

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for (int i = x0; i < x1; i++){
        for (int j = y0; j < y1; j++){
            for (int k = z0; k < z1; k++){
                putVoxel(i, j, k);
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for (int i = x0; i < x1; i++){
        for (int j = y0; j < y1; j++){
            for (int k = z0; k < z1; k++){
                cutVoxel(i, j, k);
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int i = (xcenter-radius); i < (xcenter+radius); i++){
        for(int j = (ycenter-radius); j < (ycenter+radius); j++){
            for(int k = (zcenter-radius); k < (zcenter+radius); k++){
                if (((float)pow((i-xcenter),2)/(float)(pow(radius,2))) + (((float)pow((j-ycenter),2))/(float)(pow(radius,2))) + (((float)pow((k-zcenter),2))/(float)(pow(radius,2))) <= 1.0){
                    putVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int i = (xcenter-radius); i < (xcenter+radius); i++){
        for(int j = (ycenter-radius); j < (ycenter+radius); j++){
            for(int k = (zcenter-radius); k < (zcenter+radius); k++){
                if (((float)pow((i-xcenter),2)/(float)(pow(radius,2))) + (((float)pow((j-ycenter),2))/(float)(pow(radius,2))) + (((float)pow((k-zcenter),2))/(float)(pow(radius,2))) <= 1.0){
                    cutVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int i = (xcenter-rx); i < (xcenter+rx); i++){
        for(int j = (ycenter-ry); j < (ycenter+ry); j++){
            for(int k = (zcenter - rz); k < (zcenter + rz); k++){
                if (((float)pow((i-xcenter),2)/(float)(pow(rx,2))) + (((float)pow((j-ycenter),2))/(float)(pow(ry,2))) + (((float)pow((k-zcenter),2))/(float)(pow(rz,2))) <= 1.0)
                {
                   putVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int i = (xcenter-rx); i < (xcenter+rx); i++){
        for(int j = (ycenter-ry); j < (ycenter+ry); j++){
            for(int k = (zcenter - rz); k < (zcenter + rz); k++){
                if (((float)pow((i-xcenter),2)/(float)(pow(rx,2))) + (((float)pow((j-ycenter),2))/(float)(pow(ry,2))) + (((float)pow((k-zcenter),2))/(float)(pow(rz,2))) <= 1.0)
                {
                   cutVoxel(i, j, k);
                }
            }
        }
    }
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
