#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Usuario.h"
using namespace std;
class Usuario;
class Sorftwer
{
private:
	string name;
	string developer;
	int cal_edad;
	vector <Usuario*>  listUsuarios;
	int precio;
public:
	Sorftwer(string name,string developer, int edad,int precio,vector<Usuario*> listU);
	~Sorftwer();
	void setName(string);
	void setDeveloper(string);
	string getName();
	string getDeveloper();
	void addUsuario(Usuario*);
	void removeUsuario(Usuario*);
	void print();
	void printAll();
	int getPrecio();
	void setPrecio(int);
	void setCal_edad(int);
	int getCal_edad();
	virtual string getTipo() const = 0;
	vector<Usuario*> getListUsuarios();

};

