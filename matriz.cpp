#include "matriz.h"

Matriz::Matriz()
{
    this->x = NULL;
    this->y = NULL;
}

Matriz::~Matriz(){
    NodoMatriz* tmpX, *tmpY, *auxX, *auxX2, *xflg, *yflg;
    xflg = this->x;
    yflg = this->y;
    while(yflg != NULL){
        tmpY = yflg->getSur();
        auxX = yflg->getEste();
        while(auxX != NULL){
            tmpX = auxX->getEste();
            delete auxX;
            auxX = tmpX;
        }
        delete yflg;
        yflg = tmpY;
    }
    while(xflg != NULL){
        auxX2 = xflg->getEste();
        delete xflg;
        xflg = auxX2;
    }
}

Cabecera* Matriz::crearX(int px){
    if(this->x == NULL){
        Cabecera* nuevo= new Cabecera(px);
        this->x = nuevo;
        return nuevo;
    }
    Cabecera *aux = this->x;
    if(px < aux->getPosicion()){
        Cabecera* nuevo = new Cabecera(px);
        nuevo->setEste(aux);
        this->x->setOeste(nuevo);
        this->x = nuevo;
        return nuevo;
    }
    while(aux->getEste() != NULL){
        if((px > aux->getPosicion()) && (px < ((Cabecera*)((NodoMatriz*)aux)->getEste())->getPosicion())){
            Cabecera* nuevo = new Cabecera(px);
            Cabecera* tmp = (Cabecera*)aux->getEste();
            tmp->setOeste(nuevo);
            nuevo->setEste(tmp);
            aux->setEste(nuevo);
            nuevo->setOeste(aux);
            return nuevo;
        }
        aux = (Cabecera*)aux->getEste();
    }
    Cabecera* nuevo = new Cabecera(px);
    aux->setEste(nuevo);
    nuevo->setOeste(aux);
    return nuevo;
}

Cabecera* Matriz::crearY(int py){
    if(this->y == NULL){
        Cabecera* nuevo = new Cabecera(py);
        this->y = nuevo;
        return nuevo;
    }
    Cabecera *aux = this->y;
    if(py < aux->getPosicion()){
        Cabecera* nuevo = new Cabecera(py);
        nuevo->setSur(aux);
        this->y->setNorte(nuevo);
        this->y = nuevo;
        return nuevo;
    }
    while(aux->getSur() != NULL){
        if((py > aux->getPosicion()) && (py < ((Cabecera*)((NodoMatriz*)aux)->getSur())->getPosicion())){
            Cabecera* nuevo = new Cabecera(py);
            Cabecera* tmp = (Cabecera*)aux->getSur();
            tmp->setNorte(nuevo);
            nuevo->setSur(tmp);
            aux->setSur(nuevo);
            nuevo->setNorte(aux);
            return nuevo;
        }
        aux = (Cabecera*)aux->getSur();
    }
    Cabecera* nuevo = new Cabecera(py);
    aux->setSur(nuevo);
    nuevo->setNorte(aux);
    return nuevo;
}

NodoMatriz* Matriz::ultimoX(Cabecera *cabecera, int posicion){
    if(cabecera->getEste()== NULL){
        return cabecera;
    }
    NodoMatriz* aux = cabecera->getEste();
    while(aux->getEste() != NULL){
        if(posicion <= ((Cabecera*)(aux))->getPosicion()){
            return aux;
        }
        aux = aux->getEste();
    }
    if(posicion <= ((Cabecera*)(aux))->getPosicion()){
        return aux->getOeste();
    }
    return aux;
}

NodoMatriz* Matriz::ultimoY(Cabecera *cabecera, int posicion){
    if(cabecera->getSur()==NULL){
        return cabecera;
    }
    NodoMatriz* aux = cabecera->getSur();
    while(aux->getSur() != NULL){
        if(posicion <= ((Cabecera*)aux)->getPosicion()){
            return aux;
        }
        aux = aux->getSur();
    }
    if(posicion <= ((Cabecera*)aux)->getPosicion()){
        return aux->getNorte();
    }
    return aux;
}

Cabecera* Matriz::getX(int posicion){
    if(this->x == NULL){
        return NULL;
    }
    Cabecera* aux = this->x;
    while(aux != NULL){
        if(posicion == aux->getPosicion()){
            return aux;
        }
        aux = (Cabecera*)aux->getEste();
    }
    return NULL;
}

Cabecera* Matriz::getY(int posicion){
    if(this->y == NULL){
        return NULL;
    }
    Cabecera* aux = this->y;
    while(aux != NULL){
        if(posicion == aux->getPosicion()){
            return aux;
        }
        aux = (Cabecera*)aux->getSur();
    }
    return NULL;
}

void Matriz::agregar(NodoObjeto *nuevo){
    Cabecera *y=this->getY(nuevo->getPosY());
    Cabecera *x=this->getX(nuevo->getPosX());
    if(y == NULL){
        y = this->crearY(nuevo->getPosY());
    }
    if(x == NULL){
        x = this->crearX(nuevo->getPosX());
    }
    NodoMatriz *izquierda = this->ultimoX(y, nuevo->getPosX());
    NodoMatriz *superior = this->ultimoY(x, nuevo->getPosY());
    if(izquierda->getEste() == NULL){
        izquierda->setEste(nuevo);
        nuevo->setOeste(izquierda);
    } else {
        NodoMatriz* tmp=izquierda->getEste();
        izquierda->setEste(nuevo);
        nuevo->setOeste(izquierda);
        tmp->setOeste(nuevo);
        nuevo->setEste(tmp);
    }
    if(superior->getSur() == NULL){
        superior->setSur(nuevo);
        nuevo->setNorte(superior);
    } else {
        NodoMatriz* tmp=superior->getSur();
        superior->setSur(nuevo);
        nuevo->setNorte(superior);
        tmp->setNorte(nuevo);
        nuevo->setSur(tmp);
    }
}

void Matriz::graficar(){
    ofstream archivo;
    archivo.open("C:/Users/solis/OneDrive/Escritorio/salida.dot");

    archivo<<"digraph Matriz { \n\tnode[shape = box]"<<endl;
    archivo<<"\tMt[ label = \"Pivote\", width = 1.5, style = filled, fillcolor = firebrick1, group = 1 ];"<<endl;
    archivo<<"\te0[ shape = point, width = 0 ];"<<endl;
    archivo<<"\te1[ shape = point, width = 0 ];"<<endl;

    string rankX = "{rank = same; Mt;";

    Cabecera *fila = this->y;

    int contador = 0;
    archivo << "\t//Se crean las cabeceras filas" << endl;

    while (fila != NULL){
        archivo << "\tF" << contador << "[label=";
        archivo << "\"" << fila->getPosicion() << "\"" << "width=1.5 group = 1];" << endl;
        fila = (Cabecera*)((NodoMatriz*)fila)->getSur();
        contador++;
    }

    fila = this->y;
    contador = 0;

    archivo << "\t//Enlaces cabeceras filas" << endl;

    while ((Cabecera*)((NodoMatriz*)fila)->getSur() != NULL){
        archivo << "\tF" << contador << "->" << "F" << contador + 1 << endl;
        archivo << "\tF" << contador + 1 << "->" << "F" << contador<< endl;
        fila = (Cabecera*)((NodoMatriz*)fila)->getSur();
        contador++;
    }

    Cabecera *columna = this->x;
    contador = 0;
    int grupo = 2;
    archivo << "\t//Se crean las cabeceras columnas" << endl;

    while (columna != NULL) {
        archivo << "\tC" << contador << "[label=";
        archivo << "\"" << columna->getPosicion() << "\"" << "width=1.5 group = " << to_string(grupo) << "];" << endl;
        rankX += "C" + to_string(contador) + ";";
        columna = (Cabecera*)((NodoMatriz*)columna)->getEste();
        grupo++;
        contador++;
    }
    rankX += "}";

    columna = this->x;
    contador = 0;

    archivo << "\t//Enlaces cabeceras columnas" << endl;

    while ((Cabecera*)((NodoMatriz*)columna)->getEste() != NULL) {
        archivo << "\tC" << contador << "->" << "C" << contador + 1 << endl;
        archivo << "\tC" << contador + 1 << "->" << "C" << contador<< endl;
        columna = (Cabecera*)((NodoMatriz*)columna)->getEste();
        contador++;
    }

    archivo << "\tMt -> F0" << endl;
    archivo << "\tMt -> C0" << endl;

    archivo << "\t" << rankX << endl;

    //fila = this->y;
    columna = this->x;
    contador = 0;
    int contador2 = 0;
    grupo = 2;

    archivo << "\t//Creacion de nodos internos "<<endl;

    while(columna != NULL) {

        fila = (Cabecera*)((NodoMatriz*)columna)->getSur();

        while(fila != NULL){
            archivo << "\tC" << to_string(contador) << "_F" << to_string(contador2);
            archivo << " [label = \"" << ((NodoObjeto*)fila)->getLetraObjeto() << "\"";
            archivo << " width = 1.5 style = filled, fillcolor = \"" << ((NodoObjeto*)fila)->getColor();
            archivo << "\", group = " << to_string(grupo) << "];" << endl;
            fila = (Cabecera*)((NodoMatriz*)fila)->getSur();
            contador2++;
        }
        grupo++;
        contador++;
        contador2 = 0,
        columna = (Cabecera*)((NodoMatriz*)columna)->getEste();
    }

    archivo << "\t//Creacion de enlaces internos columnas"<<endl;

    columna = this->x;
    contador = 0;
    contador2 = 0;

    while ((Cabecera*)((NodoMatriz*)columna)->getEste() != NULL) {
        string rankI = "{rank = same; F" + to_string(contador) + ";";
        fila = (Cabecera*)((NodoMatriz*)columna)->getSur();


        columna = (Cabecera*)((NodoMatriz*)columna)->getEste();
    }

    archivo << "}"<<endl;

    archivo.close();

}
