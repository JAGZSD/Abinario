#include "Nodo.h"

class Arbolbinario{
public:
	//Atributos
	Nodo *Raiz;
	//Constructor
	Arbolbinario(int Dato);
	//Metodos
	Nodo *Buscar(int Ref, Nodo *aux);
	Nodo *Insertar(int Ref, Nodo *aux);
	Nodo *NodoDer(Nodo *aux);
	bool Insertar(int Dato);
	bool Eliminar(int Ref);
};