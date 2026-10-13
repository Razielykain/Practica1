#ifndef PIZZERIA_H
#define PIZZERIA_H

#include <iostream>
#include <string>
#include "Cola.h"

#define PROB_PERSONALIZACION 20
#define ZONAS 4
#define N_PEDIDOS_PASO 10

using namespace std;

// Declaraciones de funciones
class Pizzeria
{
public:
    Pizzeria();
    virtual ~Pizzeria();
    Pedido generador(int cliente);
    Cola pedir(Cola &generar);
    void mostrarEstado(Cola &generar, Cola &cocina, Cola &especial, Cola expedicion[]);
    void preparacion(Cola &generar, Cola &cocina, Cola &especial);
    void reparto(Cola &cocina, Cola &especial, Cola expedicion[]);
    void tick(Cola &generar, Cola &cocina, Cola &especial, Cola expedicion[]);
};


#endif // FUNCIONES_H
