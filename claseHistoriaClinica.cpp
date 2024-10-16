#ifndef CLASE_HISTORIA_CLINICA_H 
#define CLASE_HISTORIA_CLINICA_H

#include <iostream>
#include <string>
#include "claseFecha.cpp"

using namespace std;

struct HistoriaClinica {
    string idHistoria;
    string idCliente;
    string idUnicoveterinario; 
    string fecha;
    float costoProcedimiento;
    string descripcionProcedimiento;
};

struct NodoHistoria {
    HistoriaClinica historia;
    NodoHistoria* siguiente; 
};

struct ListaHistorias {
    NodoHistoria* cabeza; 
};

ListaHistorias* crearLista() {
    ListaHistorias* lista = new ListaHistorias;
    lista->cabeza = NULL; 
    return lista;
}

void crearHistoriaClinica(ListaHistorias* lista, HistoriaClinica nuevaHistoria, NodoHistoria* nuevoNodo) {

    cout << "Ingrese el ID de la historia clinica: ";
    cin >> nuevaHistoria.idHistoria;

    cout << "Ingrese el id del cliente:" << endl;
    cin >> nuevaHistoria.idCliente;

    cout << "Ingrese el identificador del veterinario:" << endl;
    cin >> nuevaHistoria.idUnicoveterinario;

    cout << "Ingrese la fecha de la cita (DD/MM/AAAA): ";
    getline(cin, nuevaHistoria.fecha);

    cout << "Ingrese el costo del procedimiento: ";
    cin >> nuevaHistoria.costoProcedimiento;

    cout << "Ingrese la descripcion del procedimiento: ";
    cin.ignore(); 
    getline(cin, nuevaHistoria.descripcionProcedimiento);

    nuevoNodo->historia = nuevaHistoria;
    nuevoNodo->siguiente = lista->cabeza;
    lista->cabeza = nuevoNodo; 

    cout << "Historia clinica creada con exito." << endl;
}

void mostrarHistoriaClinica(HistoriaClinica historia) {
    cout << "----- Historia Clinica -----" << endl;
    cout << "ID de Historia: " << historia.idHistoria << endl;

    cout << "Identifiacion del Cliente:" << historia.idCliente << endl;

    cout << "ID del Veterinario: " << historia.idUnicoveterinario << endl; 

    cout << "Fecha del Procedimiento: " << historia.fecha << endl;

    cout << "Costo del Procedimiento: " << historia.costoProcedimiento << endl;
    cout << "Descripcion del Procedimiento: " << historia.descripcionProcedimiento << endl;

    cout << "----------------------------" << endl;
}

void mostrarHistoriasClinicas(ListaHistorias* lista) {
    if (lista->cabeza == NULL) {
        cout << "No hay historias clinicas disponibles." << endl;
    } else {
        NodoHistoria* actual = lista->cabeza;
        while (actual != NULL) {
            mostrarHistoriaClinica(actual->historia); 
            actual = actual->siguiente; 
        }
    }
}

void actualizarHistoriaClinica(ListaHistorias* lista, const string& id) {
    NodoHistoria* actual = lista->cabeza;
    bool encontrado = false;

    while (actual != NULL) {
        if (actual->historia.idHistoria == id) {
            encontrado = true; 
            cout << "Actualizando historia clinica con ID: " << id << endl;
            cout << "Ingrese nuevo id del cliente:" << endl;
            cin >> actual->historia.idCliente;
            
            cout << "Ingrese nuevo identificador del veterinario:" << endl;
            cin >> actual->historia.idUnicoveterinario;

            cout << "Ingrese nueva fecha del procedimiento:" << endl;
            cin >> actual->historia.fecha;

            cout << "Ingrese nuevo costo del procedimiento: ";
            cin >> actual->historia.costoProcedimiento;

            cout << "Ingrese nueva descripcion del procedimiento: ";
            cin.ignore(); 
            getline(cin, actual->historia.descripcionProcedimiento);

            cout << "Historia clinica actualizada con exito." << endl;
        }
        actual = actual->siguiente;
    }

    if (!encontrado) {
        cout << "No se encontro la historia clinica con ID: " << id << endl;
    }
}

void eliminarHistoriaClinica(ListaHistorias* lista, const string& id) {
    NodoHistoria* actual = lista->cabeza;
    NodoHistoria* anterior = NULL;
    bool encontrado = false;

    while (actual != NULL) {
        if (actual->historia.idHistoria == id) {
            encontrado = true;
            if (anterior == NULL) {
                lista->cabeza = actual->siguiente; 
            } else {
                anterior->siguiente = actual->siguiente;
            }
            delete actual; 
        } else {
            anterior = actual;
        }
        actual = actual->siguiente; 
    }

    if (!encontrado) {
        cout << "No se encontro la historia clinica con ID: " << id << endl;
    } else {
        cout << "Historia clinica eliminada con exito." << endl;
    }
}

void eliminarLista(ListaHistorias* lista) {
    NodoHistoria* actual = lista->cabeza;
    while (actual != NULL) {
        NodoHistoria* siguiente = actual->siguiente; 
        delete actual;
        actual = siguiente; 
    }
    delete lista; 
}

#endif