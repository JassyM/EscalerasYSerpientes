/*
  Nombre: Juez.cpp
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

#include "Juez.h"

Juez::Juez(Jugador *j1, Jugador *j2)
{
    jugador1 = j1;
    jugador2 = j2;
}

Juez::~Juez()
{
    //dtor

    delete jugador1;
    delete jugador2;
}

int Juez::lanzarDado()
{
    srand(time(0));
    return valorDado = ((rand()%6) + 1);
}

void Juez::mostrarTablero()
{
    tablero.imprimirTablero();
}

string Juez::Convertir(char c)
{
    return string(1,c);
}

void Juez::asignarFicha()
{
    string X = Convertir(char(4));
    string O = Convertir(char(3));
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),0+7);

    jugador1->fichaJ(X);
    jugador2->fichaJ(O);

    cout << endl;
    cout <<  jugador1->darNombreJ() << "  jugar\240  con la ficha:  ";
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),0+1);
    cout<< jugador1->darFicha() << endl;

    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),0+7);
    cout <<  jugador2->darNombreJ() << "  jugar\240  con la ficha:  ";
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),0+4);
    cout << jugador2->darFicha() << endl<<endl;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),0+7);
}

bool Juez::asignarTurno()
{
    srand(time(0));
    if((rand()%2) == 0) // inicia jugador 2
    {
         return turno = true;
    }
    else
    {
        return turno = false;
    }
}

string Juez::toString(int x)
{
    string salida = "";
    stringstream stream;
    stream << x;
    salida = stream.str();
    return salida;
}

void Juez::situarJugadores()
{
    int x=1;
    jugador1->posInicialJ(x);
    jugador1->posFinalJ(x);
    jugador2->posInicialJ(x);
    jugador2->posFinalJ(x);
    tablero.moverJugador(jugador1->darFicha(), jugador1->darPosInicial(), jugador1->darPosFinal());
    system("cls");
    tablero.moverJugador(jugador2->darFicha(), jugador2->darPosInicial(), jugador2->darPosFinal());
}

void Juez::asesinarJugador(string n1, int posJ1, string n2, int posJ2)
{
    if(posJ1==posJ2)
    {
        cout << endl<<endl;
        cout << n1 << " ha matado al jugador "<<n2<<endl<<endl;
    }
    else
    {
        cout <<"";
    }
}

void Juez::msjRecorrido(int posFJugador, string nombreJ)
{
    if(posFJugador!=100)
    {
        cout << "\n\n "<<nombreJ<< " el valor del dado es: " << valorDado << endl;
    }
    else
    {
        cout << "";
    }
}

void Juez::moverJugador(bool t)
{
    if(!t)
    {
        jugador1->posInicialJ(jugador1->darPosFinal());
        int posx = jugador1->darPosFinal()+valorDado; //se le aasigna a la variable pos, la posición final del jugador.
        int pos, posn;
        posn= tablero.serpiente(posx);//escalera un metodo de tablero que retorna la posicion en la que termina
        pos= tablero.escalera(posn);
        if (pos>100)
        {
            int resta = pos-100;
            pos = 100-resta;
            jugador1->posFinalJ(pos);
            tablero.moverJugador(jugador1->darFicha(),jugador1->darPosInicial(),jugador1->darPosFinal());
        }
        else
        {
            jugador1->posFinalJ(pos);
            if(jugador1->darPosFinal()==jugador2->darPosFinal())
            {
                jugador2->posInicialJ(jugador2->darPosFinal());
                jugador2->posFinalJ(jugador1->darPosInicial());
                tablero.moverJugador(jugador1->darFicha(), jugador1->darPosInicial(),jugador1->darPosFinal());
                system("cls");
                tablero.moverJugador(jugador2->darFicha(), jugador2->darPosInicial(),jugador2->darPosFinal());
            }
            else
            {
                tablero.moverJugador(jugador1->darFicha(), jugador1->darPosInicial(),jugador1->darPosFinal());
            }
        }
        msjRecorrido(jugador2->darPosFinal(), jugador1->darNombreJ());
        asesinarJugador(jugador1->darNombreJ(),jugador1->darPosFinal(),jugador2->darNombreJ(),jugador2->darPosFinal());
        msj(posx, pos);
    }

    else
    {
        jugador2->posInicialJ(jugador2->darPosFinal());
        int posx=jugador2->darPosFinal()+valorDado;
        int pos,posn;

        posn=tablero.serpiente(posx);
        pos=tablero.escalera(posn);
        if (pos>100)
        {
            int resta = pos-100;
            pos = 100-resta;
            jugador2->posFinalJ(pos);
            tablero.moverJugador(jugador2->darFicha(), jugador2->darPosInicial(),jugador2->darPosFinal());
        }
        else
        {
            jugador2->posFinalJ(pos);
            if(jugador2->darPosFinal()==jugador1->darPosFinal())
            {
                jugador1->posInicialJ(jugador1->darPosFinal());
                jugador1->posFinalJ(jugador2->darPosInicial());
                tablero.moverJugador(jugador2->darFicha(), jugador2->darPosInicial(),jugador2->darPosFinal());
            	system("cls");
                tablero.moverJugador(jugador1->darFicha(), jugador1->darPosInicial(),jugador1->darPosFinal());

            }
            else
            {
                tablero.moverJugador(jugador2->darFicha(), jugador2->darPosInicial(),jugador2->darPosFinal());
            }
        }
        msjRecorrido(jugador1->darPosFinal(), jugador2->darNombreJ());
        asesinarJugador(jugador2->darNombreJ(),jugador2->darPosFinal(),jugador1->darNombreJ(),jugador1->darPosFinal());
        msj(posx, pos);
    }

}

void Juez::msj(int posI,int posF)
{
    if((posI==2)||(posI==11)||(posI==15)||(posI==44)||(posI==48)||(posI==58)||(posI==77))
    {
        cout << " \n\n\nHas llegado a una escalera, avanzaras a la casilla: "<< posF << endl;
    }
    else if ((posI==16)||(posI==27)||(posI==39)||(posI==60)||(posI==64)||(posI==73)||(posI==79)||(posI==90)||(posI==93)||(posI==99))
    {
        cout << " \n\n\nHas llegado a una serpiente, retrocederas a la casilla: "<< posF << endl;
    }
    else
    {
        cout << "";
    }
}

string Juez::darNombreJ1()
{
   return  jugador1->darNombreJ();
}

string Juez::darNombreJ2()
{
   return jugador2->darNombreJ();
}

string Juez::darFicha1()
{
   return jugador1->darFicha();
}

string Juez::darFicha2()
{
   return jugador2->darFicha();
}

bool Juez::termino()
{
    return tablero.gano();
}

int Juez::darPosIJ1()
{
    return jugador1->darPosFinal();
}

void Juez::gano()
{
    if(jugador1->darPosFinal()==100)
    {
        cout << endl << endl;
        cout << "   ¡Felicitaciones! "<<endl<<endl;
        cout << jugador1->darNombreJ() << ", has ganado esta partida.\n\n"<<endl;
        ganador.guardarArchivo(jugador1->darNombreJ(), 10);
    }
    else if(jugador2->darPosFinal()==100)
    {
        cout << endl << endl;
        cout << "   ¡Felicitaciones! "<<endl<<endl;
        cout << jugador2->darNombreJ() << ", has ganado esta partida.\n\n"<<endl;
        ganador.guardarArchivo(jugador2->darNombreJ(), 10);
    }
    else
    {
        cout << "";
    }
    exit(0);
}
