#pragma once
#include "Usuario.h"
using namespace std;

class UsuarioNorm :public Usuario
{
private:
	string correo;
public:
	UsuarioNorm(const string& nombre, const string& contrasena, int edad, const string& correo);
	~UsuarioNorm();
	string getCorreo() const;
	void setCorreo(const string& correo);
	string getTipo() const override;
};