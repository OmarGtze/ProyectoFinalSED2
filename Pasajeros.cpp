#include "Pasajeros.h"
#include <iostream>
#include <string.h>
#include<conio.h>
#include <fstream>

using namespace std;


string Pasajeros::getNombre(void)
{
    return nombre_de_pasajero;
}

void Pasajeros::setNombre(string nom)
{
    nombre_de_pasajero=nom;
}

string Pasajeros::getOrigen(void)
{
    return origen;
}

void Pasajeros::setOrigen(string orig)
{
    origen=orig;
}

string Pasajeros::getFechaSalida(void)
{
    return fecha_de_salida;
}

void Pasajeros::setFechaSalida(string fechsal)
{
    fecha_de_salida=fechsal;
}

string Pasajeros::getHoraSalida(void)
{
    return hora_de_salida;
}

void Pasajeros::setHoraSalida(string horsal)
{
    hora_de_salida=horsal;
}

string Pasajeros::getDestino(void)
{
    return destino;
}

void Pasajeros::setDestino(string dest)
{
    destino=dest;
}

string Pasajeros::getFechaLlegada(void)
{
    return fecha_de_llegada;
}

void Pasajeros::setFechaLlegada(string fechlleg)
{
    fecha_de_llegada=fechlleg;
}

string Pasajeros::getHoraLlegada(void)
{
    return hora_de_llegada;
}

void Pasajeros::setHoraLlegada(string horlleg)
{
    hora_de_llegada=horlleg;
}

Pasajeros::Pasajeros()
{
    nombre_de_pasajero="";
    hora_de_llegada="";
    fecha_de_llegada="";
    destino="";
    origen="";
    fecha_de_salida="";
    hora_de_salida="";



    h=nullptr;
    t=nullptr;
    ancla=nullptr;
}

Pasajeros::~Pasajeros()
{
}


/*void Pasajeros::insertarInicio(string datoInser)
{
	Nodo *temporal=new Nodo();
	temporal->dato=datoInser;
	temporal->siguiente=nullptr;
	temporal->anterior=nullptr;



	if(h==nullptr && t==nullptr)
	{
		h=temporal;
		t=temporal;


	}
	else
	{
		temporal->siguiente=h;
		h->anterior=temporal;
		h=temporal;

	}


}*/


void Pasajeros::insertarFinal(string datoFinal)
{
    Nodo *tmp = new Nodo();
    tmp->dato = datoFinal;
    tmp->siguiente = nullptr;
    tmp->anterior=nullptr;


    if(h == nullptr && t == nullptr)
    {
        h = tmp;
        t = tmp;
    }
    else
    {
        t->siguiente=tmp;
        tmp->anterior=t;
        t=tmp;
    }
}






void Pasajeros::mostrarTodo()
{
    Nodo *auxiliar;
    auxiliar=h;

    cout<<"\n--------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"NOMBRE DEL PASAJERO"<<" | "<<"  ORIGEN  "<<" | "<<"    FECHA DE SALIDA    "<<" | "<<"  HORA DE SALIDA  "<<" | "<<"   DESTINO   "<<" | "<<"   FECHA DE LLEGADA   "<<" | "<<" HORA DE LLEGADA ";
    cout<<"\n--------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    while(auxiliar != nullptr)
    {
        cout<<"       "<<auxiliar->dato<<"      ";
        auxiliar=auxiliar->siguiente;
    }
    cout<<"\n--------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
}



void Pasajeros::inicializar()
{
    h=nullptr;
    t=nullptr;
}


void Pasajeros::eliminar(string elim)
{
    Nodo *aux;
    bool comparando=true;

    if(aux)
    {
        while(aux and comparando)
        {
            if(h->dato==elim)
            {
                aux=h;
                h=h->siguiente;
                h=h->siguiente;
                h=h->siguiente;
                h=h->siguiente;
                h=h->siguiente;
                h=h->siguiente;

                delete(aux);
            }
            else
            {
                comparando=false;
            }
        }

        if(aux==nullptr)
        {
            cout<<"\n**********Dato no encontrado**********\n"<<endl;
        }
        else if(aux->dato==elim)
        {
            aux=t;
            t=t->anterior;
            delete(aux);
        }
        else if(aux->siguiente==nullptr && aux->anterior==nullptr)
        {
            cout<<"\n**********Lista Vacia**********\n"<<endl;
        }

    }
}


bool Pasajeros::operator ==(const Pasajeros& p)const
{
    nombre_de_pasajero==p.nombre_de_pasajero;
}

void Pasajeros::buscar(string busc)
{
    bool flag = false;
    Nodo *aux = h;

    while (aux != nullptr && aux->dato <= busc)
    {
        if (aux->dato == busc)
        {
            flag = true;
        }
        cout << aux->dato << " ";
        aux = aux->siguiente;
    }

    cout << endl << endl;

    if (flag == true)
    {
        cout << "\n***Elemento buscado se encontro***\n" << endl;
        aux = h;
        while (aux != nullptr)
        {
            cout << aux->dato << " ";
            aux = aux->siguiente;
        }
    }
    else
    {
        cout << "\n***Elemento buscado no se encontro***\n" << endl;
        if (h == nullptr)
        {
            cout << "\tLa lista esta vacia\n";
        }
    }

    getch();
}

void Pasajeros::respaldarEnArchivo(string nombreArchivo)
{
    ofstream archivo(nombreArchivo);

    if (!archivo.is_open())
    {
        cout << "Error al abrir el archivo de respaldo." << endl;
        return;
    }

    Nodo* aux = h;
    while (aux != nullptr)
    {
        archivo << aux->dato << endl;
        aux = aux->siguiente;
    }

    archivo.close();
}

void Pasajeros::recuperarDesdeArchivo(string nombreArchivo)
{
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open())
    {
        cout << "Error al abrir el archivo de respaldo." << endl;
        return;
    }

    string dato;
    while (getline(archivo, dato))
    {
        // Agregar dato a la lista de pasajeros
        // Suponiendo que tienes una función "agregarPasajero" para agregar cada pasajero a la lista
        insertarFinal(dato);
    }

    archivo.close();
}



/*
void Pasajeros::buscar(string busc)
{
	bool flag = false;

    Nodo *aux = new Nodo();
	aux=h;


cout<<"\n***Elemento buscado se encontro***\n"<<endl;
    while((aux != nullptr) && (aux->dato <= busc)){
    	if(aux->dato == busc){
		flag = true;
		}
		cout<<aux->dato<<" ";
        aux=aux->siguiente;
        aux=aux->anterior;
        aux=aux->siguiente;

    }
    cout<<endl<<endl;

    if(flag == true){
        cout<<"\n***Elemento buscado se encontro***\n"<<endl;
        cout<<aux->dato<<" ";
        aux=aux->siguiente;
        aux=aux->anterior;
        aux=aux->siguiente;

        cout<<aux->dato<<" ";
        aux=aux->siguiente;
        aux=aux->anterior;
        aux=aux->siguiente;

        cout<<aux->dato<<" ";
        aux=aux->siguiente;
        aux=aux->anterior;
        aux=aux->siguiente;

        cout<<aux->dato<<" ";
        aux=aux->siguiente;
        aux=aux->anterior;
        aux=aux->siguiente;

        cout<<aux->dato<<" ";
        aux=aux->siguiente;
        aux=aux->anterior;
        aux=aux->siguiente;

        cout<<aux->dato<<" ";
        aux=aux->siguiente;
        aux=aux->anterior;
        aux=aux->siguiente;


    }
	else{
        cout<<"\n***Elemento buscado no se encontro***\n"<<endl;
        if(h == nullptr){
            cout<<"\tLa lista esta vacia\n";
        }
    }
    getch();
}
*/
