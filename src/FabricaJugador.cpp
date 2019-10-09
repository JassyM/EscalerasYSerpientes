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

#include "FabricaJugador.h"

FabricaJugador::FabricaJugador()
{
    cout <<  endl << endl<< endl;
    cout << "           ¡¡¡ ESCALERAS Y SERPIENTES !!! \n\n" << endl;
    cout <<  endl;
    cout << "  - Inicia el juego con un jugador escogido al azar." << endl;
    cout << "  - Los sucesivos movimientos se realizaran en turnos alternativos" <<endl;
    cout << "    entre ambos jugadores, a razon de una ficha por turno."<<endl;
	cout << "  - Los jugadores se sit\243an en la casilla de salida." <<endl;
	cout << "  - Cada jugador lanza por turnos el dado y avanza con su ficha" <<endl;
	cout << "    tantas casillas como puntos saque." <<endl;
	cout << "  - Si cae en una casilla situada en la base de las escaleras," <<endl;
	cout << "    pasara a la casilla donde termina la escalera." <<endl;
	cout << "  - Si cae en la casilla ocupada por la cola de la serpiente," <<endl;
	cout << "    retrocede hasta la casilla donde esta la cabeza de la serpiente." <<endl;
	cout << "  - Si cae en la casilla ocupada por otro, este \243ltimo retrocede" <<endl;
	cout << "    a la casilla de procedencia del jugador que le ''ha matado''" <<endl;
	cout << "  - Si el numero que saco en la \243ltima jugada es mayor que  " <<endl;
	cout << "    el que necesitaba, la ficha se movera hacia atras tantos lugares" <<endl;
	cout << "    como los numeros de mas que saco." <<endl;
	cout << "  - Gana el juego el que primero llegue a la meta." <<endl;
	cout <<endl<<endl;

    system("pause");
    system("cls");

    cout <<endl<< endl;
    cout << gana.cargarArchivo("ganadores.txt") << endl<< endl;
    system("pause");
    system("cls");
}

FabricaJugador::~FabricaJugador()
{
    //dtor
}


Jugador *FabricaJugador::crear()
{
    int opcion;

    system("cls");
    cout << endl<<endl;
    cout << "  ---------- BIENVENIDO -----------" << endl << endl<< endl;
    cout << "  1. - Jugador Humano Vs Jugador Humano" << endl;
    cout << "  2. - Jugador Humano Vs Maquina" << endl;
    cout << "  3. - Maquina Vs Maquina" << endl;
    cout << "  4. - Salir" << endl;

    do{
        cout << "  Introduzca Opci\242n: ";
        cin >> opcion;
    }while (!((opcion>=1) && (opcion <=4)));

        switch(opcion)
            {
                case 1:
                {
                    system("cls");
                    string nombre1, nombre2;
                    cout << endl << endl;
                    cout << " Ingrese el nombre del jugador 1: " ;
                    cin >> nombre1;
                    cout << " Ingrese el nombre del jugador 2: " ;
                    cin >> nombre2;
                    cout << endl << endl;
                    jugador1 = new JugadorHumano();
                    jugador2 = new JugadorHumano();
                    jugador1->nombreJ(nombre1);
                    jugador2->nombreJ(nombre2);
                    break;
                }
                case 2:
                {
                    system("cls");
                    string nombre1;
                    cout << endl << endl;
                    cout << " Ingrese el nombre del jugador : " ;
                    cin >> nombre1;
                    cout << endl << endl;
                    jugador1 = new JugadorHumano();
                    jugador2 = new JugadorMaquina();
                    jugador1->nombreJ(nombre1);
                    jugador2->nombreJ("Maquina");
                    break;
                }
                case 3:
                {
                    system("cls");
                    cout << endl << endl;
                    jugador1 = new JugadorMaquina();
                    jugador2 = new JugadorMaquina();
                    jugador1->nombreJ("Maquina1");
                    jugador2->nombreJ("Maquina2");
                    break;
                }
                case 4:
                {
                    exit(0);
                    break;
                }
            }

    Juez juez(jugador1, jugador2);
    juez.asignarFicha();

    bool turno = juez.asignarTurno();
    string turno1, turno2;

    if (!turno)
    {
        turno1=juez.darNombreJ1();
        turno2=juez.darNombreJ2();
        cout<<"Inicias t\243, "<< turno1;
        cout << endl<<endl;
    }
    else
    {
        turno1=juez.darNombreJ1();
        turno2=juez.darNombreJ2();
        cout<<"Inicias t\243, "<< turno2;
        cout << endl<<endl;
    }

    system("pause");
    system("cls");

    juez.situarJugadores();

    while(!juez.termino())
    {
            if (!turno)
            {
                if(turno1=="Maquina"||turno1=="Maquina1")
                {
                    Sleep(2000);
                    system("cls");
                    juez.lanzarDado();
                    juez.moverJugador(turno);
                    turno = true;
                }
                else
                {
                    cout << " \n\nPulse una tecla para lanzar el dado " << endl;
                    system("pause>nul");
                    system("cls");
                    juez.lanzarDado();
                    juez.moverJugador(turno);
                    turno = true;
                }
            }
            else
            {
                if(turno2=="Maquina"||turno2=="Maquina2")
                {
                    Sleep(2000);
                    system("cls");
                    juez.lanzarDado();
                    juez.moverJugador(turno);
                    turno = false;
                }
                else
                {
                    cout << " \n\nPulse una tecla para lanzar el dado " << endl;
                    system("pause>nul");
                    system("cls");
                    juez.lanzarDado();
                    juez.moverJugador(turno);
                    turno = false;
                }
            }
    }
    juez.gano();

    delete jugador1;
    delete jugador2;

    return 0;
}
