#ifndef CABECERA_H
#define CABECERA_H
#include "nodomatriz.h"
#include <iostream>
using namespace std;

class Cabecera:public NodoMatriz
{
public:
    Cabecera();
    Cabecera(int pos);
    void setPosicion(int pos);
    int getPosicion();
private:
    int posicion;
};

#endif // CABECERA_H
