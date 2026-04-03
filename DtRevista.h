#ifndef DTREVISTA_H
#define DTREVISTA_H
#include <string>
#include "DtMaterial.h"
class DtRevista : public DtMaterial{
    public:
    int numeroEdicion;
    bool esMensual;
    std::string getTipo();
    DtRevista(int numeroEdicion, bool esMensual, string codigo, string titulo, int anioPublicacion, float multaBase);
    ~DtRevista();
    void imprimir();
};
#endif