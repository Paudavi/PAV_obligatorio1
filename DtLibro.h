#ifndef DTLIBRO_H
#define DTLIBRO_H
#include <string>
using namespace std;

class DtLibro : public DtMaterial{
    public:
    string autor;
    int cantPaginas;
    string getTipo();
    DtLibro(string autor, int cantPaginas);
    void imprimir();
};
#endif