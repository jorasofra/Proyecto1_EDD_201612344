#ifndef NIVEL_H
#define NIVEL_H
#include "Objeto.h"
#include "matriz.h"
#include "arbolbb.h"
#include <iostream>
using namespace std;

class Nivel
{
public:
    Nivel();
    Nivel(int numeroNivel);
    void agregarObjetoMatriz(NodoObjeto* objeto);
    void agregarObjetoArbol(Objeto objeto);
    void setNumero(int numeroNivel);
    int getNumero();
    void graficar();
private:
    int numero;
    Matriz *matrizNivel;
    ArbolBB *arbolObjetos;
};

#endif // NIVEL_H
