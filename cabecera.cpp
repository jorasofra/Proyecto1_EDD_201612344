#include "cabecera.h"

Cabecera::Cabecera()
{
}

Cabecera::Cabecera(int pos){
    this->posicion = pos;
}

void Cabecera::setPosicion(int pos){
    this->posicion = pos;
}

int Cabecera::getPosicion(){
    return this->posicion;
}
