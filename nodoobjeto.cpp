#include "nodoobjeto.h"

NodoObjeto::NodoObjeto()
{
}

NodoObjeto::NodoObjeto(int x, int y, char letra, string c){
    this->posX=x;
    this->posY=y;
    this->letraObjeto=letra;
    this->color=c;
}

void NodoObjeto::setColor(string c){
    this->color = c;
}

void NodoObjeto::setLetraObjeto(char letra){
    this->letraObjeto = letra;
}

void NodoObjeto::setPosX(int x){
    this->posX=x;
}

void NodoObjeto::setPosY(int y){
    this->posY=y;
}

string NodoObjeto::getColor(){
    return this->color;
}

char NodoObjeto::getLetraObjeto(){
    return this->letraObjeto;
}

int NodoObjeto::getPosX(){
    return this->posX;
}

int NodoObjeto::getPosY(){
    return this->posY;
}
