#ifndef MAGO_HPP
#define MAGO_HPP


#include "Personaje.hpp"

class Mago : public Personaje {
private:
    int mana;

public:
    Mago();
    Mago(int v, int a, int n, int m);

    int getMana();
    void setMana(int m);

    int calculaAtaque(Personaje& objetivo) override;
    void recibeAtaque(int puntos) override;
    void atacar(Personaje& objetivo) override;
    void imprimir() override; };

#endif
