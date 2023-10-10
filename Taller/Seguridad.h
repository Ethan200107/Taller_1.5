#pragma once
#include "Sorftwer.h"
class Seguridad:public Sorftwer
{
private:
	string malware;
public:
	Seguridad(string name, string developer, int edad, int precio, vector<Usuario*> listU,string malware);
	~Seguridad();
	void setMalware(string malware);
	string getMalware();
	string mostrar();
	string getTipo() const override {
		return "Seguridad";
	}
};

