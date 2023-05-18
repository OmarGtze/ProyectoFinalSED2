#ifndef NODO_H
#define NODO_H
#include "Pasajeros.h"
#include <string.h>

using namespace std;

class Nodo
{
public:
    Nodo();
    Nodo(const Nodo*);
    ~Nodo();

    string dato;
    Nodo *siguiente;
    Nodo *anterior;

    friend class Pasajeros;

};

#endif
