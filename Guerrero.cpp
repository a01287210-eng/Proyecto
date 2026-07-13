#include <iostream>
#include "Guerrero.hpp"
using namespace std;

Guerrero::Guerrero() : Personaje() {
    fuerza = 10;
}

Guerrero::Guerrero(int v, int a, int n, int f) : Personaje(v, a, n) {
    fuerza = f;
}

int Guerrero::getFuerza() { return fuerza; }
void Guerrero::setFuerza(int f) { fuerza = f; }

int Guerrero::calculaAtaque(Personaje& objetivo) {
    int base = Personaje::calculaAtaque(objetivo);
    return base + fuerza / 2;
}

void Guerrero::recibeAtaque(int puntos) {
    int reducido = puntos - fuerza / 5;
    if (reducido < 0) reducido = 0;
    Personaje::recibeAtaque(reducido);
}

void Guerrero::imprimir() {
    Personaje::imprimir();
    cout << "Fuerza: " << fuerza << endl;
}
