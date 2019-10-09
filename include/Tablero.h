/*
  Nombre: Tablero.h
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

#ifndef TABLERO_H
#define TABLERO_H
#include <string>
#include<windows.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/*
   Clase: Tablero
   Responsabilidad:
            - Crear el inicio y el final de las serpientes que van a estar dentro de la matriz tablero.
            - Crear el inicio y el final de las escaleras que van a estar dentro de la matriz tablero.
            - Imprimir la matriz tablero con las serpientes y escaleras asignadas en cada posición.

   Colaboración: Ninguna.
*/

class Tablero
{
    public:
        Tablero();
        ~Tablero();
        void inicializar();
        void crearSerpiente();
        void crearEscalera();
        void crearTablero();

        int escalera(int);
        int serpiente(int);

        void situarJugadores();
        void moverJugador(string,int, int);
        void actualizaTablero(string ficha, int posAnterior);
        void mover(string ficha, int posNueva);
        bool gano();

        int toInt(string);
        void imprimirTablero();
        string toString(int);
    protected:
    private:
        int escaleraInicio[7];
        int escaleraFin[7];
        int serpienteInicio[10];
        int serpienteFin[10];
        string tablero[10][10];

};

#endif // TABLERO_H
