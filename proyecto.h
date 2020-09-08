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
    void setNombre(string nombre);
    void agregarNivel(Nivel nivel);
    string getNombre();
    int getId();
    void imprimirNiveles();
private:
    int id;
    string nombre;
    ListaGenerica<Nivel> *listaNiveles;
    int convertirID(string nombre);
};

#endif // PROYECTO_H
