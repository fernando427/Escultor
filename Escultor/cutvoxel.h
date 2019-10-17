#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "figurageometrica.h"

/**
 * @brief The CutVoxel class é a classe filho
 * que tem a implementação do método
 * virtual draw, onde desativará um
 * voxel na tela.
 */

class CutVoxel : public FiguraGeometrica
{
private:
    int x;
    int y;
    int z;
public:
    CutVoxel(int x, int y, int z);
    void draw(Sculptor &t);
};

#endif // CUTVOXEL_H
