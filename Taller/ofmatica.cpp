#include "ofmatica.h"

ofmatica::ofmatica(string name, string developer, int edad, int precio, vector<Usuario*> listU,int cantA) : Sorftwer(name, developer, edad, precio,listU) {
	cantarch= cantA;
}

ofmatica::~ofmatica() {
}

void ofmatica::setlistaarchivos(int archivos) {
    cantarch = archivos;
}

int ofmatica::getlistarchivos() {
    return cantarch;
}
