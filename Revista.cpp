#include "Revista.h"

Revista::Revista(int numeroEdicion, bool esMensual, string codigo, string titulo, int anioPublicacion) : Material(codigo, titulo, anioPublicacion)
{
    this->numeroEdicion = numeroEdicion;
    this->esMensual = esMensual;
}

float Revista::calcularMulta(int diasAtraso)
{
    return diasAtraso * 2;
}

int Revista::getNumeroEdicion() { return numeroEdicion; }
bool Revista::getEsMensual() { return esMensual; }
void Revista::setNumeroEdicion(int numeroEdicion) { this->numeroEdicion = numeroEdicion; }
void Revista::setEsMensual(bool esMensual) { this->esMensual = esMensual; }