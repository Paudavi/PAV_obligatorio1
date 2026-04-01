#ifndef PRESTAMO_H
#define PRESTAMO_H
#include "DtFecha.h"
#include "Material.h"
class Prestamo
{
private:
    DtFecha fechaPrestamo;
    int diasPermitidos;
    Material* material;
public:
    Prestamo(DtFecha fechaPrestamo, int diasPermitidos, Material* material);
    DtFecha getFechaPrestamo();
    int getDiasPermitidos();
    Material* getMaterial();
    void setFechaPrestamo(DtFecha fechaPrestamo);
    void setDiasPermitidos(int diasPermitidos);
    void setMaterial(Material* material);
    ~Prestamo();
};
#endif