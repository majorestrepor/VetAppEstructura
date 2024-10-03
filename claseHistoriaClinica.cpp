#include <iostream>
#include <string>
#include "claseVeterinario.cpp"
#include "claseFecha.cpp"
#include "clasePersona.cpp"
using namespace std;

struct HistoriaClinica {
    string idHistoria;
    Persona cliente;
    Veterinario veterinario;
    fecha fecha;
    float costoProcedimiento;
    string descripcionProcedimiento;
};

void crearHistoriaClinica(HistoriaClinica historia) {
	
    cout << "Ingrese el ID de la historia clinica: ";
    cin >> historia.idHistoria;

    cout << "Ingrese los datos del cliente:" << endl;
    leerPersona(historia.cliente);

    cout << "Ingrese los datos del veterinario:" << endl;
    //leerVeterinario(historia.veterinario);

    cout << "Ingrese la fecha del procedimiento:" << endl;
    crearFecha(historia.fecha);

    cout << "Ingrese el costo del procedimiento: ";
    cin >> historia.costoProcedimiento;

    cout << "Ingrese la descripcion del procedimiento: ";
    cin.ignore(); 
    getline(cin, historia.descripcionProcedimiento);

    cout << "Historia clinica creada con exito." << endl;
}

void mostrarHistoriaClinica(HistoriaClinica historia) {
    cout << "----- Historia Clinica -----" << endl;
    cout << "ID de Historia: " << historia.idHistoria << endl;

    cout << "Datos del Cliente:" << endl;
    imprimirPersona(historia.cliente); 

    cout << "Datos del Veterinario:" << endl;
   // imprimirVeterinario(historia.veterinario); 

    cout << "Fecha del Procedimiento: " << historia.fecha.dia << "/" 
         << historia.fecha.mes << "/" << historia.fecha.year << endl;

    cout << "Costo del Procedimiento: " << historia.costoProcedimiento << endl;
    cout << "Descripcion del Procedimiento: " << historia.descripcionProcedimiento << endl;

    cout << "----------------------------" << endl;
}

void actualizarHistoriaClinica() {
	
}

void eliminarHitoriaClinica() {
	
}