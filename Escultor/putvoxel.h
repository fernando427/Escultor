#ifndef PUTVOXEL_H
#define PUTVOXEL_H
#include "figurageometrica.h"

/**
 * @brief The PutVoxel class é a classe filho
 * que tem a implementação do método
 * virtual draw, onde ativará um
 * voxel na tela e atribuirá a
 * cor para o mesmo.
 */

class PutVoxel : public FiguraGeometrica
{
private:
    int x;
    int y;
    int z;
public:
    PutVoxel(int x, int y, int z, float r, float g, float b, float a);
    void draw(Sculptor &t);
};

#endif // PUTVOXEL_H
