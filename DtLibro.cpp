#include "DtLibro.h"
#include "DtMaterial.h"
#include <iostream>

DtLibro::DtLibro(string codigo, string titulo, int anioPublicacion, string autor, int cantPaginas, float multaBase)
    : DtMaterial(codigo, titulo, anioPublicacion, 0.0)
{

    this->autor = autor;
    this->cantPaginas = cantPaginas;
}

std::string DtLibro::getTipo() { return "libro"; }
void DtLibro::imprimir()
{
    DtMaterial::imprimir();
    cout << "- Autor: " << autor << endl;
    cout << "- Cantidad de paginas: " << cantPaginas << endl;
}