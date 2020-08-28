#ifndef NODOMATRIZ_H
#define NODOMATRIZ_H
#include <iostream>
using namespace std;

class NodoMatriz
{
public:
    NodoMatriz();
    void setNorte(NodoMatriz* norte);
    void setSur(NodoMatriz* sur);
    void setEste(NodoMatriz* este);
    void setOeste(NodoMatriz* oeste);
    NodoMatriz *getNorte();
    NodoMatriz *getSur();
    NodoMatriz *getEste();
    NodoMatriz *getOeste();
private:
    NodoMatriz *este, *oeste, *norte, *sur;
};

#endif // NODOMATRIZ_H
