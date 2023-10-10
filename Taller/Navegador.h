#pragma once
#include "Sorftwer.h"
#include <string>
using namespace std;
class Navegador:public Sorftwer
{
private :
	string url[10];
public:
	Navegador(string name, string developer, int edad, int precio, vector<Usuario*> listU,string url_[]);
	~Navegador();
	int buscarUrl(string url);
	string getUrl();
	void setUrl(string url[]);
	bool eliminarUrl(string url);
	string getTipo() const override {
		return "Navegador";
	}
};

