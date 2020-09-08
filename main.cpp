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
    pr.setNombre("Hola");

    Proyecto pr2;
    pr2.setNombre("Hol");

    Proyecto pr3;
    pr3.setNombre("loH");

    Nivel n;
    n.setNumero(2);

    Nivel n1;
    n1.setNumero(3);

    Nivel n2;
    n2.setNumero(1);

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
    pr.agregarNivel(n1);
    pr.agregarNivel(n2);

    //n.graficar();

    a->agregar(pr);
    a->agregar(pr2);
    a->agregar(pr3);
    //a->inOrden();
    ListaGenerica<Proyecto> *l = a->getProyecto(388);
    NodoGenerico<Proyecto> *proyect = l->getCabeza();
    cout << pr.getNombre() << endl;

    while(proyect != NULL){
        cout << proyect->getValor().getNombre() << endl;
        proyect = proyect->getSiguiente();
    }

    //Menu men;
    //men.encabezado();
    //men.menuPrincipal();
    //LeerArchivo l;
    //l.leer("C:/Users/solis/OneDrive/Escritorio/Rafael/Estructuras de Datos/Laboratorio/Proyectos.json");
    return 0;
}
