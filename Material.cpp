#include "Material.h"

Material::Material(string codigo, string titulo, int anioPublicacion) {
    this->codigo = codigo;
    this->titulo = titulo;
    this->anioPublicacion = anioPublicacion;
}
Material::~Material(){}
string Material::getCodigo() { return codigo; }
string Material::getTitulo() { return titulo; }
int Material::getAnioPublicacion() { return anioPublicacion; }