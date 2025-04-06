#include <iostream>
#include <vector>
using namespace std;

struct Libro {
    int codigo;
    string titulo;
    string autor;
    bool disponible;
};

vector<Libro> biblioteca;

void registrarLibro();
void registrarPrestamo();
void registrarDevolucion();
void opcionesConsulta();

int main() {
    int opcion;

    do {
        cout << "\n--- MENU DE BIBLIOTECA ---\n";
        cout << "1. Registrar libro\n";
        cout << "2. Registrar prestamo\n";
        cout << "3. Registrar devolucion\n";
        cout << "4. Mostrar todas las opciones\n";
        cout << "0. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarLibro();
                break;
            case 2:
                registrarPrestamo();
                break;
            case 3:
                registrarDevolucion();
                break;
            case 4:
                opcionesConsulta();
                break;
            case 0:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opción inválida. Intenta de nuevo.\n";
        }

    } while (opcion != 0);

    return 0;
}
void registrarLibro() {
    Libro nuevo;
    cout << "\n--- Registrar libro ---\n";
    cout << "Codigo: ";
    cin >> nuevo.codigo;

    for (const Libro & libro : biblioteca) {
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

void registrarDevolucion() {
    int codigo;
    cout << "\n--- Registrar devolucion ---\n";
    cout << "Codigo del libro: ";
    cin >> codigo;

    for (Libro &libro : biblioteca) {
        if (libro.codigo == codigo) {
            if (!libro.disponible) {
                libro.disponible = true;
                cout << "Libro devuelto correctamente.\n";
            } else {
                cout << "El libro ya estaba disponible.\n";
            }
            return;
        }
    }

    cout << "El libro no existe en la biblioteca.\n";
}


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
