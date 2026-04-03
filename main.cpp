#include <iostream>
using namespace std;
#include "DtFecha.h"
#include "Lector.h"
#include "Prestamo.h"
#include "Libro.h"
#include "Revista.h"
#include "DtMaterial.h"
#include "DtRevista.h"
#include "DtLibro.h"
const int MAX_LECTORES = 10;
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

bool esMenorFecha(DtFecha fechaPrestamo, DtFecha fechaConsulta)
{
    if (fechaConsulta.anio != fechaPrestamo.anio)
        return fechaConsulta.anio < fechaPrestamo.anio;
    if (fechaConsulta.mes != fechaPrestamo.mes)
        return fechaConsulta.mes < fechaPrestamo.mes;
    return fechaConsulta.dia < fechaPrestamo.dia;
}

//---------------------------------------------------------------

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

DtMaterial **verPrestamosAntesDeFecha(string ci, DtFecha *fecha, int &cantPrestamos)
{
    Lector *lector = buscarLector(ci);
    cantPrestamos = 0;
    for (int i = 0; i < 10; i++)
    {
        Prestamo *p = lector->getPrestamo(i);
        if (p != nullptr && esMenorFecha(*fecha, p->getFechaPrestamo()))
            cantPrestamos++;
    }

    DtMaterial **materialesPrestados = new DtMaterial *[cantPrestamos];
    int j = 0;
    for (int i = 0; i < 10; i++)
    {
        if (lector->getPrestamo(i) != nullptr)
        {
            if (esMenorFecha(*fecha, lector->getPrestamo(i)->getFechaPrestamo()))
            {
                Material *m = lector->getPrestamo(i)->getMaterial();
                if (m->getTipo() == "libro")
                {
                    Libro *l = (Libro *)m;
                    materialesPrestados[j] = new DtLibro(l->getCodigo(), l->getTitulo(), m->getAnioPublicacion(), l->getAutor(), l->getCantPaginas(), 0.0);
                }
                else
                {
                    Revista *r = (Revista *)m;
                    materialesPrestados[j] = new DtRevista(r->getNumeroEdicion(), r->getEsMensual(), r->getCodigo(), r->getTitulo(), m->getAnioPublicacion(), 0.0);
                }
                j++;
            }
        }
    }
    return materialesPrestados;
}
void agregarMaterial(DtMaterial *dtMaterial)
{
    for (int i = 0; i < cantMateriales; i++)
    {
        if (materiales[i]->getCodigo() == dtMaterial->codigo)
            throw invalid_argument("El material ya existe");
    }
    if (dtMaterial->getTipo() == "revista")
    {
        DtRevista *dtr = (DtRevista *)dtMaterial;
        materiales[cantMateriales] = new Revista(dtr->numeroEdicion, dtr->esMensual, dtMaterial->codigo, dtMaterial->titulo, dtMaterial->anioPublicacion);
    }
    else if (dtMaterial->getTipo() == "libro")
    {
        DtLibro *dtl = (DtLibro *)dtMaterial;
        materiales[cantMateriales] = new Libro(dtl->autor, dtl->cantPaginas, dtMaterial->codigo, dtMaterial->titulo, dtMaterial->anioPublicacion);
    }
    cantMateriales++;
}
int main()
{

    materiales[0] = new Libro("Cervantes", 800, "L001", "Don Quijote", 1605);
    materiales[1] = new Revista(5, false, "R001", "National Geographic", 2020);
    materiales[2] = new Revista(56, true, "R002", "Paula", 1996);
    cantMateriales = 3;
    DtFecha fecha(1, 1, 2020);
    lectores[0] = new Lector("1", "Juan Perez", fecha);
    Prestamo* prestamoLibro = new Prestamo(fecha, 10, materiales[0]);
    Prestamo* prestamoRevista = new Prestamo(fecha, 10, materiales[1]);
    lectores[0]->setPrestamo(0, prestamoLibro);
    lectores[0]->setPrestamo(1,prestamoRevista);
    cantLectores = 1;

    int opcion;
    do
    {
        cout << "\nBienvenido!" << endl;
        cout << "Elija la opcion:" << endl;
        cout << "1) Registrar lector" << endl;
        cout << "2) Agregar prestamo" << endl;
        cout << "3) Obtener materiales prestados" << endl;
        cout << "4) Consultar multa de material" << endl;
        cout << "5) Ver prestamos antes de fecha" << endl;
        cout << "6) Agregar material" << endl;
        cout << "0) Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        try
        {
            switch (opcion)
            {
            case 1:
            {
                string ci, nombre;
                int dia, mes, anio;
                cout << "CI: ";
                cin >> ci;
                cout << "Nombre: ";
                cin >> nombre;
                cout << "Dia: ";
                cin >> dia;
                cout << "Mes: ";
                cin >> mes;
                cout << "Anio: ";
                cin >> anio;
                DtFecha fecha(dia, mes, anio);
                registrarLector(ci, nombre, &fecha);
                cout << "Lector registrado!" << endl;
                break;
            }
            case 2:
            {
                string ci, codigo;
                int dia, mes, anio, dias;
                cout << "CI: ";
                cin >> ci;
                cout << "Codigo material: ";
                cin >> codigo;
                cout << "Dia: ";
                cin >> dia;
                cout << "Mes: ";
                cin >> mes;
                cout << "Anio: ";
                cin >> anio;
                cout << "Dias permitidos: ";
                cin >> dias;
                DtFecha fecha(dia, mes, anio);
                agregarPrestamo(ci, codigo, &fecha, dias);
                cout << "Prestamo agregado!" << endl;
                break;
            }
            case 3:
            {
                string ci;
                int cant;
                cout << "CI: ";
                cin >> ci;
                DtMaterial **mats = obtenerMaterialesPrestados(ci, cant);
                cout << "Materiales prestados: " << cant << endl;
                for (int i = 0; i < cant; i++)
                {
                    mats[i]->imprimir();
                    delete mats[i];
                }
                delete[] mats;
                break;
            }
            case 4:
            {
                string ci, codigo;
                int dias;
                cout << "CI: ";
                cin >> ci;
                cout << "Codigo material: ";
                cin >> codigo;
                cout << "Dias de atraso: ";
                cin >> dias;
                float multa = consultarMultaMaterial(ci, codigo, dias);
                cout << "Multa: " << multa << endl;
                break;
            }
            case 5:
            {
                string ci;
                int dia, mes, anio, cant;
                cout << "CI: ";
                cin >> ci;
                cout << "Dia: ";
                cin >> dia;
                cout << "Mes: ";
                cin >> mes;
                cout << "Anio: ";
                cin >> anio;
                DtFecha fecha(dia, mes, anio);
                DtMaterial **mats = verPrestamosAntesDeFecha(ci, &fecha, cant);
                cout << "Materiales: " << cant << endl;
                for (int i = 0; i < cant; i++)
                {
                    mats[i]->imprimir();
                    delete mats[i];
                }
                delete[] mats;
                break;
            }
            case 6:
            {
                int tipo;
                string codigo, titulo;
                int anio;
                cout << "1) Libro  2) Revista: ";
                cin >> tipo;
                cout << "Codigo: ";
                cin >> codigo;
                cout << "Titulo: ";
                cin >> titulo;
                cout << "Año: ";
                cin >> anio;
                DtMaterial *dtm;
                if (tipo == 1)
                {
                    string autor;
                    int pags;
                    cout << "Autor: ";
                    cin >> autor;
                    cout << "Paginas: ";
                    cin >> pags;
                    dtm = new DtLibro(codigo, titulo, anio, autor, pags, 0.0);
                }
                else
                {
                    int edicion;
                    bool mensual;
                    cout << "Numero edicion: ";
                    cin >> edicion;
                    cout << "Es mensual (1/0): ";
                    cin >> mensual;
                    dtm = new DtRevista(edicion, mensual, codigo, titulo, anio, 0.0);
                }
                dtm->codigo = codigo;
                dtm->titulo = titulo;
                dtm->anioPublicacion = anio;
                agregarMaterial(dtm);
                cout << "Material agregado!" << endl;
                delete dtm;
                break;
            }
            case 0:
                cout << "Hasta luego!" << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
            }
        }
        catch (invalid_argument &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    } while (opcion != 0);

    return 0;
};
