#include "UsuarioNino.h"
#include <string>
using namespace std;


UsuarioNino::UsuarioNino(const string& nombre, const string& contrasena, int edad)
    : Usuario(nombre, contrasena, edad) {};

UsuarioNino::~UsuarioNino() {}

string UsuarioNino::getTipo() const
{
    return "Nino";
}
