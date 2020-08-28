#ifndef OBJETO_H
#define OBJETO_H
#include "Listagenerica.h"
#include "Listagenerica.cpp"
#include "Nodogenerico.h"
#include "Coordenada.h"
#include <iostream>
using namespace std;

class Objeto
{
public:
    Objeto();
    void setId(int id);
    void setNombre(string nombre);
    void setColor(string color);
    void setLetra(char letra);
    void agregarCoordenada(Coordenada coorde);
    //void eliminarCoordenada(Coordenada coorde);
    void imprimirCoordenadas();

    int getId();
    string getNombre();
    string getColor();
    char getLetra();
private:
    int id;
    string nombre, color;
    char letra;
    ListaGenerica<Coordenada> *lista;
};

#endif // OBJETO_H
