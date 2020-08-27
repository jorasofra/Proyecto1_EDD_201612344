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
        this->cabeza = next;
    }
}

template <class T>
int ListaGenerica<T>::getSize(){
    return this->size;
}

template <class T>
void ListaGenerica<T>::agregar(T coor){
    T *n = new T(coor);
    if(this->cabeza == NULL)
        this->cabeza = n;
    else {
        T *temp = this->cabeza;
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

template <class T>
NodoGenerico<T>* ListaGenerica<T>::imprimirCoordenadas(){
    return this->cabeza;
}
