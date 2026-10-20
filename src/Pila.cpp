#include "Pila.h"
#include "NodoPila.h"
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

void Pila::apilar(int v)
    { 
        pnodo nuevo = new NodoPila(v, cima);
        //comienzo de la pila nevo nodo
        cima = nuevo;
}

void Pila::desapilar()
    { 
        pnodo nodo; //puntero aux para manipular el nodo
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
            cout << "Cima pila: "<< cima->valor<<endl;
        }
    return 0;
    }