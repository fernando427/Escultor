#ifndef PUTBOX_H
#define PUTBOX_H
#include "figurageometrica.h"

/**
 * @brief The PutBox class é a classe filho
 * que tem a implementação do método
 * virtual draw, onde ativará todos
 * os voxels em um intervalo de
 * [x0,x1],[y0,y1],[z0,z1] e
 * atribuirá a cor para o mesmo.
 */

class PutBox : public FiguraGeometrica
{
private:
    int x0;
    int x1;
    int y0;
    int y1;
    int z0;
    int z1;
public:
    PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a);
    void draw(Sculptor &t);
};

#endif // PUTBOX_H
