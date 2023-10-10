#include "Juego.h"
#include <string>
using namespace std;

// Constructor de Juego
Juego::Juego(string name, string developer, int edad, int precio, vector<Usuario*> listU, string listgenero[])
    : Sorftwer(name, developer, edad, precio,listU) {
    // Inicializa los atributos específicos de Juego aquí, si los tienes
    for (int i = 0; i < 50; i++) {
        ListaGenero[i] = listgenero[i];
    }
}

// Destructor de Juego
Juego::~Juego() {
    // Agrega aquí la lógica de destrucción de objetos específica de Juego si es necesario
}

// Setter para la lista de géneros
void Juego::setListaGenero(string lista[]) {
    for (int i = 0; i < 50; i++) {
        if (!lista[i].empty()) {
            ListaGenero[i] = lista[i];
        }
        else {
            // Termina de copiar cuando encuentres un elemento vacío en la lista
            break;
        }
    }
}

string Juego::getListaGenero() {
    string generos;
    for (int i = 0; i < 50; i++) {
        if (!ListaGenero[i].empty()) {
            if (!generos.empty()) {
                generos += ", ";
            }
            generos += ListaGenero[i];
        }
        else {
            // Termina de copiar cuando encuentres un elemento vacío en la lista
            break;
        }
    }
    return generos;
}
