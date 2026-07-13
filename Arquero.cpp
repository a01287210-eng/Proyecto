#ifndef ARQUERO_HPP
#define ARQUERO_HPP

#include "Personaje.hpp"

class Arquero : public Personaje {
private:
    float precision;

public:
    Arquero();
    Arquero(int v, int a, int n, float p);

    float getPrecision();
    void setPrecision(float p);

    int calculaAtaque(Personaje& objetivo) override;
    void recibeAtaque(int puntos) override;
    void imprimir() override;
};

#endif
