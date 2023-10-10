#include "Usuario.h"
#include "Sorftwer.h"
#include <vector>
#include <iostream>
using namespace std;

Usuario::Usuario(string nombre, string contrasena, int edad)
    : nombre(nombre), contrasena(contrasena), edad(edad) {
}

Usuario::~Usuario() {
}

string Usuario::getNombre() const {
    return nombre;
}

void Usuario::setNombre(string nombre) {
    this->nombre = nombre;
}

string Usuario::getContrasena() const {
    return contrasena;
}

void Usuario::setContrasena(string contrasena) {
    this->contrasena = contrasena;
}

int Usuario::getEdad() const {
    return edad;
}

void Usuario::setEdad(int edad) {
    this->edad = edad;
}

void Usuario::imprimirDatos() const {
    cout << "Nombre: " << nombre << endl;
    cout << "Contraseña: " << contrasena << endl;
    cout << "Edad: " << edad << endl;
    cout << "Lista de Software:" << endl;
    for (Sorftwer* software : listSoftwer) {
        cout << " - " <<software->getTipo() << " - " << software->getName() << endl;
    }
}

void Usuario::addSoftwer(Sorftwer* softwer) {
    listSoftwer.push_back(softwer);
}

vector<Sorftwer*> Usuario::getListSoftwer() const {
    return listSoftwer;
}

void Usuario::setListSoftwer(vector<Sorftwer*> listSoftwer) {
    this->listSoftwer = listSoftwer;
}

void Usuario::removeSoftwer(Sorftwer* softwer)
{
    for (auto it = listSoftwer.begin(); it != listSoftwer.end(); ++it)
    {
        if (*it == softwer)
        {
            listSoftwer.erase(it);
            break;
        }
    }
}

void Usuario::setSoftwer(Sorftwer* soft) {
	listSoftwer.push_back(soft);
}

