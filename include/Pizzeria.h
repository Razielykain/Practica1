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
using namespace std;

// Declaraciones de funciones
class Pizzeria
{
public:
    Pizzeria();
    virtual ~Pizzeria();
    Pedido generador(int cliente);
    Cola pedir(Cola &generar);
    void mostrarEstado(Cola &generar, Cola &cocina, Cola &especial, Cola expedicion[], Pila cajas[]);
    void preparacionEspecial(Cola &especial, Cola &cocina);
    void preparacion(Cola &generar, Cola &cocina, Cola &especial);
    void reparto(Cola &cocina, Cola &especial, Cola expedicion[]);
    void caja(Cola expedicion[], Pila cajas[]);
    void tick(Cola &generar, Cola &cocina, Cola &especial, Cola expedicion[], Pila cajas[]);
    void vaciarCaja(Pila &caja);
    void verCaja(Pila &caja);
    bool retirarPedidoCaja(Pila &caja);
    void actCaja(Pila cajas[], bool rm);
};


#endif // FUNCIONES_H
