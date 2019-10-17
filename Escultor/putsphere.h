#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"

/**
 * @brief The PutSphere class é a classe filho
 * que tem a implementação do método
 * virtual draw, onde ativará todos
 * os voxels que satisfazem a equação
 * da esfera e atribuirá a cor para o mesmo.
 */

class PutSphere : public FiguraGeometrica
{
private:
    int xcenter;
    int ycenter;
    int zcenter;
    int radius;
public:
    PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
    void draw(Sculptor &t);
};

#endif // PUTSPHERE_H
