/*
  Nombre: JugadorMaquina.h
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

#ifndef JUGADORMAQUINA_H
#define JUGADORMAQUINA_H
#include "Jugador.h"
#include <string>

using namespace std;

/*
   Clase: JugadorMaquina
   Responsabilidad:
            - Guardar y retornar el nombre del jugador.
            - Guardar y retornar la ficha del jugador.
            - Guardar y retornar la posición inicial y la posición final del jugador.
            - Los movimientos de este jugador, el computador es quien lo realiza.
            - Esta es la clase derivada de la clase Jugador.h

   Colaboración: Jugador.h  hereda sus atributos y funciones(clase virtual).

*/

class JugadorMaquina : public Jugador
{
    public:
        JugadorMaquina();
        ~JugadorMaquina();
        void nombreJ(string);
        string darNombreJ();
        void fichaJ(string);
        string darFicha();
        void posInicialJ(int);
        int darPosInicial();
        void posFinalJ(int);
        int darPosFinal();
    protected:
    private:
};

#endif // JUGADORMAQUINA_H
