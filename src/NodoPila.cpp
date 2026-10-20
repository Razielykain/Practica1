#include "NodoPila.h"

NodoPila::NodoPila()
    {
        valor=0;
        siguiente=NULL;
        //ctor
    }

NodoPila::NodoPila(Pedido p, NodoPila *sig)
    {
        Pedido = p;
        siguiente = sig;
    }

NodoPila::~NodoPila()
    {
        //dtor
    }