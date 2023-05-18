//#include "Nodo.h"
#include "Pasajeros.h"
#include <string.h>

Nodo::Nodo()
{
    dato;
    siguiente=nullptr;
    anterior=nullptr;
}

Nodo::~Nodo()
{
}

Nodo::Nodo(const Nodo*)
{
    dato;
    siguiente=nullptr;
    anterior=nullptr;
}
