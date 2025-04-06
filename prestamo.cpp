#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Libro {
    int codigo;
    string titulo;
    string autor;
    bool disponible;
};

vector<Libro> biblioteca = {
    {101, "Cien años de soledad", "Gabriel García Márquez", true},
    {102, "1984", "George Orwell", false},
    {103, "El Principito", "Antoine de Saint-Exupéry", true},
    {104, "Don Quijote de la Mancha", "Miguel de Cervantes", false} 
};

void registrarPrestamo() {
    int codigo;
    cout << "\n--- Registrar prestamo ---\n";
    cout << "Codigo del libro: ";
    cin >> codigo;

    for (Libro &libro : biblioteca) {
        if (libro.codigo == codigo) {
            if (libro.disponible) {
                libro.disponible = false;
                cout << "Prestamo registrado exitosamente.\n";
            } else {
                cout << "El libro no esta disponible actualmente.\n";
            }
            return;
        }
    }

    cout << "El libro no existe en la biblioteca.\n";
}

int main() {
    registrarPrestamo();

    cout << "\n--- Estado actual de la biblioteca ---\n";
    for (const Libro &libro : biblioteca) {
        cout << "Codigo: " << libro.codigo
             << ", Titulo: " << libro.titulo
             << ", Disponible: " << (libro.disponible ? "Si" : "No") << endl;
    }

    return 0;
}