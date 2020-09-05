#include "nivel.h"

Nivel::Nivel(){
    this->matrizNivel = new Matriz();
    this->arbolObjetos = new ArbolBB();
}

Nivel::Nivel(int nivel)
{
    this->numero = nivel;
    this->matrizNivel = new Matriz();
    this->arbolObjetos = new ArbolBB();
}

void Nivel::agregarObjetoMatriz(NodoObjeto *objeto){
    this->matrizNivel->agregar(objeto);
}

void Nivel::agregarObjetoArbol(Objeto obj){
    this->arbolObjetos->agregar(obj);
}

void Nivel::setNumero(int numeroNivel){
    this->numero = numeroNivel;
}

void Nivel::graficar(){
    this->matrizNivel->graficar();
}
