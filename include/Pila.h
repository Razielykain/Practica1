#ifndef PILA_H
#define PILA_H
#include "NodoCola.h"

class Pila
{
    public:
        Pila();
        ~Pila();
        bool esVacia();
        void apilar(Pedido p);
        void desapilar();
        Pedido mostrar();

    protected:

    private:
        NodoCola* cima;
};

#endif // PILA_H

