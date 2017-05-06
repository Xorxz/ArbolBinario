#include "Nodo.h"

class Arbol
{
public:
	Nodo *Raiz;
	Arbol(int Dato);
	bool AddNodo(int Dato);
	
	bool AddRec(int Dato,Nodo *aux);
	bool EliminarRef(int ref);
	void intercambiar(Nodo *a,Nodo *aux);

	Nodo* BuscarRef(int ref);
	Nodo* BusqRec(int ref,Nodo *aux);
	
	void LadoIzq(Nodo *aux);
	void LadoDer(Nodo *aux);

	void ShowA();
	void imprime();
	void imprimeRec(Nodo *aux);
	
};