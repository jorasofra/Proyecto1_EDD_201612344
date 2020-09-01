#include "nodoabb.h"

NodoABB::NodoABB(Objeto obj)
{
    this->obj = obj;
}

void NodoABB::setObjeto(Objeto obj){
    this->obj = obj;
}

Objeto NodoABB::getObjeto(){
    return this->obj;
}
