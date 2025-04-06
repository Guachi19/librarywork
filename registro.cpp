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

vector<Libro> biblioteca;

void registrarLibro() {
    Libro nuevo;
    cout << "\n--- Registrar libro ---\n";
    cout << "Codigo: ";
    cin >> nuevo.codigo;

    for (const Libro& libro : biblioteca) {
        if (libro.codigo == nuevo.codigo) {
            cout << "Ya existe un libro con ese codigo.\n";
            return;
        }
    }

    cin.ignore(); 
    cout << "Titulo: ";
    getline(cin, nuevo.titulo);
    cout << "Autor: ";
    getline(cin, nuevo.autor);

    nuevo.disponible = true;
    biblioteca.push_back(nuevo);

    cout << "Libro registrado correctamente.\n";
}

void mostrarLibros() {
    cout << "\n--- Libros registrados ---\n";
    if (biblioteca.empty()) {
        cout << "No hay libros registrados.\n";
        return;
    }

    for (const Libro& libro : biblioteca) {
        cout << "Codigo: " << libro.codigo << endl;
        cout << "Titulo: " << libro.titulo << endl;
        cout << "Autor: " << libro.autor << endl;
        cout << "Disponible: " << (libro.disponible ? "Sí" : "No") << endl;
        cout << "-------------------------\n";
    }
}

int main() {
    char continuar;

    do {
        registrarLibro();

        cout << "¿Deseas registrar otro libro? (s/n): ";
        cin >> continuar;
        cin.ignore(); 

    } while (continuar == 's' || continuar == 'S');

    mostrarLibros();

    return 0;
}
