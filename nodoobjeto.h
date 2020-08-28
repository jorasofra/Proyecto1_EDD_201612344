#ifndef NODOOBJETO_H
#define NODOOBJETO_H
#include "nodomatriz.h"
#include <iostream>
using namespace std;

class NodoObjeto:public NodoMatriz
{
public:
    NodoObjeto();
    NodoObjeto(int x, int y, char letra, string c);
    void setLetraObjeto(char letra);
    void setColor(string c);
    void setPosX(int x);
    void setPosY(int y);
    char getLetraObjeto();
    string getColor();
    int getPosX();
    int getPosY();
private:
    int posX;
    int posY;
    char letraObjeto;
    string color;
};

#endif // NODOOBJETO_H
