#include "Guerrero.hpp"
#include "Arquero.hpp"
#include "Mago.hpp"

int main() {
    Guerrero guerrero(150, 20, 4, 30);
    Arquero arquero(120, 18, 3, 40);
    Mago mago(100, 15, 5, 100);

    guerrero.imprimir();
    arquero.imprimir();
    mago.imprimir();

    guerrero.atacar(arquero);
    guerrero.imprimir();
    arquero.imprimir();

    arquero.atacar(mago);
    arquero.imprimir();
    mago.imprimir();

    mago.atacar(guerrero);
    mago.imprimir();
    guerrero.imprimir();

    return 0;
}
