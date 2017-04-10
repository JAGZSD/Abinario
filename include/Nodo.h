#include <iostream>

class Nodo{
public:
  
	Nodo *Padre,*Izq,*Der;
	int Dato;
	Nodo(int Dato);
	Nodo(int Dato, Nodo *Padre);
	
};