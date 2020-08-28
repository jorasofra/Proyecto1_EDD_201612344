#ifndef COORDENADA_H
#define COORDENADA_H


class Coordenada
{
private:
    int x,y;
public:
    Coordenada();
    Coordenada(int x, int y);
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
};

#endif // COORDENADA_H
