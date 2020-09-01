#ifndef NODOABB_H
#define NODOABB_H
#include "nodoarbol.h"
#include "Objeto.h"

class NodoABB:public NodoArbol
{
public:
    NodoABB(Objeto obj);
    void setObjeto(Objeto obj);
    Objeto getObjeto();
private:
    Objeto obj;
};

#endif // NODOABB_H
