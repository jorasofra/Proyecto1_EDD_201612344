#include "proyecto.h"

Proyecto::Proyecto(){
    this->listaNiveles = new ListaGenerica<Nivel>();
}

Proyecto::Proyecto(string nombre)
{
    this->id = 0;
    this->setNombre(nombre);
    this->listaNiveles = new ListaGenerica<Nivel>();
}

void Proyecto::setNombre(string nombre){
    this->nombre = nombre;
    this->id = this->convertirID(nombre);
}

string Proyecto::getNombre(){
    return this->nombre;
}

int Proyecto::getId(){
    return this->id;
}

void Proyecto::agregarNivel(Nivel nivel){
    this->listaNiveles->insercionOrdenada(nivel);
}

int Proyecto::convertirID(string nombre){
    int id = 0;
    for (int l = 0; l < (int)nombre.length(); l++){
        char n = (char)nombre.at(l);
        id += n;
    }
    return id;
}

void Proyecto::imprimirNiveles(){
    NodoGenerico<Nivel>* aux = listaNiveles->imprimirNiveles();
    while (aux != NULL) {
        cout << aux->getValor().getNumero() << endl;
        aux = aux->getSiguiente();
    }
}
