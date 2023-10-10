#pragma once
#include "Usuario.h"
using namespace std;
class Admin : public Usuario

{
private:
	string correo;
	bool loge;
public:
	Admin(const string& nombre, const string& contrasena, int edad, const string& correo, bool loge);
	~Admin();
	string getCorreo();
	void setCorreo(const string& correo);
	bool estaLoggeado() ;
	void setLog(bool loge);
	void imprimirDatos() ;
	string getTipo() const override;
};

