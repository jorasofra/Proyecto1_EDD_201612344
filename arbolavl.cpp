#include "arbolavl.h"
#include "cstdbool"

ArbolAVL::ArbolAVL()
{
    this->raiz = NULL;
}

ArbolAVL::~ArbolAVL(){
    eliminar(this->raiz);
}

void ArbolAVL::eliminar(NodoAVL *raiz){
    if(raiz == NULL){
        return;
    }
    eliminar((NodoAVL*)((NodoArbol*)raiz)->getIzquierda());
    eliminar((NodoAVL*)((NodoArbol*)raiz)->getDerecha());
}

NodoAVL* ArbolAVL::rotacionII(NodoAVL* n, NodoAVL* n1){
    n->setIzquierda(n1->getDerecha());
    n1->setDerecha(n);
    if(n1->getFactor() == -1){
        n->setFactor(0);
        n1->setFactor(0);
    } else {
        n->setFactor(-1);
        n1->setFactor(1);
    }
    return n1;
}

NodoAVL* ArbolAVL::rotacionDD(NodoAVL* n, NodoAVL* n1){
    n->setDerecha(n1->getIzquierda());
    n1->setIzquierda(n);
    if(n1->getFactor() == 1){
        n->setFactor(0);
        n1->setFactor(0);
    } else {
        n->setFactor(1);
        n1->setFactor(-1);
    }
    return n1;
}

NodoAVL* ArbolAVL::rotacionID(NodoAVL* n, NodoAVL* n1){
    NodoAVL* n2 = (NodoAVL*)((NodoArbol*)n1)->getDerecha();
    n->setIzquierda(n2->getDerecha());
    n2->setDerecha(n);
    n1->setDerecha(n2->getIzquierda());
    n2->setIzquierda(n1);

    if(n2->getFactor() == 1){
        n1->setFactor(-1);
    } else {
        n1->setFactor(0);
    }

    if(n1->getFactor() == -1){
        n->setFactor(1);
    } else {
        n->setFactor(0);
    }
    n2->setFactor(0);
    return n2;
}

NodoAVL* ArbolAVL::rotacionDI(NodoAVL* n, NodoAVL* n1){
    NodoAVL* n2 = (NodoAVL*)((NodoArbol*)n1)->getIzquierda();
    n->setDerecha(n2->getIzquierda());
    n2->setIzquierda(n);
    n1->setIzquierda(n2->getDerecha());
    n2->setDerecha(n1);

    if(n2->getFactor() == 1){
        n->setFactor(-1);
    } else {
        n->setFactor(0);
    }

    if(n2->getFactor() == -1){
        n1->setFactor(1);
    } else {
        n1->setFactor(0);
    }
    n2->setFactor(0);
    return n2;
}

NodoAVL* ArbolAVL::agregar(NodoAVL* raiz, Proyecto pro, bool &escape){
    NodoAVL *n1;
    if(raiz == NULL){
        raiz = new NodoAVL(pro);
        escape = true;
    } else if(pro.getId() < raiz->getProyecto().getId()){
        NodoAVL* izq = this->agregar((NodoAVL*)((NodoArbol*)raiz)->getIzquierda(), pro, escape);
        raiz->setIzquierda(izq);
        if(escape){
            switch (raiz->getFactor()) {
                case 1:
                    raiz->setFactor(0);
                    escape = false;
                break;
                case 0:
                    raiz->setFactor(-1);
                break;
                case -1:
                    n1 = (NodoAVL*)raiz->getIzquierda();
                    if(n1->getFactor() == -1){
                        raiz = rotacionII(raiz, n1);
                    } else {
                        raiz = rotacionID(raiz, n1);
                    }
                    escape = false;
                break;
            }
        }
    } else if(pro.getId() >= raiz->getProyecto().getId()){
        NodoAVL* der = this->agregar((NodoAVL*)((NodoArbol*)raiz)->getDerecha(), pro, escape);
        raiz->setDerecha(der);
        if(escape){
            switch (raiz->getFactor()) {
                case 1:
                    n1 = (NodoAVL*)raiz->getDerecha();
                    if(n1->getFactor() == 1){
                        raiz = rotacionDD(raiz, n1);
                    } else {
                        raiz = rotacionDI(raiz, n1);
                    }
                    escape = false;
                break;
                case 0:
                    raiz->setFactor(1);
                break;
                case -1:
                    raiz->setFactor(0);
                    escape = false;
                break;
            }
        }
    }
    return raiz;
}

void ArbolAVL::agregar(Proyecto pro){
    bool b = false;
    bool *a = &b;
    this->raiz = agregar(this->raiz, pro, *a);
}

void ArbolAVL::postOrden(NodoAVL *raiz){
    if (raiz != NULL){
        postOrden((NodoAVL*)raiz->getIzquierda());
        postOrden((NodoAVL*)raiz->getDerecha());
        cout << raiz->getProyecto().getNombre() << " " << raiz->getProyecto().getId() << endl;
    }
}

void ArbolAVL::inOrden(){
    if (raiz != NULL){
        postOrden((NodoAVL*)raiz->getIzquierda());
        cout << raiz->getProyecto().getNombre() << " " << raiz->getProyecto().getId() << endl;
        postOrden((NodoAVL*)raiz->getDerecha());
    }
    cout << raiz->getProyecto().getId() << endl;
}

ListaGenerica<Proyecto>* ArbolAVL::getProyecto(int codigo){
    this->getProyectop(this->raiz, codigo);
    return this->busqueda;
}

void ArbolAVL::getProyectop(NodoAVL* n, int codigo){
    if (codigo < n->getProyecto().getId()){
        getProyectop((NodoAVL*)n->getIzquierda(), codigo);
    } else if (codigo > n->getProyecto().getId()) {
        getProyectop((NodoAVL*)n->getDerecha(), codigo);
    } else if (codigo == n->getProyecto().getId()){
        Proyecto pr = n->getProyecto();
        this->busqueda->agregar(pr);
    }
}
