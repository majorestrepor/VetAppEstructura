#include <iostream>
#include "claseHistoriaClinica.cpp" 

using namespace std;

void mostrarMenuHistoriaClinica(ListaHistorias* lista) {
    int opcion;
    string id;

    do {
        cout << "---------- VETAPP: Historias Clinicas ----------" << endl;
        cout << "1. Crear historia clinica" << endl;
        cout << "2. Mostrar todas las historias clinicas" << endl;
        cout << "3. Actualizar historia clinica" << endl;
        cout << "4. Eliminar historia clinica" << endl;
        cout << "5. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                HistoriaClinica nuevaHistoria; 
                NodoHistoria* nuevoNodo = new NodoHistoria; 
                crearHistoriaClinica(lista, nuevaHistoria, nuevoNodo);
                break;
            }
            case 2:
                mostrarHistoriasClinicas(lista);
                break;
            case 3:
                cout << "Ingrese el ID de la historia clinica a actualizar: ";
                cin >> id;
                actualizarHistoriaClinica(lista, id);
                break;
            case 4:
                cout << "Ingrese el ID de la historia clinica a eliminar: ";
                cin >> id;
                eliminarHistoriaClinica(lista, id);
                break;
            case 5:
                cout << "Volviendo al menu principal..." << endl;
                break;
            default:
                cout << "Opcion no valida. Por favor, intente de nuevo." << endl;
        }
    } while (opcion != 5);
}