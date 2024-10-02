#include <iostream>
#include "clasePersona.cpp"
#include "claseCita.cpp"
#include "claseFecha.cpp"

using namespace std;

void mostrarMenu() {
    int opcion = 0;
    do {
        cout << "---------- VETAPP ----------" << endl;
        cout << "1. Agregar usuario" << endl;
        cout << "2. Actualizar usuario" << endl;
        cout << "3. Eliminar usuario" << endl;
        cout << "4. Buscar usuario" << endl;
        cout << "5. Agendar cita" << endl;
        cout << "6. Agregar fecha" << endl;
        cout << "7. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "Opcion 1: Agregar usuario" << endl;
            	//agregarUsuario();
                break;
            }
            case 2:
                cout << "Opcion 2: Actualizar usuario" << endl;
                break;
            case 3:
                cout << "Opcion 3: Eliminar usuario" << endl;
                break;
            case 4:
                cout << "Opcion 4: Buscar usuario" << endl;
                break;
            case 5:
                cout << "Opcion 5: Agendar cita" << endl;
                break;
            case 6:
                cout << "opcion 7: Agregar fecha " << endl;
                break;
            case 7:
                cout << "Saliendo del programa..." << endl;
            
                break;
            default:
                cout << "Opcion no valida. Por favor, intente de nuevo." << endl;
        }
    } while (opcion != 6);
}

void agregarUsuario() {
	Persona persona; 
    leerPersona(persona);
    imprimirPersona(persona); 
}
