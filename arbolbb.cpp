#include "arbolbb.h"

ArbolBB::ArbolBB()
{
    this->raiz = NULL;
}

ArbolBB::~ArbolBB(){
    eliminar(this->raiz);
}

void ArbolBB::eliminar(NodoABB* raiz){
    if(raiz == NULL){
        return;
    }
    eliminar((NodoABB*)raiz->getIzquierda());
    eliminar((NodoABB*)raiz->getDerecha());
}

NodoABB* ArbolBB::agregar(NodoABB* raiz, Objeto obj){
    if(raiz == NULL){
        raiz = new NodoABB(obj);
    } else if (obj.getId() < raiz->getObjeto().getId()){
        NodoABB* izq = this->agregar((NodoABB*)raiz->getIzquierda(), obj);
        raiz->setIzquierda(izq);
    } else if (obj.getId() >= raiz->getObjeto().getId()){
        NodoABB* der = this->agregar((NodoABB*)raiz->getDerecha(), obj);
        raiz->setDerecha(der);
    }
    return raiz;
}

void ArbolBB::agregar(Objeto obj){
    this->raiz = agregar(this->raiz, obj);
}
