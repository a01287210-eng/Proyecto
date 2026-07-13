#include <iostream>
#include "Personaje.hpp"
using namespace std;

Personaje::Personaje() {
    vida = 100;
    salud = 100;
    ataque = 10;
    nivel = 1;
}

Personaje::Personaje(int v, int a, int n) {
    vida = v;
    salud = v;
    ataque = a;
    nivel = n;
}

int Personaje::getVida() { return vida; }
int Personaje::getSalud() { return salud; }
int Personaje::getAtaque() { return ataque; }
int Personaje::getNivel() { return nivel; }

void Personaje::setVida(int v) { vida = v; }
void Personaje::setSalud(int s) { salud = s; }
void Personaje::setAtaque(int a) { ataque = a; }
void Personaje::setNivel(int n) { nivel = n; }

int Personaje::porcentajeSalud() {
    return (salud * 100) / vida;
}

void Personaje::imprimeBarra() {
    int porcentaje = porcentajeSalud();
    int llenos = (porcentaje * 20) / 100;

    for (int i = 0; i < 20; i++) {
        if (i < llenos) {
            cout << "%";
        } else {
            cout << "=";
        }
    }
}

int Personaje::calculaAtaque(Personaje& objetivo) {
    if (objetivo.nivel > nivel) {
        return 1 + rand() % (ataque / 2);
    } else {
        return ataque / 2 + rand() % (ataque / 2 + 1);
    }
}

void Personaje::recibeAtaque(int puntos) {
    salud = salud - puntos;
    if (salud < 0) {
        salud = 0;
    }
}

void Personaje::atacar(Personaje& objetivo) {
    int danio = calculaAtaque(objetivo);
    objetivo.recibeAtaque(danio);
}

void Personaje::imprimir() {
    cout << "Nivel: " << nivel << " Ataque: " << ataque << " Salud: " << salud << "/" << vida << " ";
    imprimeBarra();
    cout << endl;
}
