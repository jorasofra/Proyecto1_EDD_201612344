#ifndef LISTAGENERICA_H
#define LISTAGENERICA_H
#include "Nodogenerico.h"
#include "Nodogenerico.cpp"
#include <iostream>
using namespace std;

template <class T>
class ListaGenerica
{
public:
    ListaGenerica();
    ~ListaGenerica();
    int getSize();
    void agregar(T valor);
    //void eliminarCoordenada(T valor);
    NodoGenerico<T>* imprimirCoordenadas();
private:
    NodoGenerico<T> *cabeza;
    int size;
};

#endif // LISTAGENERICA_H
