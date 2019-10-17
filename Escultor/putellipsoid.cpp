#include "putellipsoid.h"
#include "math.h"
#include <iostream>

PutEllipsoid::PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a)
{
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->rx = rx;
    this->ry = ry;
    this->rz = rz;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void PutEllipsoid::draw(Sculptor &t){
    t.setColor(r, g, b, a);
    for(int i = (xcenter-rx); i <= (xcenter+rx); i++){
        for(int j = (ycenter-ry); j <= (ycenter+ry); j++){
            for(int k = (zcenter-rz); k <= (zcenter+rz); k++){
                if((((float)pow((i - xcenter),2)/(float)(pow(rx,2))) + (((float)pow((j - ycenter),2))/(float)(pow(ry,2))) + (((float)pow((k - zcenter),2))/(float)(pow(rz,2)))) <= 1.0){
                    t.putVoxel(i,j,k);
                } else {
                    return;
                }
            }
        }
    }
}
