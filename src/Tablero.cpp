/*
  Nombre: Tablero.cpp
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

#include "Tablero.h"


Tablero::Tablero()
{
    inicializar();
    crearTablero();
    crearEscalera();
    crearSerpiente();
}

Tablero::~Tablero()
{
    //dtor
}

void Tablero::inicializar()
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            tablero[i][j] = "| ";
        }
    }
}

void Tablero::crearEscalera()
{
    escaleraInicio[0]=2;
    escaleraFin[0]=18;
    escaleraInicio[1]=11;
    escaleraFin[1]=31;
    escaleraInicio[2]=15;
    escaleraFin[2]=25;
    escaleraInicio[3]=44;
    escaleraFin[3]=74;
    escaleraInicio[4]=48;
    escaleraFin[4]=53;
    escaleraInicio[5]=58;
    escaleraFin[5]=62;
    escaleraInicio[6]=77;
    escaleraFin[6]=98;
}

void Tablero::crearSerpiente()
{
    serpienteInicio[0]=16;
    serpienteFin[0]=6;
    serpienteInicio[1]=27;
    serpienteFin[1]=7;
    serpienteInicio[2]=39;
    serpienteFin[2]=24;
    serpienteInicio[3]=60;
    serpienteFin[3]=38;
    serpienteInicio[4]=64;
    serpienteFin[4]=54;
    serpienteInicio[5]=73;
    serpienteFin[5]=46;
    serpienteInicio[6]=79;
    serpienteFin[6]=37;
    serpienteInicio[7]=90;
    serpienteFin[7]=32;
    serpienteInicio[8]=93;
    serpienteFin[8]=74;
    serpienteInicio[9]=99;
    serpienteFin[9]=83;
}

string Tablero::toString(int x)
{
    string salida = "";
    stringstream stream;
    stream << x;
    salida = stream.str();
    return salida;
}

int Tablero::toInt(string x)
{
    int salida;
    salida = atoi(x.c_str());
    return salida;
}

void Tablero::crearTablero()
{
    int g=1;
    int contadorxz=0;

    for(int f=9;f!=-1;f--)
        {
            if(contadorxz==0)
            {
                for(int x=0;x<10;x++)
                {
                    tablero[f][x]= toString(g);
                    g++;
                }
            }
            if(contadorxz==1)
                {
                    for(int x=9;x!=-1;x--)
                    {
                        tablero[f][x]=toString(g);
                        g++;
                    }
                }
            if(contadorxz==1)
                {
                    contadorxz=0;
                }
            else
                {
                    contadorxz=1;
                }
        }
}

void Tablero::imprimirTablero()
{
    int contador=1; // Con este contador se dibujara el tablero, al ser igual a 1 dibujara el techo.
    int enumerador = 100; // Se utiliza para incluir los números en la matriz, comienza en 100 y se decrementa hasta 1.
    char borde= '-';
    cout << "   \nESCALERAS Y SERPIENTES "<< endl << endl;
    cout << endl;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(contador==1)
            {
                {
                    if(j==0){cout << borde;}
                    cout << borde<< borde<< borde<<borde<<borde;
                    if(j==9 ){cout << borde;}

                    if(j==9){j=0;contador=2; cout<<endl;enumerador--;}
                }
            }

            if(contador == 2)
            {
                if(j== 0){
                        cout << '|'<< " ";
                }
                if(toInt(tablero[i][j])< 10)
                {
                    cout<<"  "<< tablero[i][j] <<" " << '|';/* el tablero normal */
                }

                else if (tablero[i][j] == "100")
                {
                        cout<< tablero[i][j] <<" " << '|';
                    }

                else
                    {
                        cout<<" "<< tablero[i][j] <<" " << '|';
                    }

                if(j==9)
                {
                    j = 0;contador = 3;cout<<endl;enumerador--;
                }
            }

            if(contador == 3)
                {

                    if(j==9 ){contador=1;enumerador--;}
                }

        }
    }
    cout<<borde<<borde<<borde<<borde<<borde<<borde<<borde<<borde<<borde<<borde<<borde<<
          borde<<borde<<borde<<borde<<borde<<borde<<borde<<borde<<borde<<borde<<borde<<borde<<borde<<
        borde<<borde<<borde<<borde<<borde<<borde<<borde<<borde<<borde<<borde<<borde<<borde<<borde<<
        borde<<borde<<borde<<borde<<borde<<borde<<borde<<borde<<borde<<borde<<borde<<borde<<borde<<borde<<borde;
}

bool Tablero::gano()
{
    if(tablero[0][0] != "100")
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Tablero::moverJugador(string ficha, int posAnterior, int posNueva)
{
    actualizaTablero(ficha, posAnterior);
    mover(ficha, posNueva);
}

void Tablero::actualizaTablero(string ficha, int posAnterior)
{
    string posAnt = toString(posAnterior);
    for(int i=0; i<10;i++)
    {
        for(int j=0; j<10;j++)
        {
            if (tablero[i][j]==ficha)
            {
                tablero[i][j]= posAnt;
            }
        }
    }
}

void Tablero::mover(string ficha, int posNueva)
{
    string posN = toString(posNueva);
    for(int p=0; p<10; p++)
    {
        for(int q=0; q<10; q++)
        {
            if (tablero[p][q]== posN)
            {
                tablero[p][q]=ficha;
            }
        }
    }
    imprimirTablero();
}

int Tablero::escalera(int posicion)
{
    int pos = posicion;
    for (int i=0; i<7; i++)
    {
        if (pos == escaleraInicio[i])
        {
            pos = escaleraFin[i];
        }
    }
    return pos;
}

int Tablero::serpiente(int posicion)
{
    int pos = posicion;
    for (int i=0; i<10; i++)
    {
        if (pos == serpienteInicio[i])
        {
            pos = serpienteFin[i];
        }
    }
    return pos;
}
