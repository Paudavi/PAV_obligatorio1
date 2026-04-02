#ifndef REVISTA_H
#define REVISTA_H
#include "Material.h"
class Revista : public Material
{
private:
    int numeroEdicion;
    bool esMensual;
public:
    float calcularMulta(int diasAtraso);
    string getTipo();
    Revista(int numeroEdicion, bool esMensual, string codigo, string titulo, int anioPublicacion);
    int getNumeroEdicion();
    bool getEsMensual();
    void setNumeroEdicion(int numeroEdicion);
    void setEsMensual(bool esMensual);
};
#endif