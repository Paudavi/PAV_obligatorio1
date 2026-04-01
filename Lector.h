#ifndef LECTOR_H
#define LECTOR_H
#include <string>
#include "DtFecha.h"
#include "Prestamo.h"
using namespace std;

class Lector
{
private:
    string ci;
    string nombre;
    DtFecha fechaRegistro;
    Prestamo *prestamos[10];

public:
    Lector(string ci, string nombre, DtFecha fechaRegistro);
    string getCi();
    string getNombre();
    DtFecha getFechaRegistro();
    Prestamo* getPrestamo(int i);
    void setCi(string ci);
    void setNombre(string nombre);
    void setFechaRegistro(DtFecha fechaRegistro);
    void setPrestamo(int i, Prestamo* p);
    ~Lector();
};
#endif




