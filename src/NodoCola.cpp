#include "NodoCola.h"
#include "Pedido.h"
NodoCola::NodoCola()
{
    elemento=Pedido();
    siguiente=NULL;
    //constructor por defecto
}

NodoCola::NodoCola(Pedido e, NodoCola*sig)
{
    elemento = e;
    siguiente = sig;
}

NodoCola::~NodoCola()
{
    //dtor
}
