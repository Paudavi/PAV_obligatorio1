#include <iostream>
using namespace std;
#include "DtFecha.h"
#include "Lector.h"
#include "Prestamo.h"
#include "Libro.h"
#include "Revista.h"
#include "DtMaterial.h"
const int MAX_LECTORES = 10;
const int MAX_PRESTAMOS = 10;
const int MAX_MATERIALES = 30;
Lector *lectores[MAX_LECTORES];
Material *materiales[MAX_MATERIALES];
int cantLectores = 0;
int cantMateriales = 0;

// FUNCIONES AUXILIARES
Lector *buscarLector(string ci)
{
    for (int i = 0; i < cantLectores; i++)
    {
        if (lectores[i]->getCi() == ci)
        {
            return lectores[i];
        }
    }
    throw invalid_argument("El lector no está registrado");
}

Material *buscarMaterial(string codigo)
{
    for (int i = 0; i < cantMateriales; i++)
    {
        if (materiales[i]->getCodigo() == codigo)
        {
            return materiales[i];
        }
    }
    throw invalid_argument("No existe material con ese código");
}

void registrarLector(string ci, string nombre, DtFecha *fechaRegistro)
{
    if (cantLectores < MAX_LECTORES)
    {
        lectores[cantLectores] = new Lector(ci, nombre, *fechaRegistro);
        cantLectores++;
    }
}
void agregarPrestamo(string ci, string codigoMaterial, DtFecha *fechaPrestamo, int diasPermitidos)
{
    // Chequear que el lector ya está registrado
    Lector *lector = buscarLector(ci);

    // Chequear que codigoMaterial existe
    Material *material = buscarMaterial(codigoMaterial);

    // Chequear que el lector tiene menos de 10 préstamos
    bool agregado = false;
    for (int i = 0; i < 10 && !agregado; i++)
    {
        Prestamo *flag = lector->getPrestamo(i);
        if (flag == nullptr)
        {
            Prestamo *nuevoPrestamo = new Prestamo(*fechaPrestamo, diasPermitidos, material);
            lector->setPrestamo(i, nuevoPrestamo);
            agregado = true;
        }
    }
    if (!agregado)
        throw invalid_argument("El lector ya ha realizado sus 10 préstamos");
}
DtMaterial **obtenerMaterialesPrestados(string ci, int &cantMateriales)
{
    Lector *lector = buscarLector(ci);

    cantMateriales = 0;
    for (int i = 0; i < 10; i++)
    {
        if (lector->getPrestamo(i) != nullptr)
            cantMateriales++;
    }

    DtMaterial **materialesPrestados = new DtMaterial *[cantMateriales];
    int j = 0;
    for (int i = 0; i < 10; i++)
    {
        if (lector->getPrestamo(i) != nullptr)
        {
            Material *m = lector->getPrestamo(i)->getMaterial();
            materialesPrestados[j] = new DtMaterial(m->getCodigo(), m->getTitulo(), m->getAnioPublicacion(), 0.0);
            j++;
        }
    }
    return materialesPrestados;
}

float consultarMultaMaterial(string ci, string codigoMaterial, int diasAtraso)
{
    Lector *lector = buscarLector(ci);
    for (int i = 0; i < 10; i++)
    {
        Prestamo *prestamoLector = lector->getPrestamo(i);
        if (prestamoLector != nullptr && prestamoLector->getMaterial()->getCodigo() == codigoMaterial)
            return prestamoLector->getMaterial()->calcularMulta(diasAtraso);
    }
    throw invalid_argument("El lector no tiene prestado este material");
}

int main()
{

    materiales[0] = new Libro("Cervantes", 800, "L001", "Don Quijote", 1605);
    materiales[1] = new Revista(5, false, "R001", "National Geographic", 2020);
    materiales[2] = new Revista(56, true, "R001", "Paula", 1996);
    cantMateriales = 3;
    DtFecha fecha(1, 1, 2020);
    lectores[0] = new Lector("1", "Juan Perez", fecha);
    cantLectores = 1;
    return 0;
};
