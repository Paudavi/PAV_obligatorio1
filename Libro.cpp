#include "Libro.h"

Libro::Libro(string autor, int cantPaginas, string codigo, string titulo, int anioPublicacion)
    : Material(codigo, titulo, anioPublicacion)
{
    this->autor = autor;
    this->cantPaginas = cantPaginas;
}

float Libro::calcularMulta(int diasAtraso)
{
    return diasAtraso * 5;
}

string Libro::getTipo() { return "libro"; }
string Libro::getAutor() { return autor; }
int Libro::getCantPaginas() { return cantPaginas; }
void Libro::setAutor(string autor) { this->autor = autor; }
void Libro::setCantPaginas(int cantPaginas) { this->cantPaginas = cantPaginas; }