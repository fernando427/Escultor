#ifndef CUTBOX_H
#define CUTBOX_H
#include "figurageometrica.h"

/**
 * @brief The CutBox class é a classe filho
 * que tem a implementação do método
 * virtual draw, onde desativará todos
 * os voxels em um intervalo de
 * [x0,x1],[y0,y1],[z0,z1].
 */

class CutBox : public FiguraGeometrica
{
private:
    int x0;
    int x1;
    int y0;
    int y1;
    int z0;
    int z1;
public:
    CutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    void draw(Sculptor &t);
};

#endif // CUTBOX_H
