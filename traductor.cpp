#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

const char *nombre_archivo = "archivo.dat";

struct Biblioteca {
    char palabra[50];
    char traduccion[50];
    char funcionalidad[500];
};

// Función para cargar el diccionario desde el archivo
map<string, Biblioteca> cargarDiccionario() {
    map<string, Biblioteca> diccionario;

    ifstream archivo(nombre_archivo, ios::binary);
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo.\n";
        return diccionario;
    }

    Biblioteca biblioteca;
    while (archivo.read(reinterpret_cast<char*>(&biblioteca), sizeof(Biblioteca))) {
        diccionario[biblioteca.palabra] = biblioteca;
    }

    archivo.close();
    return diccionario;
}

// Función para traducir una palabra utilizando el diccionario cargado
void traducirPalabra(const string& palabra, const map<string, Biblioteca>& diccionario) {
    string palabraTraducida = palabra;
    transform(palabraTraducida.begin(), palabraTraducida.end(), palabraTraducida.begin(), ::tolower);

    // Buscar la palabra en el diccionario
    if (diccionario.count(palabraTraducida) > 0) {
        const Biblioteca& info = diccionario.at(palabraTraducida);
        cout << "Traduccion: " << info.traduccion << "\n";
        cout << "Funcionalidad: " << info.funcionalidad << "\n";
    } else {
        cout << "Palabra no encontrada en el diccionario.\n";
    }
}

int main() {
    map<string, Biblioteca> diccionario = cargarDiccionario();

    cout << "Bienvenido al Traductor de C++ a Espanol\n";
    cout << "Ingrese una palabra en C++ para traducir (escriba 'salir' para terminar consultas):\n";

    string entrada;
    while (true) {
        cout << ": ";
        getline(cin, entrada);

        if (entrada == "salir") {
            break;
        }

        traducirPalabra(entrada, diccionario);
        cout << "\n";
    }

    cout << "Hasta luego!\n";
    system("pause");
}