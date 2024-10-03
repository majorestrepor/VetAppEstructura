#include <iostream>
#include <fstream>
#include "clasePersona.cpp"
#include "claseMascota.cpp"

using namespace std;

void guardarUsuarioEnArchivo(Persona persona) {
    ofstream archivo("usuarios.txt"); 
    
    if (archivo.is_open()) {
        archivo << persona.nombre << " "
                << persona.apellido << " "
                << persona.direccion << " "
                << persona.identificacion << " "
                << persona.telefono << " "
				<< persona.mascota.nombre << " "
				<< persona.mascota.especie << " "
				<< persona.mascota.edad << " "
				<< persona.mascota.peso;  
        archivo.close(); 
        cout << "Usuario guardado con éxito." << endl;
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

void agregarUsuario() {
	Persona persona; 
    leerPersona(persona);
    guardarUsuarioEnArchivo(persona);
}

Persona buscarUsuarioEnArchivo(string identificacionBuscada) {
    ifstream archivo("usuarios.txt"); 
    Persona persona;
    bool encontrado = false;

    if (archivo.is_open()) {
        while (archivo >> persona.nombre >> persona.apellido >> persona.direccion 
                      >> persona.identificacion >> persona.telefono) {
            if (persona.identificacion == identificacionBuscada) {
                encontrado = true;
                cout << "Usuario encontrado: " << endl;
                imprimirPersona(persona);
                break;
            }
        }
        archivo.close(); 
        if (!encontrado) {
            cout << "Usuario con identificacion " << identificacionBuscada << " no encontrado." << endl;
        }
    } else {
        cout << "Error al abrir el archivo." << endl;
    }

    return persona;
}


void actualizarUsuarioEnArchivo(string identificacionBuscada) {
    ifstream archivo("usuarios.txt");
    ofstream archivoTemp("temp.txt"); 

    Persona persona;
    bool encontrado = false;

    if (archivo.is_open() && archivoTemp.is_open()) {
        while (archivo >> persona.nombre >> persona.apellido >> persona.direccion 
                      >> persona.identificacion >> persona.telefono) {
            if (persona.identificacion == identificacionBuscada) {
                cout << "Usuario encontrado. Ingrese los nuevos datos: " << endl;
                leerPersona(persona); 
                encontrado = true;
            }

            archivoTemp << persona.nombre << " "
                << persona.apellido << " "
                << persona.direccion << " "
                << persona.identificacion << " "
                << persona.telefono << " @" << endl; 
        }
        archivo.close();
        archivoTemp.close();

        remove("usuarios.txt");           
        rename("temp.txt", "usuarios.txt"); 

        if (encontrado) {
            cout << "Usuario actualizado con éxito." << endl;
        } else {
            cout << "Usuario con identificacion " << identificacionBuscada << " no encontrado." << endl;
        }
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}



void eliminarUsuarioEnArchivo(string identificacionBuscada) {
    ifstream archivo("usuarios.txt");
    ofstream archivoTemp("temp.txt");
    Persona persona;
    bool encontrado = false;

    if (archivo.is_open() && archivoTemp.is_open()) {
        while (archivo >> persona.nombre >> persona.apellido >> persona.direccion 
                      >> persona.identificacion >> persona.telefono) {
            if (persona.identificacion != identificacionBuscada) {
                archivoTemp << persona.nombre << " "
                            << persona.apellido << " "
                            << persona.direccion << " "
                            << persona.identificacion << " "
                            << persona.telefono << " @" << endl;  
            } else {
                encontrado = true;
            }
        }
        archivo.close();
        archivoTemp.close();

        remove("usuarios.txt");
        rename("temp.txt", "usuarios.txt");

        if (encontrado) {
            cout << "Usuario eliminado con exito." << endl;
        } else {
            cout << "Usuario con identificacion " << identificacionBuscada << " no encontrado." << endl;
        }
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

void mostrarTodosLosUsuarios() {
    ifstream archivo("usuarios.txt"); 
    Persona persona;
    Mascota mascota;

    if (archivo.is_open()) {
        cout << "----- Lista de todos los usuarios -----" << endl;
        while (archivo >> persona.nombre >> persona.apellido >> persona.direccion >> persona.identificacion >> persona.telefono >> mascota.nombre 
		    >> mascota.especie >> mascota.edad >> mascota.peso) {
		               	
            imprimirPersona(persona);
            imprimirMascota(mascota);
            cout << "------------------------------------" << endl;
        }
        archivo.close();
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}


void mostrarMenuUsuario() {
    int opcion = 0;
    string identificacion;

    do {
        cout << "---------- VETAPP ----------" << endl;
        cout << "1. Agregar usuario" << endl;
        cout << "2. Actualizar usuario" << endl;
        cout << "3. Eliminar usuario" << endl;
        cout << "4. Buscar usuario" << endl;
        cout << "5. Mostrar todos los usuarios" << endl;  
        cout << "6. Volver al menu principal" << endl;
        cout << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarUsuario();
                break;
            case 2:
                cout << "Ingrese la identificacion del usuario a actualizar: ";
                cin >> identificacion;
                actualizarUsuarioEnArchivo(identificacion);
                break;
            case 3:
                cout << "Ingrese la identificacion del usuario a eliminar: ";
                cin >> identificacion;
                eliminarUsuarioEnArchivo(identificacion);
                break;
            case 4:
                cout << "Ingrese la identificacion del usuario a buscar: ";
                cin >> identificacion;
                buscarUsuarioEnArchivo(identificacion);
                break;
            case 5:
                mostrarTodosLosUsuarios(); 
                break;
            case 6:
                cout << "Volviendo al menu principal..." << endl;
                break;
            default:
                cout << "Opcion no valida. Por favor, intente de nuevo." << endl;
        }
    } while (opcion != 6);
}