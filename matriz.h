#ifndef MATRIZ_H
#define MATRIZ_H
#include "nodomatriz.h"
#include "nodoobjeto.h"
#include "cabecera.h"
#include <iostream>
#include <fstream>
using namespace std;

class Matriz
{
public:
    Matriz();
    ~Matriz();
    void agregar(NodoObjeto *nuevo);
    void graficar(int nivel);
private:
    Cabecera* x;
    Cabecera* y;
    Cabecera* getX(int x);
    Cabecera* getY(int y);
    Cabecera* crearX(int px);
    Cabecera* crearY(int py);

    NodoMatriz* ultimoX(Cabecera* cabecera, int posicion);
    NodoMatriz* ultimoY(Cabecera* cabecera, int posicion);
};

#endif // MATRIZ_H
