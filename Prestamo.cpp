#include "Prestamo.h"

Prestamo::Prestamo(DtFecha fechaPrestamo, int diasPermitidos, Material *material) : fechaPrestamo(fechaPrestamo)
{
    this->diasPermitidos = diasPermitidos;
    this->material = material;
};

DtFecha Prestamo::getFechaPrestamo() { return fechaPrestamo; }
int Prestamo::getDiasPermitidos() { return diasPermitidos; }
Material *Prestamo::getMaterial() { return material; }
void Prestamo::setFechaPrestamo(DtFecha fechaPrestamo) { this->fechaPrestamo = fechaPrestamo; }
void Prestamo::setDiasPermitidos(int diasPermitidos) { this->diasPermitidos = diasPermitidos; }
void Prestamo::setMaterial(Material *material) { this->material = material; }
Prestamo::~Prestamo(){
    delete material;
}
