#pragma once
#include "Sorftwer.h"
#include <vector>
#include <string>
using namespace std;
class ofmatica : public Sorftwer
{
private:
	int cantarch;
public:
	ofmatica(string name, string developer, int edad, int precio, vector<Usuario*> listU,int cantarch);
	~ofmatica();
	void setlistaarchivos(int archivos);
	int getlistarchivos();
	string getTipo() const override {
		return "Ofmatica";
	}
};

