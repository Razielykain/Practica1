#include "Pedido.h"
#include <String>
using namespace std;

string tpToString(TipoPizza tp)
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

string zonaToString(ZonaReparto z)
{
    switch(z)
    {
        case NORTE: return "Norte";
        case SUR: return "Sur";
        case ESTE: return "Este";
        case OESTE: return "Oeste";
    }
}
