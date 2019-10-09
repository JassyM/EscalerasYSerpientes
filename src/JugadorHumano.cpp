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

#include "JugadorHumano.h"

JugadorHumano::JugadorHumano()
{
    //ctor
}

JugadorHumano::~JugadorHumano()
{
    //dtor
}

void JugadorHumano::nombreJ(string n)
{
    nombre = n;
}

string JugadorHumano::darNombreJ()
{
    return nombre;
}

void JugadorHumano::fichaJ(string jugadorFicha) // Se recibe un string que es enviado por la clase Juez, que es la ficha del jugador.
{
    ficha = jugadorFicha;
}

string JugadorHumano::darFicha()
{
    return ficha;
}

void JugadorHumano::posInicialJ(int x)
{
     posIJ = x;
}

int JugadorHumano::darPosInicial()
{
    return posIJ;
}

void JugadorHumano::posFinalJ(int x)
{
     posFJ = x;
}

int JugadorHumano::darPosFinal()
{
    return posFJ;
}
