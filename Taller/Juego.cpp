#include "Juego.h"
#include <string>
using namespace std;

// Constructor de Juego
Juego::Juego(string name, string developer, int edad, int precio, vector<Usuario*> listU, string listgenero[])
    : Sorftwer(name, developer, edad, precio,listU) {
    // Inicializa los atributos espec�ficos de Juego aqu�, si los tienes
    for (int i = 0; i < 50; i++) {
        ListaGenero[i] = listgenero[i];
    }
}

// Destructor de Juego
Juego::~Juego() {
    // Agrega aqu� la l�gica de destrucci�n de objetos espec�fica de Juego si es necesario
}

// Setter para la lista de g�neros
void Juego::setListaGenero(string lista[]) {
    for (int i = 0; i < 50; i++) {
        if (!lista[i].empty()) {
            ListaGenero[i] = lista[i];
        }
        else {
            // Termina de copiar cuando encuentres un elemento vac�o en la lista
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
            // Termina de copiar cuando encuentres un elemento vac�o en la lista
            break;
        }
    }
    return generos;
}
