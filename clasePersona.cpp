#include <iostream>
#include "claseMascota.cpp"
using namespace std;

struct Persona {
    string nombre;
    string apellido;
    string direccion;
    Mascota mascota;
    string identificacion;
    string telefono;
};

void imprimirPersona(Persona persona) {
    cout << "Nombre: " << persona.nombre << endl;
    cout << "Apellido: " << persona.apellido << endl;
    cout << "Direccion: " << persona.direccion << endl;
    cout << "Identificacion: " << persona.identificacion << endl;
    cout << "Telefono: " << persona.telefono << endl;
    imprimirMascota(persona.mascota);
}

void leerPersona(Persona &persona) {
    cout << "ingresar nombre: " << endl;
    cin >> persona.nombre;
    cout << "ingresar apellido: " << endl;
    cin >> persona.apellido;
    cout << "ingresar direccion: " << endl;
    cin >> persona.direccion;
    
    persona.mascota = crearMascota(); 
    
    cout << "ingresar identificacion: " << endl;
    cin >> persona.identificacion;
    cout << "ingresar telefono: " << endl;
    cin >> persona.telefono;
}
