#ifndef VETERINARIO_H
#define VETERINARIO_H
#include <iostream>
#include <string>
#include "clasePersona.cpp"

using namespace std;

struct Veterinario {
	Persona informacionBasica;
	string idUnicoVeterinario;
};

void imprimirVeterinario(Veterinario veterinario) {
	imprimirPersona(veterinario.informacionBasica);
	cout << "Id unico del veterinario: " << veterinario.idUnicoVeterinario << endl;
}

void leerVeterinario(Veterinario &veterinario) {
	leerPersonaSinMascota(veterinario.informacionBasica);
	veterinario.idUnicoVeterinario = leerValorNumerico("Id unico del Veterinario", 7, 10);
}

#endif
