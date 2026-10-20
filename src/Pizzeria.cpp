#include "Pizzeria.h"
#include "Pedido.cpp"
Pizzeria::Pizzeria()
{
    //ctor
}

Pizzeria::~Pizzeria()
{
    //dtor
}

Pedido Pizzeria::generador(int cliente)
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

Cola Pizzeria::pedir(Cola &generar)
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

void Pizzeria::mostrarEstado(Cola &generar, Cola &cocina, Cola &especial, Cola expedicion[])
{
    cout << "Generar:" << endl;
    generar.mostrarCola();
    cout << "Cocina:" << endl;
    cocina.mostrarCola();
    cout << "Especial:" << endl;
    especial.mostrarCola();
    for (int i = 0; i < ZONAS; i++)
    {
        cout << "Expedicion - Zona " << i+1 << ":" << endl;
        expedicion[i].mostrarCola();
    }
}

void Pizzeria::preparacion(Cola &generar, Cola &cocina, Cola &especial)
{
    // generar -> cocina/especial
    int i = 0;
    while ((!generar.es_vacia()) && (i < N_PEDIDOS_PASO))
    {
        Pedido p = generar.desencolar();
        if (p.personalizada)
        {
            especial.encolar(p);
            p.estado = "Especial";
        }
        else
        {
            cocina.encolar(p);
            p.estado = "Cocina";
        }
        i++;
    }
}

void Pizzeria::preparacionEspecial(Cola &especial, Cola &cocina)
{
    // especial -> cocina
    int i = 0;
    while ((!especial.es_vacia()) && (i < N_PEDIDOS_PASO))
    {
        Pedido p = especial.desencolar();
        cocina.encolar(p);
        p.estado = "Cocina";
        i++;
    }
}

void Pizzeria::reparto(Cola &cocina, Cola &especial, Cola expedicion[])
{
    // cocina/especial -> expedicion
    int i = 0;
    while (!cocina.es_vacia() && (i < N_PEDIDOS_PASO))
    {
        Pedido p = cocina.desencolar();
        expedicion[p.zona_reparto].encolar(p);
        p.estado = "Expedicion" + zonaToString(p.zona_reparto);
        i++;
    }
}

void Pizzeria::tick(Cola &generar, Cola &cocina, Cola &especial, Cola expedicion[])
{   // Jimenez yams
    reparto(cocina, especial, expedicion);
    preparacionEspecial(especial, cocina);
    preparacion(generar, cocina, especial);
}

