#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "figurageometrica.h"

/**
 * @brief The PutEllipsoid class é a classe filho
 * que tem a implementação do método
 * virtual draw, onde ativará todos
 * os voxels que satisfazem a equação
 * da elipsóide e atribuirá a cor para
 * o mesmo.
 */

class PutEllipsoid : public FiguraGeometrica
{
private:
    int xcenter;
    int ycenter;
    int zcenter;
    int rx;
    int ry;
    int rz;
public:
    PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);
    void draw(Sculptor &t);
};

#endif // PUTELLIPSOID_H
