#pragma once
#include "Sorftwer.h"
#include <string>
using namespace std;
class Juego :public Sorftwer
{
private:
	string ListaGenero[50];
public:
	Juego(string name, string developer, int edad, int precio, vector<Usuario*> listU, string ListGenero[]);
	~Juego();
	void setListaGenero(string lista[]);
	string getListaGenero();
	string getTipo() const override {
		return "Juego";
	}
};

