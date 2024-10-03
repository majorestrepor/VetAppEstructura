#include <iostream>
#include <string>

using namespace std;

class Cita {
private:
    string titulo;
    string fecha;
    string hora;
    string descripcion;

public:
    Cita() {}

    Cita(string t, string f, string h, string d) 
        : titulo(t), fecha(f), hora(h), descripcion(d) {}

    
    void setTitulo(const string& t) { titulo = t; }
    string getTitulo() const { return titulo; }

    void setFecha(const string& f) { fecha = f; }
    string getFecha() const { return fecha; }

    void setHora(const string& h) { hora = h; }
    string getHora() const { return hora; }

    void setDescripcion(const string& d) { descripcion = d; }
    string getDescripcion() const { return descripcion; }

    
    void imprimirCita() const {
        cout << "Titulo: " << titulo << endl;
        cout << "Fecha: " << fecha << endl;
        cout << "Hora: " << hora << endl;
        cout << "Descripcion: " << descripcion << endl;
    }
};
