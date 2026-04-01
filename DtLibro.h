#ifndef DTLIBRO_H
#define DTLIBRO_H
#include <string>
using namespace std;

class DtLibro{
    public:
    string autor;
    int cantPaginas;

    DtLibro(string autor, int cantPaginas);
};
#endif