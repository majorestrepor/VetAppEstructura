#include <iostream>
#include <string>
#include "claseVeterinario.cpp"
#include "claseFecha.cpp"
#include "clasePersona.cpp"
using namespace std;

// Estructura HistoriaClinica
struct HistoriaClinica {
    string idHistoria;
    Persona cliente;
    Veterinario veterinario;
    fecha fecha;
    float costoProcedimiento;
    string descripcionProcedimiento;

    // Constructor
    HistoriaClinica(string id, Persona cliente, Veterinario veterinario, fecha fecha, float costo, string descripcion) {
    idHistoria = id;
    this->cliente = cliente;
    this->veterinario = veterinario;
    this->fecha = fecha;
    costoProcedimiento = costo;
    descripcionProcedimiento = descripcion;
}

    // Método para obtener la descripción del procedimiento
    string getDescripcionProcedimiento() {
        return descripcionProcedimiento;
    }

    // Método para establecer la descripción del procedimiento
    void setDescripcionProcedimiento(string descripcion) {
        descripcionProcedimiento = descripcion;
    }
};




//  int main() {
    
    //PARA ESTA PARTE ES NECESARIO USAR LA CLASE---->Persona cliente;
    
    //PARA ESTA PARTE ES NECESARIO USAR LA CLASE---->Veterinario veterinario;
    
    //PARA ESTA PARTE ES NECESARIO USAR LA CLASE---->Fecha fecha;

    // Crear un objeto de la estructura HistoriaClinica
   // HistoriaClinica historiaClinica("H001", cliente, veterinario, fecha, 100.0, "Procedimiento de cirugía");

    // Obtener la descripción del procedimiento
    //cout << "Descripción del procedimiento: " << historiaClinica.getDescripcionProcedimiento() << endl;

    // Establecer una nueva descripción del procedimiento
    //historiaClinica.setDescripcionProcedimiento("Procedimiento de cirugía con anestesia");

    // Obtener la nueva descripción del procedimiento
   // cout << "Nueva descripción del procedimiento: " << historiaClinica.getDescripcionProcedimiento() << endl;

//  }