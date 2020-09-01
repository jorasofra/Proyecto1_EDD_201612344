#include "nodoarbol.h"

NodoArbol::NodoArbol()
{
    this->derecha = NULL;
    this->izquierda = NULL;
    this->factorE = 0;
}

void NodoArbol::setFactor(int factor){
    this->factorE = factor;
}

void NodoArbol::setDerecha(NodoArbol *derecha){
    this->derecha = derecha;
}

void NodoArbol::setIzquierda(NodoArbol *izquierda){
    this->izquierda = izquierda;
}

int NodoArbol::getFactor(){
    return this->factorE;
}

NodoArbol* NodoArbol::getDerecha(){
    return this->derecha;
}

NodoArbol* NodoArbol::getIzquierda(){
    return this->izquierda;
}
