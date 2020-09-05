#include <QCoreApplication>
#include "menu.h"
#include "proyecto.h"
#include <leerarchivo.h>
#include "nivel.h"
#include "nodoobjeto.h"

int main()
{
    Proyecto pr;
    Nivel n;
    n.setNumero(1);

    NodoObjeto *o1 = new NodoObjeto(0,0,'p',"#FFFFE0");
    NodoObjeto *o2 = new NodoObjeto(1,1,'p',"#FFFFE0");
    NodoObjeto *o3 = new NodoObjeto(1,2,'p',"#FFFFE0");
    NodoObjeto *o4 = new NodoObjeto(2,4,'p',"#FFFFE0");

    n.agregarObjetoMatriz(o1);
    n.agregarObjetoMatriz(o2);
    n.agregarObjetoMatriz(o3);
    n.agregarObjetoMatriz(o4);

    pr.agregarNivel(n);

    n.graficar();


    //Menu men;
    //men.encabezado();
    //men.menuPrincipal();
    //LeerArchivo l;
    //l.leer("C:/Users/solis/OneDrive/Escritorio/Rafael/Estructuras de Datos/Laboratorio/Proyectos.json");
    return 0;
}
