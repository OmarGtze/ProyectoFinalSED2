#ifndef PASAJEROS_H
#define PASAJEROS_H
#include<string.h>
#include<iostream>
#include "Nodo.h"

using namespace std;

class Pasajeros
{
public:

    string getNombre();
    void setNombre(string);

    string getOrigen();
    void setOrigen(string);

    string getFechaSalida();
    void setFechaSalida(string);

    string getHoraSalida();
    void setHoraSalida(string);

    string getDestino();
    void setDestino(string);

    string getFechaLlegada();
    void setFechaLlegada(string);

    string getHoraLlegada();
    void setHoraLlegada(string);

    Pasajeros();
    ~Pasajeros();

    Nodo *h;
    Nodo *t;

    void insertarInicio(string);
    void insertarFinal(string);
    void mostrarTodo();
    void inicializar();   //métodos//
    void eliminar(string);
    void buscar(string);
    void respaldarEnArchivo(string);
    void recuperarDesdeArchivo(string);

    bool operator ==(const Pasajeros&)const;

private:
    string nombre_de_pasajero;
    string origen;
    string fecha_de_salida;
    string hora_de_salida;
    string destino;
    string fecha_de_llegada;
    string hora_de_llegada;      //atributos//
    Nodo* ancla;
};

#endif
