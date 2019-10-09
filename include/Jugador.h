/*
  Nombre: Jugador.h
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

#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

using namespace std;

/*
   Clase: Jugador
   Responsabilidad:
                - De esta clase se definen dos tipos de jugadores(Humano, Maquina) que heredaran sus atributos y funciones.
                  Esta es la clase Base. Clase Abstracta.
   Colaboraci�n: Ninguna.
*/

class Jugador
{
    public:
        Jugador();
        virtual ~Jugador();
        virtual void nombreJ(string) = 0;
        virtual string darNombreJ() = 0;
        virtual void fichaJ(string) = 0;
        virtual string darFicha() = 0;
        virtual void posInicialJ(int) = 0;
        virtual int darPosInicial() = 0;
        virtual void posFinalJ(int) = 0;
        virtual int darPosFinal() = 0;
    protected:
        string nombre;
        string ficha;
        int posIJ;
        int posFJ;
    private:
};

#endif // JUGADOR_H
