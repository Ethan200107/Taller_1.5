#pragma once
#include <string>
#include <vector>
#include "Sorftwer.h"
using namespace std;
class Sorftwer;
class Usuario {

private:
    string nombre;
    string contrasena;
    int edad;
    vector<Sorftwer* > listSoftwer;
public:
    
    Usuario(string nombre, string contrasena, int edad);
    ~Usuario();
    
    string getNombre() const;
    
    void setNombre(string nombre);
    
    string getContrasena() const;
    
    void setContrasena(string contrasena);
    
    int getEdad() const;
    
    void setEdad(int edad);
    void imprimirDatos() const;
	void addSoftwer(Sorftwer* softwer);
	
    vector<Sorftwer*> getListSoftwer() const;
	
    void setListSoftwer(vector<Sorftwer*> listSoftwer);
	void removeSoftwer(Sorftwer* softwer);
	void setSoftwer(Sorftwer* softwer);

    virtual string getTipo() const = 0;

};