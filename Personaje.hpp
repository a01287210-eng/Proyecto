#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP

class Personaje {
private:
    int vida;
    int salud;
    int ataque;
    int nivel;

public:
    Personaje();
    Personaje(int v, int a, int n);

    int getVida();
    int getSalud();
    int getAtaque();
    int getNivel();

    void setVida(int v);
    void setSalud(int s);
    void setAtaque(int a);
    void setNivel(int n);

    int porcentajeSalud();
    void imprimeBarra();
    virtual int calculaAtaque(Personaje& objetivo);
    virtual void recibeAtaque(int puntos);
    virtual void atacar(Personaje& objetivo);
    virtual void imprimir();
    virtual ~Personaje() {}
};

#endif
