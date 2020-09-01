#ifndef ARBOLBB_H
#define ARBOLBB_H
#include "nodoabb.h"
#include "Objeto.h"

class ArbolBB
{
public:
    ArbolBB();
    ~ArbolBB();
    NodoABB* getRaiz();
    void agregar(Objeto obj);
private:
    NodoABB* raiz;
    NodoABB* agregar(NodoABB* raiz, Objeto obj);
    void eliminar(NodoABB* raiz);
};

#endif // ARBOLBB_H
