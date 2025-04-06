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

void opcionesConsulta() {
    int opcionConsulta;
    cout << "\n--- MENU DE CONSULTAS ---\n";
    cout << "1. Mostrar todos los libros\n";
    cout << "2. Buscar libro por codigo\n";
    cout << "3. Listar libros prestados\n";
    cout << "Selecciona una opcion: ";
    cin >> opcionConsulta;

    switch (opcionConsulta) {
        case 1:
            cout << "\n--- TODOS LOS LIBROS ---\n";
            for (const Libro &libro : biblioteca) {
                cout << "Codigo: " << libro.codigo << ", Titulo: " << libro.titulo
                     << ", Autor: " << libro.autor
                     << ", Disponible: " << (libro.disponible ? "Si" : "No") << endl;
            }
            break;

        case 2: {
            int codigo;
            cout << "Introduce el codigo del libro: ";
            cin >> codigo;
            bool encontrado = false;
            for (const Libro &libro : biblioteca) {
                if (libro.codigo == codigo) {
                    cout << "Titulo: " << libro.titulo << ", Autor: " << libro.autor
                         << ", Disponible: " << (libro.disponible ? "Si" : "No") << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "No se encontro un libro con ese codigo.\n";
            }
            break;
        }

        case 3:
            cout << "\n--- LIBROS PRESTADOS ---\n";
            for (const Libro &libro : biblioteca) {
                if (!libro.disponible) {
                    cout << "Codigo: " << libro.codigo << ", Titulo: " << libro.titulo
                         << ", Autor: " << libro.autor << endl;
                }
            }
            break;

        default:
            cout << "Opcion invalida.\n";
            break;
    }
}

int main() {
    opcionesConsulta();
    return 0;
}
