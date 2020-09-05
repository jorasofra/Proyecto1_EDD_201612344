#include "leerarchivo.h"

LeerArchivo::LeerArchivo()
{

}

void LeerArchivo::leer(string ruta){
    ifstream reader(ruta);
    json j;
    reader>>j;
    reader.close();

    for (int p = 0; p < ((int)j["proyectos"].size()); p++){
        cout << "Nombre: " << j["proyectos"][p]["nombre"] << endl;

        Proyecto pr;
        pr.setNombre("Pr 1");

        for (int n = 0; n < ((int)j["proyectos"][p]["niveles"].size()); n++){
            cout << "Nivel: " << j["proyectos"][p]["niveles"][n]["nivel"] << endl;
            cout << "Paredes: " << j["proyectos"][p]["niveles"][n]["paredes"].size() << endl;
            cout << "Ventanas: " << j["proyectos"][p]["niveles"][n]["ventanas"].size() << endl;
            cout << "Objetos: " << j["proyectos"][p]["niveles"][n]["objetos"].size() << endl;
        }
    }
}
