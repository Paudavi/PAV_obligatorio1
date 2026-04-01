#include "DtMaterial.h"

DtMaterial::DtMaterial(string codigo, string titulo, int anioPublicacion, float multaBase){
    this->anioPublicacion = anioPublicacion;
    this->codigo = codigo;
    this->multaBase = multaBase;
    this->titulo = titulo;
};