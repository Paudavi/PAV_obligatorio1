#ifndef DTREVISTA_H
#define DTREVISTA_H
#include <string>
class DtRevista : public DtMaterial{
    public:
    int numeroEdicion;
    bool esMensual;
    std::string getTipo();
    DtRevista(int numeroEdicion, bool esMensual);
    void imprimir();
};
#endif