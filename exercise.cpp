#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <random>
#include <ctime>
#include "Personaje.hpp"
#include "Guerrero.hpp"
#include "Arquero.hpp"
#include "Mago.hpp"
using namespace std;

void cargarEjercito(vector<Personaje*>& ejercito, string archivo) {
    ifstream f(archivo);
    if (!f.is_open()) {
        throw runtime_error("No se pudo abrir el archivo " + archivo);
    }
    string tipo;
    int v, a, n;
    while (f >> tipo >> v >> a >> n) {
        if (tipo == "Guerrero") {
            int fuerza;
            f >> fuerza;
            ejercito.push_back(new Guerrero(v, a, n, fuerza));
        } else if (tipo == "Arquero") {
            float precision;
            f >> precision;
            ejercito.push_back(new Arquero(v, a, n, precision));
        } else if (tipo == "Mago") {
            int mana;
            f >> mana;
            ejercito.push_back(new Mago(v, a, n, mana));
        } else {
            throw runtime_error("Tipo de combatiente desconocido: " + tipo);
        }
    }
    f.close();
}

void presentarEjercito(vector<Personaje*>& ejercito, string nombre) {
    cout << "===== " << nombre << " =====" << endl;
    for (Personaje* p : ejercito) {
        p->imprimir();
    }
    cout << endl;
}

Personaje* duelo(Personaje* c1, Personaje* c2) {
    int limite = 500;
    while (c1->getSalud() > 0 && c2->getSalud() > 0 && limite > 0) {
        c1->atacar(*c2);
        cout << "  ataca -> ";
        c2->imprimir();
        if (c2->getSalud() == 0) break;
        c2->atacar(*c1);
        cout << "  contraataca -> ";
        c1->imprimir();
        limite--;
    }
    if (*c1 > *c2 || c1->getSalud() == c2->getSalud()) {
        return c1;
    } else {
        return c2;
    }
}

void batalla(vector<Personaje*>& ejercito1, vector<Personaje*>& ejercito2) {
    unsigned semilla = time(0);
    shuffle(ejercito1.begin(), ejercito1.end(), default_random_engine(semilla));
    shuffle(ejercito2.begin(), ejercito2.end(), default_random_engine(semilla + 1));
    int ronda = 1;
    while (!ejercito1.empty() && !ejercito2.empty()) {
        Personaje* c1 = ejercito1.front();
        Personaje* c2 = ejercito2.front();
        cout << "Combate " << ronda << ":" << endl;
        c1->imprimir();
        c2->imprimir();
        Personaje* ganador = duelo(c1, c2);
        if (ganador == c1) {
            cout << "Gana el combatiente del Ejercito 1" << endl;
            delete c2;
            ejercito2.erase(ejercito2.begin());
        } else {
            cout << "Gana el combatiente del Ejercito 2" << endl;
            delete c1;
            ejercito1.erase(ejercito1.begin());
        }
        cout << endl;
        ronda++;
    }
}

int main() {
    srand(time(0));
    vector<Personaje*> ejercito1;
    vector<Personaje*> ejercito2;
    try {
        cargarEjercito(ejercito1, "ejercito1.txt");
        cargarEjercito(ejercito2, "ejercito2.txt");
    } catch (const exception& e) {
        cout << "Error al cargar los ejercitos: " << e.what() << endl;
        return 1;
    }
    presentarEjercito(ejercito1, "Ejercito del Norte");
    presentarEjercito(ejercito2, "Ejercito del Sur");
    batalla(ejercito1, ejercito2);
    if (!ejercito1.empty()) {
        cout << "Gana el Ejercito del Norte" << endl;
        presentarEjercito(ejercito1, "Sobrevivientes del Ejercito del Norte");
        for (Personaje* p : ejercito1) delete p;
    } else {
        cout << "Gana el Ejercito del Sur" << endl;
        presentarEjercito(ejercito2, "Sobrevivientes del Ejercito del Sur");
        for (Personaje* p : ejercito2) delete p;
    }
    return 0;
}