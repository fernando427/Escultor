#include "cutsphere.h"
#include "math.h"
#include <iostream>

CutSphere::CutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->radius = radius;
}

void CutSphere::draw(Sculptor &t){
    for(int i = (xcenter-radius); i <= (xcenter+radius); i++){
        for(int j = (ycenter-radius); j <= (ycenter+radius); j++){
            for(int k = (zcenter-radius); k <= (zcenter+radius); k++){
                if(((float)pow((i - xcenter),2) + (float)pow((j - ycenter),2) + (float)pow((k - zcenter),2)) <= (float)pow(radius,2)){
                    t.cutVoxel(i,j,k);
                } else {
                    return;
                }
            }
        }
    }
}
