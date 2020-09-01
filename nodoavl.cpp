#include "nodoavl.h"

NodoAVL::NodoAVL(Proyecto pro)
{
    this->proyec = pro;
}

void NodoAVL::setProyecto(Proyecto pro){
    this->proyec = pro;
}

Proyecto NodoAVL::getProyecto(){
    return this->proyec;
}
