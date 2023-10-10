#pragma once
#include "Usuario.h"
using namespace std;

class UsuarioNino :public Usuario
{
public:
	UsuarioNino(const string& nombre, const string& contrasena, int edad);
	~UsuarioNino();
	string getTipo() const override;
};

