#pragma once
#include "Sorftwer.h"
#include <iostream>
#include <string>

using namespace std;
class Produccion:public Sorftwer
{
private:
	string produccion;
public:
	
	Produccion(string name, string developer, int edad, int precio, vector<Usuario*> listU,string produccion);
	~Produccion();
	string getProduccion();
	void setProduccion(string produccion);
	string getTipo() const override {
		return "Produccion";
	}
};

