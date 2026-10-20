#include "Pila.h"
#include "NodoCola.h"
#include "Pedido.cpp"
#include <iostream>
using namespace std;

Pila::Pila()
    {cima = NULL; size = 0; sent = 0;}

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
        size++;
    }

void Pila::desapilar()
    { 
        NodoCola* nodo; //puntero aux para manipular el nodo
        if(cima)
        {
            nodo = cima;
            cima = nodo->siguiente;
            delete nodo;
            size--;
        }
    }
int Pila::getSize()
    {
        return size;
    }

int Pila::getSent()
    {
        return sent;
    }

void Pila::send()
    {
        sent++;
    }

    Pedido Pila::cimaPila()
    {  
        return cima->elemento;
    }

void Pila::mostrar()
    { 
        if(esVacia()) 
        {
            cout << "Pila vacia"<<endl;
        }
        else
        {
            cout << "activa: " << getSize() << "/" << CAP_CAJA << "\t enviados: " << getSent() << endl;
        }
    }

    void Pila::mostrarCaja()
    {
        if(esVacia()) 
        {
            cout << "Pila vacia"<<endl;
        }
        else
        {
            NodoCola* aux = cima;
            while(aux != NULL)
            {
                cout << aux->elemento.id_pedido << " - " << toStrings::tpToString(aux->elemento.tipo_pizza) << endl;
                aux = aux->siguiente;
            }
        }
    }