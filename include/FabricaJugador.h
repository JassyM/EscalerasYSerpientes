/*
  Nombre: FabricaJugador.h
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
#ifndef FABRICAJUGADOR_H
#define FABRICAJUGADOR_H
#include "Jugador.h"
#include "Ganadores.h"
#include "JugadorHumano.h"
#include "JugadorMaquina.h"
#include "Juez.h"
#include <iostream>
#include <windows.h>

using namespace std;

/*
   Clase: FabricaJugador
   Responsabilidad:
            - Crea los dos tipos de jugadores(Humano, Maquina).
            - Sirve para seleccionar la pareja de jugadores que van a jugar.
            - Esta clase se relaciona con otras para empezar el juego.
   Colaboración: Jugador.h
                Ganadores.h
                JugadorHumano.h
                JugadorMaquina.h
                Juez.h
*/


class FabricaJugador
{
    private:
        Jugador *jugador1, *jugador2;
        Ganadores gana;

    public:
        FabricaJugador();
        ~FabricaJugador();
        Jugador *crear();

};

#endif // FABRICAJUGADOR_H
