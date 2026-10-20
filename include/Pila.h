#ifndef PILA_H
#define PILA_H
#include "NodoCola.h"

#define CAP_CAJA 6

class Pila
{
    public:
        Pila();
        virtual ~Pila();
        bool esVacia();
        void apilar(Pedido p);
        void desapilar();
        void mostrar();
        Pedido cimaPila();
        int getSize();
        int getSent();
        void send();
        void mostrarCaja();

    protected:

    private:
        NodoCola* cima;
        int size;
        int sent;
};

#endif // PILA_H

