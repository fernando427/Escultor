#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "sculptor.h"

/**
 * @brief The FiguraGeometrica class
 * Classe abstrata pai para todas as
 * outras classes seguintes, com o
 * intuito de gerar o interpretador
 * no fim das contas.
 */

class FiguraGeometrica
{
protected:
    float r;
    float g;
    float b;
    float a;
public:
    /**
     * @brief FiguraGeometrica é o
     * construtor da classe.
     */
    FiguraGeometrica();
    /**
     * @brief draw método virtual
     * no qual terá implementação
     * nas classes filhos.
     */
    virtual void draw(Sculptor &t) = 0;
    /**
     * @brief ~FiguraGeometrica é o destrutor
     * onde deve ser obrigatoriamente implementado
     * no qual servirá de base para outras classes.
     */
    virtual ~FiguraGeometrica();
};

#endif // FIGURAGEOMETRICA_H
