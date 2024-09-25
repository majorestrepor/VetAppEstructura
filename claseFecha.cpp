#include <iostream>

using namespace std;

struct fecha {
    int dia;
    int mes;
    int year;
};

bool esBisiesto(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int diasEnMes(int mes, int year) {
    if (mes == 2) {
        if (esBisiesto(year)) {
            return 29;
        } else {
            return 28;
        }
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return 30;
    } else {
        return 31;
    }
}

void crearFecha(fecha &f) {
    cout << "Ingrese el d a (dd): ";
    cin >> f.dia;
    cout << "Ingrese el mes (mm): ";
    cin >> f.mes;
    cout << "Ingrese el a o (aaaa): ";
    cin >> f.year;
    while (f.dia < 1 || f.dia > diasEnMes(f.mes, f.year) ||
        f.mes < 1 || f.mes > 12 ||
        f.year < 1) {
        cout << "Fecha inv lida. Ingrese nuevamente:" << endl;
        crearFecha(f);
    }
}

void editarFecha(fecha &f) {
    cout << "  D a: " << f.dia << endl;
    cout << "  Mes: " << f.mes << endl;
    cout << "  A o: " << f.year << endl;
    cout << "Editar? (s/n): ";
    char resp;
    cin >> resp;
    if (resp == 's') {
        crearFecha(f);
    }
}

void mostrarFecha(fecha f) {
    cout << "  D a: " << f.dia << endl;
    cout << "  Mes: " << f.mes << endl;
    cout << "  A o: " << f.year << endl;
}
