#ifndef GUERRERO_HPP
#define GUERRERO_HPP

#include "Personaje.hpp"

class Guerrero : public Personaje {
private:
    int fuerza;

public:
    Guerrero();
    Guerrero(int v, int a, int n, int f);

    int getFuerza();
    void setFuerza(int f);

    int calculaAtaque(Personaje& objetivo) override;
    void recibeAtaque(int puntos) override;
    void imprimir() override;
};

#endif
