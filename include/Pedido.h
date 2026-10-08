#ifndef PEDIDO_H_INCLUDED
#define PEDIDO_H_INCLUDED
#include <string>
using namespace std;

enum TipoPizza { 
    MARGARITA, 
    BARBACOA, 
    VEGETAL, 
    HAWAIANA, 
    ROMANA, 
    CUATRO_QUESOS 
};

enum ZonaReparto { 
    NORTE, 
    SUR, 
    ESTE, 
    OESTE 
};

struct Pedido
{
    string id_pedido;
    int id_cliente;
    TipoPizza tipo_pizza;
    bool isGrande;
    ZonaReparto zona_reparto;
    bool personalizada;
    string estado;
};

#endif // PEDIDO_H_INCLUDED
