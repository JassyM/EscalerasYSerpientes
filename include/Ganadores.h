/*
  Nombre: Ganadores.h
  Autor: Grupo N�6
        - Andres Felipe Arana Lozano
        - Jassy Maribel Jaramillo Suarez
        - Natalia Rubiano Silva
  Fecha Creacion: Noviembre 1 de 2014
  Fecha Modificaci�n: Diciembre 9 de 2014
  Versi�n : 7.0
  Email: - andres.arana@correounivalle.edu.com
         - jassy.jaramillo@gmail.com
         - nataove.nrs@gmail.com
*/

#ifndef GANADORES_H
#define GANADORES_H
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*
    Clase: Ganadores
    Responsabilidad:
                - Crea un archivo con una lista de los nombres de jugadores que hayan ganado el juego
                  y con su respectivo puntaje.
                - Muestra la lista de los nombres de los jugadores que han ganado con su acumulado de puntos.
    Colaboracion: Ninguna.
*/

class Ganadores
{
    public:
        Ganadores();
        ~Ganadores();
        string toString(int x);
        void guardarArchivo(string nombreJ,int puntos);
        string cargarArchivo(string nombreArchivo);
    protected:
    private:
};

#endif // GANADORES_H
