#ifndef NODOGENERICO_H
#define NODOGENERICO_H
#include <iostream>
using namespace std;

template<class T>
class NodoGenerico
{
public:
    NodoGenerico();
    NodoGenerico(T valor);
    void setValor(T valor);
    T getValor();
    void setSiguiente(NodoGenerico* siguiente);
    NodoGenerico* getSiguiente();
private:
    T valor;
    NodoGenerico* siguiente;
};

#endif // NODOGENERICO_H
