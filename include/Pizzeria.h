#ifndef PIZZERIA_H
#define PIZZERIA_H

#include <iostream>
#include <string>
#include "Cola.h"
#include "Pedido.h"
#include "Pila.h"

#define PROB_PERSONALIZACION 20
#define ZONAS 4
#define N_PEDIDOS_PASO 10
#define CAP_CAJA 6
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
    void preparacionEspecial(Cola &especial, Cola &cocina);
    void preparacion(Cola &generar, Cola &cocina, Cola &especial);
    void reparto(Cola &cocina, Cola &especial, Cola expedicion[]);
    void cajas(Cola expedicion[], Pila cajas[]);
    void tick(Cola &generar, Cola &cocina, Cola &especial, Cola expedicion[], Pila cajas[]);
};


#endif // FUNCIONES_H
