#ifndef NODOAVL_H
#define NODOAVL_H
#include "nodoarbol.h"
#include "proyecto.h"

class NodoAVL: public NodoArbol
{
public:
    NodoAVL();
    NodoAVL(Proyecto pro);
    void setProyecto(Proyecto pro);
    Proyecto getProyecto();
private:
    Proyecto proyec;
};

#endif // NODOAVL_H
