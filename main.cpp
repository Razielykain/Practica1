#include <iostream>
#include "Cola.h"
#define PROB_PERSONALIZACION 20
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

Cola pedir(Cola c)
{
    int n, id;
    cout << "Cuantos pedidos desea generar? ";
    cin >> n;
    id = 100 + rand() % 901;
    for (int i = 0; i < n; i++)
    {
        Pedido p = generador(id);
        c.encolar(p);
    }
    return c;
}

void mostrarPedidos(Cola c)
{
    c.mostrarCola();
}

int main()
{
    Cola c = Cola();
    bool salir = false;
    do
    {
        int opcion;
        cout << "1. Generar N pedidos" << endl;
        cout << "2. Mostrar pedidos" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;
        switch (opcion)
        {
            case 0: 
                salir = true;
                break;
            case 1: 
                c = pedir(c);
                break;
            case 2: 
                mostrarPedidos(c);
                break;
            default: cout << "Opcion no valida." << endl;
        }
    }
    while (!salir);
}
