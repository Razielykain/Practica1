#include "Pila.h"
#include "NodoCola.h"
#include "Pedido.cpp"
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
        if(esVacia()) 
        {
            cout << "Pila vacia"<<endl;
        }
        else
        {
            cout << "Cima pila: " << cima->elemento.id_pedido << " \t " << cima->elemento.id_cliente << 
            " \t " << tpToString(cima->elemento.tipo_pizza) << " \t " << (cima->elemento.isGrande ? "Grande" : "Mediana") << 
            " \t " << zonaToString(cima->elemento.zona_reparto) << " \t " << (cima->elemento.personalizada ? "Si" : "No") << 
            " \t " << cima->elemento.estado << endl;
        }
    return cima->elemento;
    }