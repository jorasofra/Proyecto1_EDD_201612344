#include "Coordenada.h"

Coordenada::Coordenada(int x, int y){
    this->setX(x);
    this->setY(y);
}
void Coordenada::setX(int x){
    this->x = x;
}
void Coordenada::setY(int y){
    this->y = y;
}

int Coordenada::getX(){
    return x;
}
int Coordenada::getY(){
    return y;
}
