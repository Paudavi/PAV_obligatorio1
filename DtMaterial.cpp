#include "DtMaterial.h"
#include <iostream>

DtMaterial::DtMaterial(string codigo, string titulo, int anioPublicacion, float multaBase){
    this->anioPublicacion = anioPublicacion;
    this->codigo = codigo;
    this->multaBase = multaBase;
    this->titulo = titulo;
};
std::string DtMaterial::getTipo(){return "";}

void DtMaterial::imprimir() {
    cout << "- Codigo: " << codigo << endl;
    cout << "- Titulo: " << titulo << endl;
    cout << "- Año de publicacion: " << anioPublicacion << endl;
}