#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#include "nodoavl.h"
#include "proyecto.h"
#include <iostream>
using namespace std;

class ArbolAVL
{
public:
    ArbolAVL();
    ~ArbolAVL();
    NodoAVL* getRaiz();
    void agregar(Proyecto pro);
private:
    NodoAVL* raiz;
    NodoAVL* agregar(NodoAVL* raiz, Proyecto pro, bool &escape);
    NodoAVL* rotacionII(NodoAVL* n, NodoAVL* n1);
    NodoAVL* rotacionDD(NodoAVL* n, NodoAVL* n1);
    NodoAVL* rotacionID(NodoAVL* n, NodoAVL* n1);
    NodoAVL* rotacionDI(NodoAVL* n, NodoAVL* n1);
    void eliminar(NodoAVL* raiz);
};

#endif // ARBOLAVL_H
