#include "Arbolbinario.h"

int main()
{
    int n;
    Arbolbinario a(n);
    	std::cout<<"Ingrese un dato:  "<<std::endl;
	std::cin>> n ; 
		std::cout<<"\nDato Introducido:"<<std::endl;
		std::cout<<a.Insertar(n)<<std::endl;
  return 0;
}