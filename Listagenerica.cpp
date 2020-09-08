#include "Listagenerica.h"

template <class T>
ListaGenerica<T>::ListaGenerica()
{
    this->cabeza = NULL;
    this->size = 0;
}

template<class T>
ListaGenerica<T>::~ListaGenerica(){
    NodoGenerico<T> *aux;
    while(this->cabeza != NULL){
        aux = this->cabeza->getSiguiente();
        delete this->cabeza;
        this->cabeza = aux;
    }
}

template <class T>
int ListaGenerica<T>::getSize(){
    return this->size;
}

template <class T>
void ListaGenerica<T>::agregar(T coor){
    NodoGenerico<T>* n = new NodoGenerico<T>(coor);
    if(this->cabeza == NULL)
        this->cabeza = n;
    else {
        NodoGenerico<T> *temp = this->cabeza;
        this->cabeza = n;
        n->setSiguiente(temp);
    }
    this->size++;
}

/*
template<class T>
void ListaGenerica<T>::eliminarCoordenada(T coor){
    T *aux = this->cabeza;
    if(aux->getCoordenada().getX() == coor.getX() &&
        aux->getCoordenada().getY() == coor.getY()){
        this->cabeza = aux->getSiguiente();
        delete aux;
        return;
    }
    T *anterior = aux;
    aux = aux->getSiguiente();
    while(aux != NULL){
        if(coor.getX()==aux->getCoordenada().getX() &&
            coor.getY()==aux->getCoordenada().getY()){
            anterior->setSiguiente(aux->getSiguiente());
            delete aux;
            this->size--;
            return;
        }
        anterior = aux;
        aux = aux->getSiguiente();
    }
}
*/

template  <class T>
void ListaGenerica<T>::insercionOrdenada(T valor){
    NodoGenerico<T>* n = new NodoGenerico<T>(valor);

    if (this->cabeza == NULL){
        this->cabeza = n;
        return;
    }

    NodoGenerico<T>* aux = this->cabeza;
    if (aux->getValor().getNumero() > valor.getNumero()){
        n->setSiguiente(aux);
        this->cabeza = n;
        return;
    }
    NodoGenerico<T>* aux1 = aux->getSiguiente();
    while(aux1 != NULL){
        if ((aux->getValor().getNumero() < valor.getNumero()) && (aux1->getValor().getNumero() > valor.getNumero())){
            aux->setSiguiente(n);
            n->setSiguiente(aux1);
            return;
        }
        aux = aux1;
        aux1 = aux1->getSiguiente();
    }

    aux->setSiguiente(n);
}

template <class T>
NodoGenerico<T>* ListaGenerica<T>::imprimirCoordenadas(){
    return this->cabeza;
}

template <class T>
NodoGenerico<T>* ListaGenerica<T>::imprimirNiveles(){
    return this->cabeza;
}

template <class T>
NodoGenerico<T>* ListaGenerica<T>::getCabeza(){
    return this->cabeza;
}
