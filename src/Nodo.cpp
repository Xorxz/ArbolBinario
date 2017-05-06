#include "Nodo.h"

Nodo::Nodo(int Dato)
{
	this->Dato = Dato;
}

Nodo::Nodo(int Dato,Nodo *Padre)
{
	this->Dato = Dato;
	this->Padre = Padre;
}

int Nodo::getDato()
{
	return this->Dato;
}