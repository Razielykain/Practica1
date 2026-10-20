#ifndef PILA_H
#define PILA_H
#include "NodoPila.h"

class Pila
{
    public:
        Pila();
        ~Pila();
        bool esVacia();
        void apilar(int v);
        void desapilar();
        int mostrar();

    protected:

    private:
        pnodo cima;
};

#endif // PILA_H

