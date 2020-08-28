#include "nodomatriz.h"

NodoMatriz::NodoMatriz()
{
    this->norte = NULL;
    this->sur = NULL;
    this->este = NULL;
    this->oeste = NULL;
}

void NodoMatriz::setNorte(NodoMatriz *norte){
    this->norte = norte;
}

void NodoMatriz::setSur(NodoMatriz *sur){
    this->sur = sur;
}

void NodoMatriz::setEste(NodoMatriz *este){
    this->este = este;
}

void NodoMatriz::setOeste(NodoMatriz *oeste){
    this->oeste = oeste;
}

NodoMatriz* NodoMatriz::getNorte(){
    return this->norte;
}

NodoMatriz* NodoMatriz::getSur(){
    return this->sur;
}

NodoMatriz* NodoMatriz::getEste(){
    return this->este;
}

NodoMatriz* NodoMatriz::getOeste(){
    return this->oeste;
}
