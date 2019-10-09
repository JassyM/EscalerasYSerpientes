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
#include "JugadorMaquina.h"

JugadorMaquina::JugadorMaquina()
{
    //ctor
}

JugadorMaquina::~JugadorMaquina()
{
    //dtor
}

void JugadorMaquina::nombreJ(string n)
{
    nombre = n;
}

string JugadorMaquina::darNombreJ()
{
    return nombre;
}

void JugadorMaquina::fichaJ(string jugadorFicha) // Se recibe un string que es enviado por la clase Juez, que es la ficha del jugador.
{
    ficha = jugadorFicha;
}

string JugadorMaquina::darFicha()
{
    return ficha;
}

void JugadorMaquina::posInicialJ(int x)
{
     posIJ = x;
}

int JugadorMaquina::darPosInicial()
{
    return posIJ;
}

void JugadorMaquina::posFinalJ(int x)
{
     posFJ = x;
}

int JugadorMaquina::darPosFinal()
{
    return posFJ;
}
