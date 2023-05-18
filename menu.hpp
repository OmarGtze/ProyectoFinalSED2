#include <iostream>
#include <string.h>
#include <fstream>

#include "Pasajeros.h"

using namespace std;

void insertarInicio(string);
void insertarFinal(string);
void mostrarTodo();
void inicializar();   //métodos//
void eliminar(string);
void buscar(string);

void menu_pasajeros()
{

    int opc;
    string respuesta;
    string pos;

    Pasajeros *pasajero=new Pasajeros();

    pasajero->recuperarDesdeArchivo("respaldo_pasajeros.txt");

    do
    {

        system("cls");

        cout << "\t\t\t--------------------MENU-LISTA DE PASAJEROS--------------------\n" << endl;
        cout << "[1] Insertar" << endl;
        cout << "[2] Buscar" << endl;
        cout << "[3] Mostrar Todo" << endl;
        cout << "[4] Eliminar" << endl;
        cout << "[5] Salir\n" << endl;
        cout << "Ingrese la opcion que desee" << endl;
        cin >> opc;

        switch(opc)
        {
        case 1:
        {

            system("cls");

            cout << "\n\t\t\t**********Insertar Datos de Pasajero**********\n" << endl;
            cout << "\nIngrese el pasajeroe del pasajero:" << endl;
            cin >> respuesta;
            pasajero->insertarFinal(respuesta);
            cout << "\nIngrese su origen:" << endl;
            cin >> respuesta;
            pasajero->insertarFinal(respuesta);
            cout << "\nIngrese la fecha de salida:" << endl;
            cin >> respuesta;
            pasajero->insertarFinal(respuesta);
            cout << "\nIngrese la hora de salida:" << endl;
            cin >> respuesta;
            pasajero->insertarFinal(respuesta);
            cout << "\nIngrese su destino:" << endl;
            cin >> respuesta;
            pasajero->insertarFinal(respuesta);
            cout << "\nIngrese la fecha de llegada:" << endl;
            cin >> respuesta;
            pasajero->insertarFinal(respuesta);
            cout << "\nIngrese la hora de llegada:" << endl;
            cin >> respuesta;
            pasajero->insertarFinal(respuesta);
            system("pause");

            pasajero ->respaldarEnArchivo("respaldo_pasajeros.txt");

            break;

        }

        case 2:
        {

            system("cls");

            cout << "\n\t\t\t**********Busqueda de Pasajero**********\n" << endl;
            cout << "\nIngrese el nombre del pasajero" << endl;
            cin >> respuesta;
            pasajero->buscar(respuesta);
            system("pause");
            break;
        }

        case 3:
        {

            system("cls");

            cout << "\n\t\t\t***Lista de Pasajeros***\n" << endl;
            pasajero->mostrarTodo();
            system("pause");
            break;
        }

        case 4:
        {

            system("cls");

            cout << "\n\t\t\t***Eliminar Datos de Pasajero***\n" << endl;
            cout << "Ingrese el nombre del pasajero a eliminar: "; cin >> respuesta;
            pasajero->eliminar(respuesta);

            cout << "\nPasajero eliminado.\n" << endl;

            system("pause");
            break;
        }


        case 5:
        {

            system("cls");

            cout << "\n\t\t\t------------------------------\n" << endl;
            cout << "\t\t\t\t¡Hasta luego!\n" << endl;
            cout << "\n\t\t\t------------------------------\n" << endl;

            exit(0);

            break;
        }
        break;

        default:
            cout << "\nPor favor, ingresa una opcion valida." << endl;

            system("pause");
        }

    }
    while(true);


    system("pause");
}
