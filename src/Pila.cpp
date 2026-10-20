#include "Pila.h"
#include "NodoCola.h"
#include <iostream>
using namespace std;

Pila::Pila()
    {cima = NULL;}

Pila::~Pila()
    { 
        while(cima) desapilar();
    }

bool Pila::esVacia()
    {
        return cima == NULL; 
    }

void Pila::apilar(Pedido p)
    { 
        NodoCola* nuevo = new NodoCola(p, cima);
        //comienzo de la pila nevo nodo
        cima = nuevo;
}

void Pila::desapilar()
    { 
        NodoCola* nodo; //puntero aux para manipular el nodo
        if(cima)
        {
            nodo = cima;
            cima = nodo->siguiente;
            delete nodo;
        }
    }

Pedido Pila::mostrar()
    { 
        if(esVacia()) {
            cout << "Pila vacia"<<endl;
        }
        else{
            cout << "Cima pila: "<< cima->elemento<<endl;
        }
    return cima->elemento;
    }