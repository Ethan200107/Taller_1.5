#pragma once
#include "Sorftwer.h"
#include <vector>
#include <iostream>
class Usuario;
using namespace std;
class social :public Sorftwer
{
private:
	Usuario* usuario;
	vector < Usuario* > listamigos;
public:
	social(string name, string developer, int edad, int precio, vector<Usuario*> listU,Usuario* usuario,vector< Usuario* > listA);
	~social();
	void obtenerAmigos();
	void mostrarAmigos();
	Usuario* getUsuario();
	void setUsuario(Usuario* usuario);
	void addAmigo(Sorftwer* sorftwer);
	void removeAmigo(Sorftwer* sorftwer);
	string getTipo() const override {
		return "Social";
	}

};

