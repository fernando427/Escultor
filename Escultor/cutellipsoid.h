#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "figurageometrica.h"

/**
 * @brief The CutEllipsoid class é a classe filho
 * que tem a implementação do método
 * virtual draw, onde desativará todos
 * os voxels que satisfazem a equação
 * da elipsóide.
 */

class CutEllipsoid : public FiguraGeometrica
{
private:
    int xcenter;
    int ycenter;
    int zcenter;
    int rx;
    int ry;
    int rz;
public:
    CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void draw(Sculptor &t);
};

#endif // CUTELLIPSOID_H
