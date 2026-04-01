#ifndef MATERIAL_H
#define MATERIAL_H
#include <string>
using namespace std;
class Material
{
protected:
    string codigo;
    string titulo;
    int anioPublicacion;

public:
    Material(string codigo, string titulo, int anioPublicacion);
    virtual float calcularMulta(int diasAtraso) = 0;
    virtual ~Material(){};
    string getCodigo();
    string getTitulo();
    int getAnioPublicacion();
};
#endif