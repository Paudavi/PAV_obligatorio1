#ifndef DTLIBRO_H
#define DTLIBRO_H
#include <string>
#include "DtMaterial.h"
using namespace std;

class DtLibro : public DtMaterial
{
public:
    string autor;
    int cantPaginas;
    string getTipo();
    DtLibro(string codigo, string titulo, int anioPublicacion, string autor, int cantPaginas, float multaBase);
    void imprimir();
};
#endif