#ifndef NODOCOLA_H
#define NODOCOLA_H
#include <iostream>
#include "Pedido.h"
class NodoCola
{
    friend class Cola;
    public:
        NodoCola();
        NodoCola(Pedido e, NodoCola*sig = NULL);
        virtual ~NodoCola();

    protected:

    private:
        NodoCola *siguiente;
        Pedido elemento;
};

#endif // NODOCOLA_H
