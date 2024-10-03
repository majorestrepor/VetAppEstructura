#include <iostream>
#include <string>

using namespace std;

class Veterinario {
private:
    string nombre;
    string apellido;
    string especialidad;
    
public:
    Veterinario(string nombre, string apellido, string especialidad) : nombre(nombre), apellido(apellido), especialidad(especialidad) {}
    
    string getNombre() const { return nombre; }
    string getApellido() const { return apellido; }
    string getEspecialidad() const { return especialidad; }
};

