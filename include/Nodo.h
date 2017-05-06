#include <iostream>

class Nodo
{
public:
	int Dato;
	Nodo *Padre;
	Nodo *Hizq;
	Nodo *Hder;
	int getDato();
	Nodo(int Dato);
	Nodo(int Dato,Nodo *Padre);
};