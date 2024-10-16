#include <iostream>
#include <fstream>
#include "clasePersona.cpp"
#include "claseVeterinario.cpp" 

using namespace std;

void guardarVeterinarioEnArchivo(Veterinario veterinario) {
    ofstream archivo("veterinarios.txt", std::ios::app); 
    
    if (archivo.is_open()) {
        archivo << veterinario.informacionBasica.nombre << " "
                << veterinario.informacionBasica.apellido << " "
                << veterinario.informacionBasica.direccion << " "
                << veterinario.informacionBasica.identificacion << " "
                << veterinario.informacionBasica.telefono << " "
                << veterinario.idUnicoVeterinario << endl;
        archivo.close(); 
        cout << "Veterinario guardado con éxito." << endl;
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

void agregarVeterinario() {
    Veterinario veterinario; 
    leerVeterinario(veterinario);
    guardarVeterinarioEnArchivo(veterinario);
}

Veterinario buscarVeterinarioEnArchivo(string idUnicoBuscado) {
    ifstream archivo("veterinarios.txt"); 
    Veterinario veterinario;
    bool encontrado = false;

    if (archivo.is_open()) {
        while (archivo >> veterinario.informacionBasica.nombre 
                       >> veterinario.informacionBasica.apellido
                       >> veterinario.informacionBasica.direccion
                       >> veterinario.informacionBasica.identificacion
                       >> veterinario.informacionBasica.telefono
                       >> veterinario.idUnicoVeterinario) {
            if (veterinario.idUnicoVeterinario == idUnicoBuscado) {
                encontrado = true;
                cout << "Veterinario encontrado: " << endl;
                imprimirVeterinario(veterinario);
                break;
            }
        }
        archivo.close();
        if (!encontrado) {
            cout << "Veterinario con ID " << idUnicoBuscado << " no encontrado." << endl;
        }
    } else {
        cout << "Error al abrir el archivo." << endl;
    }

    return veterinario;
}

void actualizarVeterinarioEnArchivo(string idUnicoBuscado) {
    ifstream archivo("veterinarios.txt");
    ofstream archivoTemp("temp.txt");

    Veterinario veterinario;
    bool encontrado = false;

    if (archivo.is_open() && archivoTemp.is_open()) {
        while (archivo >> veterinario.informacionBasica.nombre 
                       >> veterinario.informacionBasica.apellido
                       >> veterinario.informacionBasica.direccion
                       >> veterinario.informacionBasica.identificacion
                       >> veterinario.informacionBasica.telefono
                       >> veterinario.idUnicoVeterinario) {
            if (veterinario.idUnicoVeterinario == idUnicoBuscado) {
                cout << "Veterinario encontrado. Ingrese los nuevos datos: " << endl;
                leerVeterinario(veterinario); 
                encontrado = true;
            }

            archivoTemp << veterinario.informacionBasica.nombre << " "
                        << veterinario.informacionBasica.apellido << " "
                        << veterinario.informacionBasica.direccion << " "
                        << veterinario.informacionBasica.identificacion << " "
                        << veterinario.informacionBasica.telefono << " "
                        << veterinario.idUnicoVeterinario << endl;
        }
        archivo.close();
        archivoTemp.close();

        remove("veterinarios.txt");
        rename("temp.txt", "veterinarios.txt");

        if (encontrado) {
            cout << "Veterinario actualizado con éxito." << endl;
        } else {
            cout << "Veterinario con ID " << idUnicoBuscado << " no encontrado." << endl;
        }
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

void eliminarVeterinarioEnArchivo(string idUnicoBuscado) {
    ifstream archivo("veterinarios.txt");
    ofstream archivoTemp("temp.txt");
    Veterinario veterinario;
    bool encontrado = false;

    if (archivo.is_open() && archivoTemp.is_open()) {
        while (archivo >> veterinario.informacionBasica.nombre 
                       >> veterinario.informacionBasica.apellido
                       >> veterinario.informacionBasica.direccion
                       >> veterinario.informacionBasica.identificacion
                       >> veterinario.informacionBasica.telefono
                       >> veterinario.idUnicoVeterinario) {
            if (veterinario.idUnicoVeterinario != idUnicoBuscado) {
                archivoTemp << veterinario.informacionBasica.nombre << " "
                            << veterinario.informacionBasica.apellido << " "
                            << veterinario.informacionBasica.direccion << " "
                            << veterinario.informacionBasica.identificacion << " "
                            << veterinario.informacionBasica.telefono << " "
                            << veterinario.idUnicoVeterinario << endl;
            } else {
                encontrado = true;
            }
        }
        archivo.close();
        archivoTemp.close();

        remove("veterinarios.txt");
        rename("temp.txt", "veterinarios.txt");

        if (encontrado) {
            cout << "Veterinario eliminado con éxito." << endl;
        } else {
            cout << "Veterinario con ID " << idUnicoBuscado << " no encontrado." << endl;
        }
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

void mostrarTodosLosVeterinarios() {
    ifstream archivo("veterinarios.txt");
    Veterinario veterinario;

    if (archivo.is_open()) {
        cout << "----- Lista de todos los veterinarios -----" << endl;
        while (archivo >> veterinario.informacionBasica.nombre 
                       >> veterinario.informacionBasica.apellido
                       >> veterinario.informacionBasica.direccion
                       >> veterinario.informacionBasica.identificacion
                       >> veterinario.informacionBasica.telefono
                       >> veterinario.idUnicoVeterinario) {
            imprimirVeterinario(veterinario);
            cout << "-----------------------------------------" << endl;
        }
        archivo.close();
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

void mostrarMenuVeterinario() {
    int opcion = 0;
    string idUnico;

    do {
        cout << "---------- VETAPP: Veterinarios ----------" << endl;
        cout << "1. Agregar veterinario" << endl;
        cout << "2. Actualizar veterinario" << endl;
        cout << "3. Eliminar veterinario" << endl;
        cout << "4. Buscar veterinario" << endl;
        cout << "5. Mostrar todos los veterinarios" << endl;  
        cout << "6. Volver al menu principal" << endl;
        cout << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarVeterinario();
                break;
            case 2:
                cout << "Ingrese el ID único del veterinario a actualizar: ";
                cin >> idUnico;
                actualizarVeterinarioEnArchivo(idUnico);
                break;
            case 3:
                cout << "Ingrese el ID único del veterinario a eliminar: ";
                cin >> idUnico;
                eliminarVeterinarioEnArchivo(idUnico);
                break;
            case 4:
                cout << "Ingrese el ID único del veterinario a buscar: ";
                cin >> idUnico;
                buscarVeterinarioEnArchivo(idUnico);
                break;
            case 5:
                mostrarTodosLosVeterinarios();
                break;
            case 6:
                cout << "Volviendo al menu principal..." << endl;
                break;
            default:
                cout << "Opcion no valida. Por favor, intente de nuevo." << endl;
        }
    } while (opcion != 6);
}

