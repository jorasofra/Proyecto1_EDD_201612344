#include "Objeto.h"

Objeto::Objeto(){
    this->lista = new ListaGenerica<Coordenada>();
}
void Objeto::setId(int id){
    this->id=id;
}
void Objeto::setNombre(string nombre){
    this->nombre=nombre;
}
void Objeto::setColor(string color){
    this->color=color;
}
void Objeto::setLetra(char letra){
    this->letra=letra;
}

int Objeto::getId(){
    return id;
}
string Objeto::getNombre(){
    return nombre;
}
string Objeto::getColor(){
    return color;
}
char Objeto::getLetra(){
    return letra;
}
void Objeto::agregarCoordenada(Coordenada coor){
    this->lista->agregar(coor);
}
/*void Objeto::eliminarCoordenada(Coordenada coor){
    this->lista->eliminar(coor);
}*/
void Objeto::imprimirCoordenadas(){
    NodoGenerico<Coordenada> *aux = this->lista->imprimirCoordenadas();
    if (aux != NULL){
        while(aux != NULL){
            cout << "(" << aux->getValor().getX() << ", " << aux->getValor().getY() << ")" << endl;
            aux = aux->getSiguiente();
        }
    }
}
