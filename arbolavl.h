#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#include "nodoavl.h"
#include "proyecto.h"
#include "Listagenerica.h"
#include <iostream>
using namespace std;

class ArbolAVL
{
public:
    ArbolAVL();
    ~ArbolAVL();
    NodoAVL* getRaiz();
    void agregar(Proyecto pro);
    void postOrden(NodoAVL *raiz);
    void inOrden();
    ListaGenerica<Proyecto>* getProyecto(int codigo);
private:
    NodoAVL* raiz;
    NodoAVL* agregar(NodoAVL* raiz, Proyecto pro, bool &escape);
    NodoAVL* rotacionII(NodoAVL* n, NodoAVL* n1);
    NodoAVL* rotacionDD(NodoAVL* n, NodoAVL* n1);
    NodoAVL* rotacionID(NodoAVL* n, NodoAVL* n1);
    NodoAVL* rotacionDI(NodoAVL* n, NodoAVL* n1);
    void eliminar(NodoAVL* raiz);
    void getProyectop(NodoAVL* n, int codigo);
    ListaGenerica<Proyecto>* busqueda;
};

#endif // ARBOLAVL_H
