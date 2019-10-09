/*
  Nombre: Juez.h
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

#ifndef JUEZ_H
#define JUEZ_H
#include "Tablero.h"
#include "Jugador.h"
#include "Ganadores.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <sstream>

using namespace std;

/*
   Clase: Juez
   Responsabilidad:
            - Muestra la matriz tablero.
            - Asigna a cada jugador una ficha diferente, esta aparecerá en el tablero.
            - Debe situar a cada jugador al iniciar el juego, es decir que los jugadores esten en la casilla salida.
            - Asigna el turno a cada jugador, indica que jugador inicia primero.
            - Da un número al azar del 1 al 6 para que el jugador avance en el tablero.
            - Cambia de posición al jugador después de lanzar el dado en su turno correspondiente.

   Colaboración: Jugador.h
                 Tablero.h
                 Ganadores.h
                 Se necesitan estas clases para relacionar los metodos y las funciones para que así el juego pueda funcionar.
*/

class Juez
{
    public:
        Juez(Jugador *j1, Jugador *j2);
        ~Juez();
        void mostrarTablero();
        void asignarFicha();
        void situarJugadores();
        bool asignarTurno();
        int lanzarDado();
        void moverJugador(bool);
        string toString(int x);
        string Convertir(char c);
        bool termino();
        void asesinarJugador(string n1, int posJ1, string n2, int posJ2);
        string darNombreJ1();
        string darNombreJ2();
        string darFicha1();
        string darFicha2();
        int darPosIJ1();
        int darPosIJ2();
        void msj(int posI,int posF);
        void gano();
        void msjRecorrido(int posFJugador, string nombreJ);
    protected:
    private:
        Tablero tablero;
        Jugador *jugador1;
        Jugador *jugador2;
        bool turno; //true si el turno es del jugador 2, false si el turno es del jugador 1
        int valorDado;
        string info;
        Ganadores ganador;
};

#endif // JUEZ_H
