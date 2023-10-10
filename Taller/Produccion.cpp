#include "Produccion.h"

Produccion::Produccion(string name, string developer, int edad, int precio, vector<Usuario*> listU, string produccion) : Sorftwer(name, developer, edad, precio, listU) {
    this->produccion = produccion;
}

Produccion::~Produccion() {
    // Destructor
}

string Produccion::getProduccion() {
    return produccion;
}

void Produccion::setProduccion(string produccion) {
    this->produccion = produccion;
}
