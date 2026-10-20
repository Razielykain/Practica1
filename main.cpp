#include <iostream>
#include "Pizzeria.h"
#include "Pila.h"
using namespace std;

int main()
{
    Pizzeria p = Pizzeria();
    Cola generar, cocina, especial, norte, sur, este, oeste = Cola();
    Cola expedicion[ZONAS] = {norte, sur, este, oeste};
    Pila pnorte, psur, peste, poeste = Pila();
    Pila cajas[ZONAS] = {pnorte, psur, peste, poeste};
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
                generar = p.pedir(generar);
                break;
            case 2:
                p.tick(generar, cocina, especial, expedicion, cajas);
                break;
            case 3:
                p.mostrarEstado(generar, cocina, especial, expedicion);
                break;
            case 4:
                
            default: cout << "Opcion no valida." << endl;
        }
    }
    while (!salir);
}
