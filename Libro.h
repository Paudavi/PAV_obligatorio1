#ifndef LIBRO_H
#define LIBRO_H
#include "Material.h"
#include <string>
using namespace std;
class Libro : public Material
{
private:
    string autor;
    int cantPaginas;

public:
    Libro(string autor, int cantPaginas, string codigo, string titulo, int anioPublicacion);
    float calcularMulta(int diasAtraso);
    string getAutor();
    int getCantPaginas();
    void setAutor(string autor);
    void setCantPaginas(int cantPaginas);
};

#endif