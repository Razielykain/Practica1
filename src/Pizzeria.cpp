#include "Pizzeria.h"
#include "Pedido.h"
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

void Pizzeria::mostrarEstado(Cola &generar, Cola &cocina, Cola &especial, Cola expedicion[], Pila cajas[])
{
    cout << "=======GENERAR========" << endl;
    generar.mostrarCola();
    cout << "=======COCINA========" << endl;
    cocina.mostrarCola();
    cout << "=======ESPECIAL========" << endl;
    especial.mostrarCola();
    cout << "=======EXPEDICION========" << endl;
    for (int i = 0; i < ZONAS; i++)
    {
        cout << "Zona " << toStrings::zonaToString(static_cast<ZonaReparto>(i)) << ":" << endl;
        expedicion[i].mostrarCola();
    }
    cout << "=======CAJAS========" << endl;
    int totalEnviados = 0;
    for (int i = 0; i < ZONAS; i++)
    {
        cout << "Zona " << toStrings::zonaToString(static_cast<ZonaReparto>(i)) << " -> ";
        cajas[i].mostrar();
        totalEnviados += cajas[i].getSent();
    }
    cout << "Total enviados: " << totalEnviados << endl;
    cout << "Pedidos enviados o retirados: " << totalEnviados*CAP_CAJA << endl;
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
            p.estado = "Especial";
            especial.encolar(p);
        }
        else
        {
            p.estado = "Cocina";
            cocina.encolar(p);
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
        p.estado = "Cocina";
        cocina.encolar(p);
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
        p.estado = "Expedicion " + toStrings::zonaToString(p.zona_reparto);
        expedicion[p.zona_reparto].encolar(p);
        i++;
    }
}

void Pizzeria::caja(Cola expedicion[], Pila cajas[])
{
    // expedicion -> cajas
    for (int i = 0; i < ZONAS; i++)
    {
        int j = 0;
        if (cajas[i].getSize() >= CAP_CAJA)
        {
            vaciarCaja(cajas[i]);
            cajas[i].send();
        }
        while ((!expedicion[i].es_vacia()) && (j < N_PEDIDOS_PASO) && (cajas[i].getSize() < CAP_CAJA))
        {
            Pedido p = expedicion[i].desencolar();
            p.estado = "Caja " + toStrings::zonaToString(p.zona_reparto);
            cajas[i].apilar(p);
            j++;
        }
    }
}

void Pizzeria::vaciarCaja(Pila &caja)
{
    while (!caja.esVacia())
    {
        caja.desapilar();
    }
}

void Pizzeria::verCaja(Pila &caja)
{
    if (caja.esVacia())
    {
        cout << "La caja esta vacia." << endl;
        return;
    }
    else
    {
        cout << "=======CAJA ACTIVA: ZONA "<< toStrings::zonaToString(static_cast<ZonaReparto>(caja.cimaPila().zona_reparto)) << "========" << endl;
        cout << "(CIMA)" << endl;
        caja.mostrarCaja();
        cout << "(FONDO)" << endl;
    }
}

bool Pizzeria::retirarPedidoCaja(Pila &caja)
{
    if (caja.esVacia())
    {
        cout << "La caja esta vacia." << endl;
        return false;
    }
    else
    {
        string id;
        cout << "Ingrese el ID del pedido a retirar: ";
        cin >> id;
        bool found = false;
        Pila aux;
        while (!caja.esVacia() && !found)
        {
            Pedido p = caja.cimaPila();
            caja.desapilar();
            if (p.id_pedido == id) 
                found = true;
            else
                aux.apilar(p);
        }

        while (!aux.esVacia())
        {
            Pedido p = aux.cimaPila();
            caja.apilar(p);
            aux.desapilar();
        }
        return found;
    }
}

void Pizzeria::actCaja(Pila cajas[], bool rm)
{
    int zona;
    cout << "Ingrese la zona (0: Norte, 1: Sur, 2: Este, 3: Oeste): ";
    cin >> zona;
    if (zona >= 0 && zona < ZONAS)
    {
        if (rm)
            cout << (retirarPedidoCaja(cajas[zona]) ? "Pedido retirado." : "Pedido no encontrado.") << endl;
        else
            verCaja(cajas[zona]);
    }
    else
    {
        cout << "Zona no valida." << endl;
    }
}

void Pizzeria::tick(Cola &generar, Cola &cocina, Cola &especial, Cola expedicion[], Pila cajas[])
{   // Guiseppe yams
    caja(expedicion, cajas);
    reparto(cocina, especial, expedicion);
    preparacionEspecial(especial, cocina);
    preparacion(generar, cocina, especial);
}

