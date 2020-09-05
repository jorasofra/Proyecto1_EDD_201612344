#ifndef LEERARCHIVO_H
#define LEERARCHIVO_H
#include "proyecto.h"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;

class LeerArchivo
{
public:
    LeerArchivo();
    void leer(string ruta);
};

#endif // LEERARCHIVO_H
