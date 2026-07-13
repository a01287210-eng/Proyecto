#include <iostream>
#include "Mago.hpp"
using namespace std;

Mago::Mago() : Personaje() {
    mana = 100;
}

Mago::Mago(int v, int a, int n, int m) : Personaje(v, a, n) {
    mana = m;
}

int Mago::getMana() { return mana; }
void Mago::setMana(int m) { mana = m; }

int Mago::calculaAtaque(Personaje& objetivo) {
    int base = Personaje::calculaAtaque(objetivo);
    if (mana >= 20) {
        int tiro = rand() % 100;
        if (tiro < mana / 2) {
            base = base * 2;
            mana = mana - 20;
        }
    } else {
        base = base / 2;
    }
    return base;
}

void Mago::recibeAtaque(int puntos) {
    if (getNivel() >= 4 && mana > 80) {
        puntos = puntos / 3;
    } else if (getNivel() >= 3 && mana > 85) {
        puntos = puntos / 2;
    } else if (getNivel() <= 2 && mana >= 100) {
        puntos = puntos * 3 / 4;
    }
    Personaje::recibeAtaque(puntos);
}

void Mago::atacar(Personaje& objetivo) {
    Personaje::atacar(objetivo);
    if (objetivo.getSalud() == 0) {
        mana = mana + 20;
        if (mana > 100) mana = 100;
    }
}

void Mago::imprimir() {
    Personaje::imprimir();
    cout << "Mana: " << mana << endl;
}
