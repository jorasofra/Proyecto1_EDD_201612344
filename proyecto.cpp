#include "proyecto.h"

Proyecto::Proyecto(){
    this->listaNiveles = new ListaGenerica<Nivel>();
}

Proyecto::Proyecto(string nombre)
{
    this->id = 0;
    this->nombre = nombre;
    this->listaNiveles = new ListaGenerica<Nivel>();
}

void Proyecto::setId(int id){
    this->id = id;
}

void Proyecto::setNombre(string nombre){
    this->nombre = nombre;
}

string Proyecto::getNombre(){
    return this->nombre;
}

int Proyecto::getId(){
    return this->id;
}
