#include "Navegador.h"

Navegador::Navegador(string name, string developer, int edad, int precio, vector<Usuario*> listU, string url1[]) : Sorftwer(name, developer, edad, precio,listU) {
    // Inicializar el arreglo de URLs
    for (int i = 0; i < 10; i++) {
        this->url[i] = url1[i];
		
    }
}

Navegador::~Navegador() {
    // Destructor
}

int Navegador::buscarUrl(string url) {
    for (int i = 0; i < 10; i++) {
        if (this->url[i] == url) {
            return i; // Devuelve la posición de la URL si se encuentra.
        }
    }
    return -1; // Devuelve -1 si la URL no se encuentra.
}

string Navegador::getUrl() {
    return url[0]; // Devuelve la primera URL en el arreglo.
}

void Navegador::setUrl(string url[]) {
    for (int i = 0; i < 10; i++) {
        this->url[i] = url[i];
    }
}

bool Navegador::eliminarUrl(string url) {
    int posicion = buscarUrl(url);
    if (posicion != -1) {
        for (int i = posicion; i < 9; i++) {
            this->url[i] = this->url[i + 1];
        }
        this->url[9] = ""; // Vaciamos la última posición.
        return true;
    }
    return false; // Devuelve falso si la URL no se encuentra.
}
