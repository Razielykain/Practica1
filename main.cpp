#include <iostream>
#include "Cola.h"
#define PROB_PERSONALIZACION 20
#define ZONAS 4
#define N_PEDIDOS_PASO 10
using namespace std;


Pedido generador(int cliente)
{
    Pedido p;
    p.id_pedido = "P" + to_string(rand() % 100000);
    p.id_cliente = cliente;
    p.tipo_pizza = static_cast<TipoPizza>(rand() % 6);
    p.isGrande = rand() % 2;
    p.zona_reparto = static_cast<ZonaReparto>(rand() % 4);
    p.personalizada = (rand() % 100) < PROB_PERSONALIZACION;
    p.estado = "Pendiente";
    return p;
}

Cola pedir(Cola &generar)
{
    int n, id;
    cout << "Cuantos pedidos desea generar? ";
    cin >> n;
    id = 100 + rand() % 901;
    for (int i = 0; i < n; i++)
    {
        Pedido p = generador(id);
        generar.encolar(p);
    }
    return generar;
}

void mostrarEstado(Cola &generar, Cola &cocina, Cola &especial, Cola expedicion[])
{
    cout << "Generar:" << endl;
    generar.mostrarCola();
    cout << "Cocina:" << endl;
    cocina.mostrarCola();
    cout << "Especial:" << endl;
    especial.mostrarCola();
    
    for (int i = 0; i < ZONAS; i++)
    {
        cout << "Expedición - Zona " << i << ":" << endl;
        expedicion[i].mostrarCola();
    }
}
void preparacion(Cola &generar, Cola &cocina, Cola &especial)
{
    // generar -> cocina/especial
    int i = 0;
    do
    {
    Pedido p = generar.desencolar();
        if (p.personalizada)
            especial.encolar(p);
        else
            cocina.encolar(p);
    }
    while ((!generar.es_vacia()) && (i < N_PEDIDOS_PASO));
}
void reparto(Cola &cocina, Cola &especial, Cola expedicion[])
{
    // cocina/especial -> expedicion
    int i = 0;
    do
    {
        Pedido p;
        if (!cocina.es_vacia())
            p = cocina.desencolar();
        else if (!especial.es_vacia())
            p = especial.desencolar();
        expedicion[p.zona_reparto].encolar(p);
    }
    while ((!cocina.es_vacia() || !especial.es_vacia()) && (i < N_PEDIDOS_PASO));
}

void tick(Cola &generar, Cola &cocina, Cola &especial, Cola expedicion[])  
{   // Jimenez yams
    reparto(cocina, especial, expedicion);
    preparacion(generar, cocina, especial);
}

int main()
{
    Cola generar, cocina, especial, norte, sur, este, oeste = Cola();
    Cola expedicion[ZONAS] = {norte, sur, este, oeste};
    bool salir = false;
    do
    {
        int opcion;
        cout << "1. Generar N pedidos" << endl;
        cout << "2. Ejecutar un paso de simulacion" << endl;
        cout << "3. Mostrar estado del sistema" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;
        switch (opcion)
        {
            case 0: 
                salir = true;
                break;
            case 1: 
                generar = pedir(generar);
                break;
            case 2: 
                tick(generar, cocina, especial, expedicion);
                break;
            case 3:
                mostrarEstado(generar, cocina, especial, expedicion);
                break;
            default: cout << "Opcion no valida." << endl;
        }
    }
    while (!salir);
}
