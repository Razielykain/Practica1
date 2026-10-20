#include "Cola.h"
#include <iostream>
#include "Pedido.h"
using namespace std;



Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
    //ctor
}

Cola::~Cola()
{
    //dtor
}

void Cola::encolar(Pedido elemento)
{
    NodoCola *nuevo_nodo = new NodoCola(elemento);
    if(es_vacia())
        {
            primero = nuevo_nodo;
            ultimo = nuevo_nodo;
        }
        else
        {
            ultimo->siguiente = nuevo_nodo;
            ultimo = nuevo_nodo;
        }
        longitud++;
}
Pedido Cola::desencolar()
{
    if(!es_vacia())
    {
        Pedido elemento = primero->elemento;
        NodoCola *aux = primero;

        if((primero == ultimo) && (primero->siguiente == NULL))
        {
            primero = NULL;
            ultimo = NULL;
            aux->siguiente = NULL;
            delete(aux);
        }
        else
        {
            primero = primero->siguiente;
            aux->siguiente = NULL;
            delete(aux);
        }
        longitud--;;
        return elemento;
    }
}

Pedido Cola::inicio()
{
    if(!es_vacia())
        return primero->elemento;
}

Pedido Cola::fin()
{
    if(!es_vacia())
        return ultimo->elemento;
}

int Cola::get_longitud()
{
    return longitud;
}

bool Cola::es_vacia()
{
    return ((primero==NULL) && (ultimo==NULL));
}

void Cola::mostrarCola()
{
    NodoCola *aux = primero;
    if (es_vacia())
        cout << "Cola vacia: " << endl;
    else
    {
        cout << "Datos de la Cola: "<< endl;
        while (aux)
        {
            cout << aux->elemento.id_pedido << " \t " << aux->elemento.id_cliente <<
            " \t " << toStrings::tpToString(aux->elemento.tipo_pizza) << " \t " << (aux->elemento.isGrande ? "Grande" : "Mediana") <<
            " \t " << toStrings::zonaToString(aux->elemento.zona_reparto) << " \t " << (aux->elemento.personalizada ? "Si" : "No") <<
            " \t " << aux->elemento.estado << endl;
            aux = aux->siguiente;
        }
    }
}
