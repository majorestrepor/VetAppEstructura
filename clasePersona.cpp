#ifndef CLASE_PERSONA_H 
#define CLASE_PERSONA_H
#include <iostream>
#include <cctype>  
#include <string>
#include "claseMascota.cpp"

using namespace std;

struct Persona {
    string nombre;
    string apellido;
    string direccion;
    string identificacion;
    string telefono;
    Mascota mascota;
};

bool esNumero(string dato) {
    for (char c : dato) {
        if (!isdigit(c)) {
            return false; 
        }
    }
    return true;
}

string leerValorNumerico(string mensaje, int longitudMin, int longitudMax) {
    string valor;
    bool valido = false;
    
    do {
        cout << "ingresar " << mensaje << " (solo numeros) y tener entre " << longitudMin << " y " << longitudMax << " digitos: " << endl;
        cin >> valor;
        valido = esNumero(valor) && valor.length() >= longitudMin && valor.length() <= longitudMax;

        if (!valido) cout << "El valor ingresado debe contener solo numeros y tener entre " << longitudMin << " y " << longitudMax << " digitos. Intentelo de nuevo." << endl;
        
    } while (!valido);

    return valor;
}

void imprimirPersona(Persona persona) {
    cout << "Nombre: " << persona.nombre << endl;
    cout << "Apellido: " << persona.apellido << endl;
    cout << "Direccion: " << persona.direccion << endl;
    cout << "Identificacion: " << persona.identificacion << endl;
    cout << "Telefono: " << persona.telefono << endl;
}

void leerPersona(Persona &persona) {
    cout << "ingresar nombre: " << endl;
    cin >> persona.nombre;
    cout << "ingresar apellido: " << endl;
    cin >> persona.apellido;
    cout << "ingresar direccion: " << endl;
    cin >> persona.direccion;
        
    persona.identificacion = leerValorNumerico("identificacion", 7, 10);
	
    persona.telefono = leerValorNumerico("telefono", 8, 10);
    
    persona.mascota = crearMascota();
}

#endif