#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"

/**
 * @brief The CutSphere class é a classe filho
 * que tem a implementação do método
 * virtual draw, onde desativará todos
 * os voxels que satisfazem a equação
 * da esfera.
 */

class CutSphere : public FiguraGeometrica
{
private:
    int xcenter;
    int ycenter;
    int zcenter;
    int radius;
public:
    CutSphere(int xcenter, int ycenter, int zcenter, int radius);
    void draw(Sculptor &t);
};

#endif // CUTSPHERE_H
