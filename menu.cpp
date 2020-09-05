#include "menu.h"

Menu::Menu()
{

}

void Menu::encabezado(){
    cout << "*********************" << endl;
    cout << "*USAC" << endl;
    cout << "*Estructuras de Datos" << endl;
    cout << "*Seccion A" << endl;
    cout << "*Jose Rafael Solis Franco" << endl;
    cout << "*201612344" << endl;
    cout << "*********************" << endl;
}

void Menu::menuPrincipal(){
    int opcion = -1;
    while(opcion != 6){
        cout << "\t   Pseudo-Cad" << endl;
        cout << "\t Menu Principal" << endl;
        cout << "Escoja la opcion que desea realizar" << endl;
        cout << "1. Ver Proyectos" << endl;
        cout << "2. Editar Proyectos" << endl;
        cout << "3. Cargar Proyectos" << endl;
        cout << "4. Guardar Proyectos" << endl;
        cout << "5. Cargar Librerias" << endl;
        cout << "6. Salir" << endl;
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "Ver Proyectos" << endl;
            break;
            case 2:
                cout << "Editar Proyectos" << endl;
            break;
            case 3:
                cout << "Cargar Proyectos" << endl;
            break;
            case 4:
                cout << "Guardar Proyectos" << endl;
            break;
            case 5:
                cout << "Cargar Librerias" << endl;
            break;
            case 6:
                cout << "Gracias por utlilizar Pseudo-Cad" << endl;
                return;
            break;
            default :
                cout << "Opcion incorrecta, vuelva a elegir" << endl;
                cout << " " << endl;
        }
        system("cls");
    }
}

void Menu::menuVer(){

}

void Menu::menuEditar(){

}

void Menu::menuGuardar(){

}

void Menu::menuCargarProyectos(){

}

void Menu::menuCargarLibrerias(){

}
