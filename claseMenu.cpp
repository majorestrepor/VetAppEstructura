#include <iostream>
#include "clasePersona.cpp"

using namespace std;

int main(int argc, char** argv) {
	
	Persona persona;
	leerPersona(persona);
	imprimirPersona(persona);
	
	return 0;
}