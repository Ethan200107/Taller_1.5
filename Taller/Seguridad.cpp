#include "Seguridad.h"

Seguridad::Seguridad(string name, string developer, int edad, int precio, vector<Usuario*> listU, string malware) : Sorftwer(name, developer, edad, precio, listU) {
    this->malware = malware;
}

Seguridad::~Seguridad() {
}

void Seguridad::setMalware(string malware) {
    this->malware = malware;
}

string Seguridad::getMalware() {
    return malware;
}

string Seguridad::mostrar() {
   return "Nombre del software: " + getName() + "\nMalware asociado: " + malware;
}
