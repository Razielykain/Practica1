#ifndef NODOPILA_H
#define NODOPILA_H
#include <iostream>


class NodoPila
{
    public:
        NodoPila();
        NodoPila(Pedido p, NodoPila *sig = NULL);
    ~NodoPila();

    protected:

    private:
        Pedido p;
        NodoPila *siguiente;
        friend class Pila;
};

typedef NodoPila *pnodo;

#endif // NODOPILA_H
