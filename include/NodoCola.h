#ifndef NODOCOLA_H
#define NODOCOLA_H
#include <iostream>
#include "Pedido.h"
class NodoCola
{
    friend class Cola;
    friend class Pila;
    public:
        NodoCola();
        NodoCola(Pedido e, NodoCola*sig = NULL);
        virtual ~NodoCola();
        string tpToString(TipoPizza tp);
        string zonaToString(ZonaReparto z);

    protected:

    private:
        NodoCola *siguiente;
        Pedido elemento;
};

#endif // NODOCOLA_H
