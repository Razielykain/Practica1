#ifndef COLA_H
#define COLA_H
#include "NodoCola.h"
#include "Pedido.h"
class Cola
{
    public:
        Cola();
        virtual ~Cola();
        void encolar(Pedido elemento);
        Pedido inicio();
        Pedido fin();
        Pedido desencolar();
        bool es_vacia();
        void mostrarCola();
        int get_longitud();

    protected:

    private:
        NodoCola *primero;
        NodoCola *ultimo;
        int longitud;
};

#endif // COLA_H
