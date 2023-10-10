#include "Sorftwer.h"
#include <iostream>

Sorftwer::Sorftwer(string name, string developer, int edad, int precio, vector<Usuario*> listU)
{
    this->name = name;
    this->developer = developer;
    this->cal_edad = edad;
    this->precio = precio;
	this->listUsuarios = listU;
}

Sorftwer::~Sorftwer()
{
}

void Sorftwer::setName(string newName)
{
    name = newName;
}

void Sorftwer::setDeveloper(string newDeveloper)
{
    developer = newDeveloper;
}

string Sorftwer::getName()
{
    return name;
}

string Sorftwer::getDeveloper()
{
    return developer;
}

void Sorftwer::addUsuario(Usuario* newUser)
{
    listUsuarios.push_back(newUser);
}

void Sorftwer::removeUsuario(Usuario* userToRemove)
{
    for (auto it = listUsuarios.begin(); it != listUsuarios.end(); ++it)
    {
        if (*it == userToRemove)
        {
            listUsuarios.erase(it);
            break;
        }
    }
}

void Sorftwer::print()
{
    cout << "Software Name: " << name << endl;
    cout << "Developer: " << developer << endl;
    cout << "Calidad de Edad: " << cal_edad << endl;
    cout << "Precio: " << precio << endl;
}

void Sorftwer::printAll()
{
    cout << "Software Name: " << name << endl;
    cout << "Developer: " << developer << endl;
    cout << "Calidad de Edad: " << cal_edad << endl;
    cout << "Precio: " << precio << endl;
    cout << "Usuarios ( "<< listUsuarios.size() << ") :" << endl;
    for (Usuario* user : listUsuarios)
    {
        cout << " -> " << user->getNombre() << endl;
    }
}

int Sorftwer::getPrecio()
{
    return precio;
}

void Sorftwer::setPrecio(int newPrecio)
{
    precio = newPrecio;
}

void Sorftwer::setCal_edad(int newCal_edad)
{
    cal_edad = newCal_edad;
}

int Sorftwer::getCal_edad()
{
    return cal_edad;
}

vector<Usuario*> Sorftwer::getListUsuarios()
{
    return listUsuarios;
}

