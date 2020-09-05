#ifndef MENU_H
#define MENU_H
#include <iostream>
using namespace std;

class Menu
{
public:
    Menu();
    void encabezado();
    void menuPrincipal();
private:
    void menuVer();
    void menuEditar();
    void menuGuardar();
    void menuCargarProyectos();
    void menuCargarLibrerias();
};

#endif // MENU_H
