#include <iostream>
using namespace std;

struct Mascota {
    string nombre;
    string especie;
    int edad;
    float peso;
};

Mascota crearMascota() {
    Mascota mascota;
    cout << "ingresar nombre de la mascota: " << endl;
    cin >> mascota.nombre;
    cout << "ingresar especie de la mascota: " << endl;
    cin >> mascota.especie;
    cout << "ingresar edad de la mascota: " << endl;
    cin >> mascota.edad;
    cout << "ingresar peso de la mascota: " << endl;
    cin >> mascota.peso;
    
    return mascota;
}

void imprimirMascota(Mascota mascota) {
    cout << "Nombre de la mascota: " << mascota.nombre << endl;
    cout << "Especie de la mascota: " << mascota.especie << endl;
    cout << "Edad de la mascota: " << mascota.edad << endl;
    cout << "Peso de la mascota: " << mascota.peso << endl;
}