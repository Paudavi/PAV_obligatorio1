#include "DtRevista.h"
#include <iostream>
#include "DtMaterial.h"
DtRevista::DtRevista(int numeroEdicion, bool esMensual, string codigo, string titulo, int anioPublicacion, float multaBase) : DtMaterial(codigo, titulo, anioPublicacion, 0.0)
{
    this->numeroEdicion = numeroEdicion;
    this->esMensual = esMensual;
}
DtRevista::~DtRevista() {}

std::string DtRevista::getTipo() { return "revista"; }
void DtRevista::imprimir() {
    DtMaterial::imprimir();
    cout << "- Numero de edicion: " << numeroEdicion << endl;
    cout << "- Es mensual: " << (esMensual ? "Si" : "No") << endl;
}