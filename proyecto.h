#ifndef PROYECTO_H
#define PROYECTO_H
#include "Listagenerica.h"
#include "nivel.h"
#include <iostream>
using namespace std;

class Proyecto
{
public:
    Proyecto();
    Proyecto(string nombre);
    void setNivel();
    void setId(int id);
    void setNombre(string nombre);
    string getNombre();
    int getId();
private:
    int id;
    string nombre;
    ListaGenerica<Nivel> *listaNiveles;
};

#endif // PROYECTO_H
