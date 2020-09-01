#ifndef NODOARBOL_H
#define NODOARBOL_H
#include <iostream>
using namespace std;

class NodoArbol
{
public:
    NodoArbol();
    void setFactor(int factor);
    void setIzquierda(NodoArbol *izquierda);
    void setDerecha(NodoArbol *derecha);
    int getFactor();
    NodoArbol* getIzquierda();
    NodoArbol* getDerecha();
private:
    int factorE;
    NodoArbol *izquierda;
    NodoArbol *derecha;
};

#endif // NODOARBOL_H
