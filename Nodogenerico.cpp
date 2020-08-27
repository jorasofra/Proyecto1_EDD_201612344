#include "Nodogenerico.h"

template <class T>
NodoGenerico<T>::NodoGenerico(T valor)
{
    this->valor = valor;
    this->siguiente = NULL;
}

template <class T>
T NodoGenerico<T>::getValor(){
    return this->valor;
}


template<class T>
void NodoGenerico<T>::setValor(T valor){
    this->valor=valor;
}

template <class T>
void NodoGenerico<T>::setSiguiente(NodoGenerico* siguiente){
    this->siguiente=siguiente;
}

template<class T>
NodoGenerico<T>* NodoGenerico<T>::getSiguiente(){
    return  this->siguiente;
}
