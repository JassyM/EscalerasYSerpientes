/*
  Nombre: Ganadores.h
  Autor: Grupo Nº6
        - Andres Felipe Arana Lozano
        - Jassy Maribel Jaramillo Suarez
        - Natalia Rubiano Silva
  Fecha Creacion: Noviembre 1 de 2014
  Fecha Modificación: Diciembre 9 de 2014
  Versión : 7.0
  Email: - andres.arana@correounivalle.edu.com
         - jassy.jaramillo@gmail.com
         - nataove.nrs@gmail.com
*/

#include "Ganadores.h"

Ganadores::Ganadores()
{
    //ctor
}

Ganadores::~Ganadores()
{
    //dtor
}

string Ganadores::toString(int x)
{
    string salida = "";
    stringstream stream;
    stream << x;
    salida = stream.str();
    return salida;
}

void Ganadores::guardarArchivo(string nombreJ,int puntos)
{
    string punt = toString(puntos);
    string s, linea;
    ifstream leerArchivo("ganadores.txt");
    while(getline(leerArchivo, linea))
    {
        s = s + linea + "\n";
    }
    s = s + nombreJ + "  " + punt;
    ofstream salidaArchivo("ganadores.txt");
    salidaArchivo << s;
}

string Ganadores::cargarArchivo(string nombreArchivo)
{
    string s, linea;
    ifstream leerArchivo(nombreArchivo.c_str());
    while(getline(leerArchivo, linea))
    {
        s = s + linea + "\n";
    }
    return s;
}
