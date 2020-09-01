#ifndef NIVEL_H
#define NIVEL_H
#include "matriz.h"
#include <iostream>
#include "Objeto.h"
using namespace std;

class Nivel
{
public:
    Nivel(int numeroNivel);
    void agregarObjeto(Objeto objeto);
private:
    int numero;
    Matriz *matrizNivel;
    //ArbolAVL arbolObjetos;
};

#endif // NIVEL_H
