#include "Lector.h"

Lector::Lector(string ci, string nombre, DtFecha fechaRegistro) : fechaRegistro(fechaRegistro)
{
    this->ci = ci;
    this->nombre = nombre;
    for (int i = 0; i < 10; i++)
    {
        prestamos[i] = nullptr;
    }
}
string Lector::getCi() { return ci; }
string Lector::getNombre() { return nombre; }
DtFecha Lector::getFechaRegistro() { return fechaRegistro; }
Prestamo* Lector::getPrestamo(int i) { return prestamos[i]; }
void Lector::setCi(string ci) { this->ci = ci; }
void Lector::setNombre(string nombre) { this->nombre = nombre; }
void Lector::setFechaRegistro(DtFecha fechaRegistro) { this->fechaRegistro = fechaRegistro; }
void Lector::setPrestamo(int i, Prestamo* p) { prestamos[i] = p; }
Lector::~Lector(){
    for(int i=0;i<0;i++){
        if (prestamos[i] != nullptr) delete prestamos[i];
    }
}