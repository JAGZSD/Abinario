#include "Arbolbinario.h"

Arbolbinario::Arbolbinario(int Dato){
	this->Raiz=new Nodo(Dato);
}

Nodo *Arbolbinario::Buscar(int Ref, Nodo *aux){

    if (aux->Dato==Ref)
      return aux;

    if (aux->Dato<Ref && aux->Der!=NULL)
      return Buscar(Ref,aux->Der);
	else
	  if (aux->Dato>Ref && aux->Izq!=NULL)
	    return Buscar(Ref,aux->Izq);
    return NULL;
}

Nodo *Arbolbinario::Insertar(int Ref,Nodo *aux){

    if (aux->Dato>Ref){
    
    if (aux->Izq==NULL)
      return aux;
    return Insertar(Ref,aux->Izq);  
    }
      else{
	if (aux->Der==NULL)
	  return aux;
	return Insertar(Ref, aux->Der);
      }
}

bool Arbolbinario::Insertar(int Dato){

    if (Buscar(Dato, this->Raiz)!=NULL){
      std::cout<<"Ya existe la referencia"<<std::endl;
      return false;
    }

    Nodo *aux=Insertar(Dato,this->Raiz);
    Nodo *hijo=new Nodo(Dato,aux);

    if (aux->Dato>Dato)
      aux->Izq=hijo;
	else
	  aux->Der=hijo;
    return true;
}


Nodo *Arbolbinario::NodoDer(Nodo *aux){
     if(aux->Der=NULL)
      return NodoDer(aux->Der);
	else 
	  return aux;
}

bool Arbolbinario::Eliminar(int Ref){

    Nodo *aux=Buscar(Ref, this->Raiz);
    if (aux==NULL){
      std::cout<<"No existe la Referencia"<<std::endl;
      return false;
    }

    if (aux->Der==NULL && aux->Izq==NULL){
      if(aux==aux->Padre->Izq)
	aux->Padre->Izq=NULL;
	  else
	      aux->Padre->Der=NULL;
    aux->Padre=NULL;
    return true;
    }

    if (aux->Izq==NULL){
      if(aux==aux->Padre->Izq)
	aux->Padre->Izq=aux->Der;
	  else
	    aux->Padre->Der=aux->Der;
	aux->Der->Padre=aux->Padre;
	aux->Padre=NULL;
	aux->Der=NULL;
    }
    else{
      if (aux->Izq->Der==NULL){
	aux->Izq->Der=aux->Der;
	aux->Izq->Padre=aux->Padre;
	  if(aux==aux->Padre->Izq)
	    aux->Padre->Izq=aux->Izq;
		else
		   aux->Padre->Der=aux->Izq;
	    aux->Der->Padre=aux->Izq;
	    aux->Der=NULL;
	    aux->Izq=NULL;
	    aux->Padre=NULL;
      }
	else{
	  Nodo *aux2=NodoDer(aux->Izq);
	     if (aux2->Izq!=NULL){
		aux2->Izq->Padre=aux2->Padre;
		aux->Padre->Der=aux2->Izq;
	     }
	aux2->Padre=aux->Padre;
	aux->Padre->Der=aux2;
	aux->Izq->Padre=aux2;
	aux2->Izq=aux->Izq;

	    if(aux->Der!=NULL)
	      aux->Der->Padre=aux2;
		if(aux == aux->Padre->Izq)
		  aux->Padre->Izq=aux2;
		else
		  aux->Padre->Der=aux2;
	aux->Der=NULL;
	aux->Izq=NULL;
	aux->Padre=NULL;
	}
     }
}