#include <iostream>
#include <vector>
#include <fstream> 
#include "claseCita.cpp"
#include "claseVeterinario.cpp"
#include "claseHistoriaClinica.cpp"
#include "claseGestionarUsuario.cpp"
#include "claseGestionarVeterinario.cpp"
#include "claseGestionarHistoriaClinica.cpp"

using namespace std;

vector<Cita> citas;

void guardarCitasEnArchivo() {
    ofstream archivo("citas.txt", ios::trunc); 
    
    if (archivo.is_open()) {
        for (const auto& cita : citas) {
            archivo << cita.getTitulo() << ","
                    << cita.getFecha() << ","
                    << cita.getHora() << ","
                    << cita.getDescripcion() << endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo de citas." << endl;
    }
}

void cargarCitasDesdeArchivo() {
    ifstream archivo("citas.txt");
    string linea, titulo, fecha, hora, descripcion;

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            size_t pos = 0;
            pos = linea.find(',');
            titulo = linea.substr(0, pos);
            linea.erase(0, pos + 1);

            pos = linea.find(',');
            fecha = linea.substr(0, pos);
            linea.erase(0, pos + 1);

            pos = linea.find(',');
            hora = linea.substr(0, pos);
            linea.erase(0, pos + 1);

            descripcion = linea;

            Cita cita(titulo, fecha, hora, descripcion);
            citas.push_back(cita);
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo de citas." << endl;
    }
}

void agendarCita() {
    string titulo, fecha, hora, descripcion;
    cout << "Ingrese el titulo de la cita: ";
    cin.ignore(); 
    getline(cin, titulo);
    cout << "Ingrese la fecha de la cita (DD/MM/AAAA): ";
    getline(cin, fecha);
    cout << "Ingrese la hora de la cita (HH:MM): ";
    getline(cin, hora);
    cout << "Ingrese una descripcion para la cita: ";
    getline(cin, descripcion);

    Cita nuevaCita(titulo, fecha, hora, descripcion);
    citas.push_back(nuevaCita);

    
    guardarCitasEnArchivo();

    cout << "Cita agendada exitosamente!" << endl;
}

void eliminarCita() {
    string titulo;
    cout << "Ingrese el titulo de la cita a eliminar: ";
    cin.ignore();
    getline(cin, titulo);

    bool encontrada = false;
    for (auto it = citas.begin(); it != citas.end(); ++it) {
        if (it->getTitulo() == titulo) {
            citas.erase(it);
            cout << "Cita eliminada exitosamente!" << endl;
            encontrada = true;
            
            guardarCitasEnArchivo();
            break;
        }
    }

    if (!encontrada) {
        cout << "No se encontró una cita con ese título." << endl;
    }
}

void reprogramarCita() {
    string titulo;
    cout << "Ingrese el titulo de la cita a reprogramar: ";
    cin.ignore();
    getline(cin, titulo);

    bool encontrada = false;
    for (auto &cita : citas) {
        if (cita.getTitulo() == titulo) {
            string nuevaFecha, nuevaHora, nuevaDescripcion;
            cout << "Ingrese la nueva fecha (DD/MM/AAAA): ";
            getline(cin, nuevaFecha);
            cout << "Ingrese la nueva hora (HH:MM): ";
            getline(cin, nuevaHora);
            cout << "Ingrese una nueva descripcion: ";
            getline(cin, nuevaDescripcion);

            cita.setFecha(nuevaFecha);
            cita.setHora(nuevaHora);
            cita.setDescripcion(nuevaDescripcion);

            cout << "Cita reprogramada exitosamente!" << endl;
            encontrada = true;

            
            guardarCitasEnArchivo();
            break;
        }
    }

    if (!encontrada) {
        cout << "No se encontró una cita con ese título." << endl;
    }
}

void consultarCita() {
    string titulo;
    cout << "Ingrese el titulo de la cita que desea consultar: ";
    cin.ignore(); 
    getline(cin, titulo);

    bool encontrada = false;
    for (const auto &cita : citas) {
        if (cita.getTitulo() == titulo) {
            cout << "Cita encontrada:" << endl;
            cout << "Fecha: " << cita.getFecha() << endl;
            cout << "Hora: " << cita.getHora() << endl;
            cout << "Descripcion: " << cita.getDescripcion() << endl;
            encontrada = true;
            break;
        }
    }

    if (!encontrada) {
        cout << "No se encontró una cita con ese título." << endl;
    }
}

void gestionarCitas() {
    cargarCitasDesdeArchivo();

    int opcionCita = 0;
    do {
        cout << "------ Gestion de Citas ------" << endl;
        cout << "1. Agendar cita" << endl;
        cout << "2. Eliminar cita" << endl;
        cout << "3. Reprogramar cita" << endl;
        cout << "4. Consultar cita" << endl;
        cout << "5. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionCita;

        switch (opcionCita) {
            case 1:
                agendarCita();
                break;
            case 2:
                eliminarCita();
                break;
            case 3:
                reprogramarCita();
                break;
            case 4:
                consultarCita();  
                break;
            case 5:
                cout << "Volviendo al menu principal..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcionCita != 5);
}

void mostrarMenu() {
    int opcion = 0;
    ListaHistorias* listaHistorias = new ListaHistorias();
    
    do {
        cout << "---------- VETAPP ----------" << endl;
        cout << "1. Gestionar usuarios" << endl;
        cout << "2. Gestionar citas" << endl;
        cout << "3. Gestionar historial Clinico" << endl;
        cout << "4. Gestionar veterinarios" << endl;
        cout << "5. Salir" << endl;
        cout << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Opcion 1: Gestionar usuarios" << endl;
                mostrarMenuUsuario();
                break;
            case 2:
                gestionarCitas();  
                break;
            case 3:
                cout << "Opcion 3: Historial Clinico" << endl;
                mostrarMenuHistoriaClinica(listaHistorias);
                break;
            case 4: 
            	cout << "Opcion 4: Veterinario..." << endl; 
                mostrarMenuVeterinario();
				break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida. Por favor, intente de nuevo." << endl;
        }
    } while (opcion != 5);
}

