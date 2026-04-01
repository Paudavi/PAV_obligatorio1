#ifndef DTMATERIAL_H
#define DTMATERIAL_H
#include <string> 

using namespace std;
class DtMaterial{
    public:
    string codigo;
    string titulo;
    int anioPublicacion;
    float multaBase;

    DtMaterial(string codigo, string titulo, int anioPublicacion, float multaBase);
};
#endif