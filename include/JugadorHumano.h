/*
  Nombre: JugadorHumano.h
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

#ifndef JUGADORHUMANO_H
#define JUGADORHUMANO_H
#include "Jugador.h"
#include <string>

using namespace std;
/*
   Clase: JugadorHumano
   Responsabilidad:
            - Guardar y retornar el nombre del jugador.
            - Guardar y retornar la ficha del jugador.
            - Guardar y retornar la posici�n inicial y la posici�n final del jugador.
            - Esta es la clase derivada de la clase Jugador.h

   Colaboraci�n: Jugador.h  hereda sus atributos y funciones(clase virtual).
*/


class JugadorHumano : public Jugador
{
    public:
        JugadorHumano();
        ~JugadorHumano();
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

#endif // JUGADORHUMANO_H
