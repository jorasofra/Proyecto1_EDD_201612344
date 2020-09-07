#include <QCoreApplication>
#include "menu.h"
#include "proyecto.h"
#include <leerarchivo.h>
#include "nivel.h"
#include "nodoobjeto.h"
#include "arbolavl.h"

int main()
{
    ArbolAVL *a = new ArbolAVL();

    Proyecto pr;
    Nivel n;
    n.setNumero(1);

    NodoObjeto *o1 = new NodoObjeto(0,0,'1',"#FFFFE0");
    NodoObjeto *o2 = new NodoObjeto(1,1,'2',"#FFFFE0");
    NodoObjeto *o4 = new NodoObjeto(2,2,'4',"#FFFFE0");
    NodoObjeto *o3 = new NodoObjeto(1,2,'3',"#FFFFE0");
    NodoObjeto *o5 = new NodoObjeto(2,4,'5',"#FFFFE0");
    NodoObjeto *o6 = new NodoObjeto(2,0,'6',"#FFFFE0");
    NodoObjeto *o7 = new NodoObjeto(1,0,'7',"#FFFFE0");
    NodoObjeto *o8 = new NodoObjeto(2,1,'8',"#FFFFE0");

    n.agregarObjetoMatriz(o1);
    n.agregarObjetoMatriz(o2);
    n.agregarObjetoMatriz(o3);
    n.agregarObjetoMatriz(o4);
    n.agregarObjetoMatriz(o5);
    n.agregarObjetoMatriz(o6);
    n.agregarObjetoMatriz(o7);
    n.agregarObjetoMatriz(o8);

    pr.agregarNivel(n);

    n.graficar();

    a->agregar(pr);

    //Menu men;
    //men.encabezado();
    //men.menuPrincipal();
    //LeerArchivo l;
    //l.leer("C:/Users/solis/OneDrive/Escritorio/Rafael/Estructuras de Datos/Laboratorio/Proyectos.json");
    return 0;
}
