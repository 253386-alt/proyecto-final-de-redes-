#include <iostream> 
#include <cmath>
using namespace std;

  void mostrarMenu();  // Realmente, creo no sirve que este aqui, pero lo dejo por si se tiene que actualizar este codigo en el futuro

/*funcion*/ float verServiciosEstetica(float ingresos1, int totalMascotas) { // Abre el menu de los servicios esteticos
    int opcion;
    float cantidadCompra;
    float servicioBanio = 150;
    float servicioPeluqueria = 200;
    do {
        cout << "\n\n----------------------------------------------------------------";
        cout << "\n1 >> Servicios de Estetica disponibles:";
        cout << "\n(0) REGRESAR";
        cout << "\n(1) Banio: $150";
        cout << "\n(2) Peluqueria: $200";
        cout << "\nOpcion: > ";
        cin >> opcion;
        if (opcion != 0) {
            do {
                cout << "\nCantidad de compras: > ";
                cin >> cantidadCompra;
                if (cantidadCompra > totalMascotas) { // Verifica que no compres mas servicios de las mascotas limites que se pueden atender por dia
                    cout << "No se pueden atender mas mascotas del limite (MAX: 10), quedan " << totalMascotas << " para atender";
                }
            } while (cantidadCompra > totalMascotas);
        }

        if (opcion == 0) {
            cout << "\n\n>> Ha presionado (0), regresando al menu de servicios...";
        }
        else if (opcion == 1) {
            cout << "\n\n>> Ha comprado " << cantidadCompra << " vez/veces el servicio de BANIO. ($" << servicioBanio * cantidadCompra << ")";
            ingresos1 = ingresos1 + (servicioBanio * cantidadCompra);
        }
        else if (opcion == 2) {
            cout << "\n\n>> Ha comprado " << cantidadCompra << " vez/veces el servicio de PELUQUERIA. ($" << servicioPeluqueria * cantidadCompra << ")";
            ingresos1 = ingresos1 + (servicioPeluqueria * cantidadCompra);
        }
        else {
            cout << "\n\n[!] Numero ingresado no valido, intentelo de nuevo.";
        }
    } while (opcion != 0);
    return ingresos1;
}

/*funcion*/  float verServiciosMedicos(float ingresos2, int totalMascotas) { // Abre el menu de los servicios medicos
    int opcion;
    float cantidadCompra;
    float servicioVacunacion = 400;
    float servicioCirugia = 1000;
    do {
        cout << "\n----------------------------------------------------------------";
        cout << "\n2 >> Servicios de Estetica disponibles:";
        cout << "\n(0) REGRESAR";
        cout << "\n(1) Vacunacion: $400";
        cout << "\n(2) Cirugia: $1,000";
        cout << "\nOpcion: > ";
        cin >> opcion;
        if (opcion != 0) { 
            do {
                cout << "\nCantidad de compras: > ";
                cin >> cantidadCompra;
                if (cantidadCompra > totalMascotas) { // Verifica que no compres mas servicios de las mascotas limites que se pueden atender por dia
                    cout << "No se pueden atender mas mascotas del limite (MAX: 10), quedan " << totalMascotas << " para atender";
                }
            } while (cantidadCompra > totalMascotas);
        }

        if (opcion == 0) {
            cout << "\n\n>> Ha presionado (0), regresando al menu de servicios...";
        }
        else if (opcion == 1) {
            cout << "\n\n>> Ha comprado " << cantidadCompra << " vez/veces el servicio de VACUNACION. ($" << servicioVacunacion * cantidadCompra << ")";
            ingresos2 = ingresos2 + (servicioVacunacion * cantidadCompra);
        }
        else if (opcion == 2) {
            cout << "\n\n>> Ha comprado " << cantidadCompra << " vez/veces el servicio de CIRUGIA. ($" << servicioCirugia * cantidadCompra << ")";
            ingresos2 = ingresos2 + (servicioCirugia * cantidadCompra);
        }
        else {
            cout << "\n\n[!] Numero ingresado no valido, intentelo de nuevo.";
        }
    } while (opcion != 0);
    return ingresos2;
}

/*funcion*/  void mostrarMenu() { // Muestra el Menu Principal
    int opcion;
    int totalMascotas = 10;
    float ingresosTotales = 0;
    float ing1Total = 0;
    float ing2Total = 0;
    float total = 0;
    float ingresos1 = 0;
    float ingresos2 = 0;
    do {
        // Imprimir estadisticas de procesos actuales
        cout << "\n\n>> Mascotas aceptadas maximas: " << totalMascotas;
        cout << "\n>> Gasto de la nota de pago actual: " << total;
        cout << "\n>> Opciones: Salir (0), Imprimir nota de pago (1), Ver Servicios (2), Ver Ingresos (8), Reiniciar Contador (9)";
        cout << "\n> ";
        cin >> opcion;
        // AQUI empieza la selectiva de opciones usando IF
        if (opcion == 0) {
            cout << "\n>> Ha presionado (0), saliendo del programa";
        }
        else if (opcion == 1) {
            cout << "\n>> Ha presionado (1),imprimiendo nota de pago... (" << totalMascotas << " mascotas por atender restantes";
            cout << "\nPet Co.";
            cout << "\nAvenida Sur Poniente 1340";
            cout << "\nTUXTLA GTZ, CHIS.";
            cout << "\n\n*** VENTA ***";
            cout << "\nTotal: " << total << endl;
            cout << "--- Servicios" << endl;
            cout << "* Estetica: " << ingresos1 << endl;
            cout << "* Servicios Medicos: " << ingresos2 << endl;

            // Al imprimir la nota de pago, los acumuladores se reinician EXCEPTO los que acumulan el total de ingresos en general, 
            // sino que estos ultimos se actualizan con los valores que se estan a punto de borrar de la memoria
            ingresosTotales = ingresosTotales + total;
            ing1Total = ing1Total + ingresos1;
            ing2Total = ing2Total + ingresos2;
            ingresos1 = 0;
            ingresos2 = 0;
            total = 0;
        }
        else if (opcion == 2) {
            do {
                cout << "\n----------------------------------------------------------------";
                cout << "\n>> Servicios disponibles: Estetica (1), Servicios Medicos (2), SALIR (0)";
                cout << "\n> ";
                cin >> opcion;
                if (opcion == 0) {
                    cout << "\n>> Ha presionado (0), regresando al menu principal...";
                }
                else if (opcion == 1) {
                    ingresos1 = verServiciosEstetica(ingresos1, totalMascotas);
                }
                else if (opcion == 2) {
                    ingresos2 = verServiciosMedicos(ingresos2, totalMascotas);
                }
                else {
                    cout << "\n\n[!] Numero ingresado no valido, intentelo de nuevo.";
                }
            } while (opcion != 0);
            // Actualizar valores al terminar de atender 1 masctoa
            cout << "\n>> Se ha atendido a 1 mascota! (" << totalMascotas << " restante(s) )" << endl;
            totalMascotas = totalMascotas - 1;
            total = ingresos1 + ingresos2;
            opcion = 2;
        }
        else if (opcion == 8) {
            cout << "\n*** INGRESOS DEL DIA ***" << endl;
            cout << "Total: " << ingresosTotales << endl;
            cout << "--- Servicios" << endl;
            cout << "* Estetica: " << ing1Total << endl;
            cout << "* Servicios Medicos: " << ing2Total << endl;
        }
        else if (opcion == 9) {
            do {
                cout << "Que desea reiniciar?: (1) Limite de mascotas a atender (Max: 10), (2) Contador de gasto de la nota actual ($" << total << "), (3) Ingresos del dia" << endl;
                cout << "> ";
                cin >> opcion;
                if (opcion == 1) {
                    cout << ">> Ha presionado (2), reiniciando el contador de mascotas aceptadas maximas";
                    totalMascotas = 10;
                }
                else if (opcion == 2) { // Reinicia solo acumuladores de los ingresos que se van a obtener de 1 solo cliente
                    cout << ">> Ha presionado (2),reiniciando contador";
                    ingresos1 = 0;
                    ingresos2 = 0;
                    total = 0;
                }
                else if (opcion == 3) { // Reinicia solo acumuladores de los ingresos TOTALES de todos los servicios anteriores
                    cout << ">> Ha presionado (3), reiniciando el contador de los ingresos del dia...";
                    ing1Total = 0;
                    ing2Total = 0;
                    ingresosTotales = 0;
                }
                else {
                    cout << "\n\n[!] Numero ingresado no valido, intentelo de nuevo.";
                }
            } while (opcion < 1 && opcion > 2);
            opcion = 9;
        }
        else {
            cout << "\n\n[!] Numero ingresado no valido, intentelo de nuevo.";
        }
    } while (opcion != 0);
}

/*funcion*/  int main() {
    cout << "\nVeterinaria Pet Co.";
    mostrarMenu();
}