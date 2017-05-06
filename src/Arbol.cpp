#include "Arbol.h"

Arbol::Arbol(int Dato)
{
	this->Raiz = new Nodo(Dato);
}

bool Arbol::AddNodo(int Dato)
{
	if (BuscarRef(Dato) != NULL)
	{
		return true;
	}
	return AddRec(Dato,Raiz);
}

bool Arbol::AddRec(int Dato,Nodo *aux)
{
	bool Res;
	if (Dato < aux->getDato())
	{
		if (aux->Hizq != NULL)
		{
			Res = AddRec(Dato,aux->Hizq);
		}
		else
		{
			Nodo *n = new Nodo(Dato,aux);
			aux->Hizq = n;
			return true;
		}
	}
	else
	{
		if (aux->Hder != NULL)
		{
			Res = AddRec(Dato,aux->Hder);
		}
		else
		{
			Nodo *n = new Nodo(Dato,aux);
			aux->Hder = n;
			return true;
		}
	}
	return Res;
}

void Arbol::intercambiar(Nodo *a,Nodo *aux)
{
	a->Padre->Hder = NULL;
	a->Padre = aux->Padre;
	a->Hder = aux->Hder;
	a->Hizq = aux->Hizq;
	aux->Hizq->Padre = a;
	aux->Hder->Padre = a;
	aux->Padre = a;
	aux->Hder = NULL;
	aux->Hizq = NULL;
	aux->Padre = NULL;
}

bool Arbol::EliminarRef(int ref)
{
	Nodo *aux = BuscarRef(ref);
	if (aux == NULL)
	{
		return false;
	}
	if (aux->Hizq == NULL && aux->Hder == NULL)
	{
		if (aux->Padre->Hizq == aux)
		{
			aux->Padre->Hizq = NULL;
		}
		else
		{
			aux->Padre->Hder = NULL;
		}
		aux->Padre = NULL;
	}
	if (aux->Hizq != NULL)
	{
		if (aux->Hizq->Hder == NULL)
		{
			aux->Padre->Hder = aux->Hizq;
			aux->Hizq->Padre = aux->Padre;
			aux->Padre = NULL;
			aux->Hizq->Hder = aux->Hder;
			aux->Hder->Padre = aux->Hizq;
			aux->Hder = NULL;
			aux->Hizq = NULL;
		}
	}
	else
	{
		Nodo *a = aux->Hizq->Hder;
		while(a->Hder != NULL)
		{
			a = a->Hder;
		}
		if (a->Hizq != NULL)
		{
			a->Hizq->Padre = a->Padre;
			a->Padre->Hder = a->Hizq;
			a->Hizq = NULL;
		}
		intercambiar(a,aux);
	}
}

Nodo *Arbol::BuscarRef(int ref)
{
		if (Raiz == NULL)
		{
			return NULL;
		}
		return BusqRec(ref,Raiz);
}

Nodo *Arbol::BusqRec(int ref,Nodo *aux){
	Nodo *Busqueda = aux;
	Nodo *Res;
	if (Busqueda->getDato() == ref)
	{
		return Busqueda;
	}
	if (Busqueda->Hder == NULL && Busqueda->Hizq == NULL)
	{
		return NULL;
	}
	if (ref < Busqueda->getDato() && Busqueda->Hizq != NULL)
	{
		Res = BusqRec(ref,Busqueda->Hizq);
	}
	else
	{
		if (ref > Busqueda->getDato() && Busqueda->Hder != NULL)
		{
			Res = BusqRec(ref,Busqueda->Hder);
		}
	}
	if (Res != NULL)
	{
		return Res;
	}
	return NULL;
}

void Arbol::LadoIzq(Nodo *aux)
{
	while(aux->Hizq != NULL)
	{
		std::cout<<aux->Hizq->getDato()<<std::endl;
		aux = aux->Hizq;
	}
}

void Arbol::LadoDer(Nodo *aux)
{

	std::cout<<"\t"<<" ";
	while(aux->Hder != NULL)
	{
		std::cout<<"\t"<<" ";
		std::cout<<aux->Hder->getDato()<<std::endl;
		aux = aux->Hder;
	}
}

void Arbol::ShowA()
{
	AddNodo(9);
	AddNodo(10);
	AddNodo(2);
	AddNodo(5);
	AddNodo(8);
	AddNodo(12);
	AddNodo(7);
	AddNodo(11);	
	AddNodo(20);
	AddNodo(19);
	AddNodo(18);
}

void Arbol::imprime()
{
		
	if (Raiz == NULL)
	{
		std::cout<<"no está el elemento"<<std::endl;
	}
	
	std::cout<<Raiz->getDato()<<std::endl;
	return imprimeRec(Raiz);

}

void Arbol::imprimeRec(Nodo *aux)
{
	Nodo *Busqueda=aux;
	
	if (Busqueda->Hder == NULL && Busqueda->Hizq == NULL)
	{
		std::cout<<"solamente raiz existente"<<std::endl;
	}
	if (Busqueda->Hizq != NULL)
	{
		while(Busqueda->Hizq != NULL)
		{
		LadoIzq(Busqueda->Hizq);
		LadoDer(Busqueda->Hizq);
		Busqueda = Busqueda->Hizq;
		}
	}
	else
	{
		if (Busqueda->Hder != NULL)
		{
			while(Busqueda->Hder != NULL)
			{
			LadoIzq(Busqueda->Hder);
			LadoDer(Busqueda->Hder);
			Busqueda = Busqueda->Hder;
			}
		}
	}

}