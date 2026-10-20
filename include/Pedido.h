#ifndef PEDIDO_H_INCLUDED
#define PEDIDO_H_INCLUDED
#include <string>
using namespace std;

enum TipoPizza
{
    MARGARITA,
    BARBACOA,
    VEGETAL,
    HAWAIANA,
    ROMANA,
    CUATRO_QUESOS
};

enum ZonaReparto
{
    NORTE,
    SUR,
    ESTE,
    OESTE
};

namespace toStrings
{
    inline std::string tpToString(TipoPizza tp)
    {
        switch(tp)
        {
            case MARGARITA: return "Margarita";
            case BARBACOA: return "Barbacoa";
            case VEGETAL: return "Vegetal";
            case HAWAIANA: return "Hawaiana";
            case ROMANA: return "Romana";
            case CUATRO_QUESOS: return "Cuatro Quesos";
        }
    }

    inline std::string zonaToString(ZonaReparto z)
    {
        switch(z)
        {
            case NORTE: return "Norte";
            case SUR: return "Sur";
            case ESTE: return "Este";
            case OESTE: return "Oeste";
        }
    }
}

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
