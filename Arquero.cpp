#include <iostream>
#include "Arquero.hpp"
using namespace std;

Arquero::Arquero() : Personaje() {
    precision = 20;
}

Arquero::Arquero(int v, int a, int n, float p) : Personaje(v, a, n) {
    precision = p;
}

float Arquero::getPrecision() { return precision; }
void Arquero::setPrecision(float p) { precision = p; }

int Arquero::calculaAtaque(Personaje& objetivo) {
    int base = Personaje::calculaAtaque(objetivo);
    int tiro = rand() % 100;
    if (tiro < precision) {
        base = base * 2;
    }
    return base;
}

void Arquero::recibeAtaque(int puntos) {
    int esquiva = rand() % 100;
    if (esquiva < precision / 2) {
        puntos = puntos / 2;
    }
    Personaje::recibeAtaque(puntos);
}

void Arquero::imprimir() {
    Personaje::imprimir();
    cout << "Precision: " << precision << endl;
}
