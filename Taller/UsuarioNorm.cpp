#include "UsuarioNorm.h"
#include <iostream>
using namespace std;


UsuarioNorm::UsuarioNorm(const string& nombre, const string& contrasena, int edad, const string& correo)
    : Usuario(nombre, contrasena, edad), correo(correo) {};

UsuarioNorm::~UsuarioNorm() {}

string UsuarioNorm::getCorreo() const {
    return correo;
};

void UsuarioNorm::setCorreo(const string& correo) {
    this->correo = correo;
}

string UsuarioNorm::getTipo() const
{
    return "Normal";
}
