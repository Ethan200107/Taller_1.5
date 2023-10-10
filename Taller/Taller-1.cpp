/*// Taller.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Usuario.h"
#include "UsuarioNino.h"
#include "Admin.h"
#include "UsuarioNorm.h"
#include "Sorftwer.h"
#include "Juego.h"
#include "Navegador.h"
#include "ofmatica.h"
#include "Produccion.h"
#include "Seguridad.h"
#include "social.h"
#include <typeinfo>
#include <sstream>
using namespace std;

vector<Usuario*> lecturaUsuarios();
vector<Sorftwer*> lecturaSoftwares(vector<Usuario*> listaUsuarios);
Usuario* buscarUsuarioP(string nombre, vector<Usuario*> listaUsuarios);

void login(vector<Usuario*> listaUsuarios, vector<Sorftwer*> listaSoftwares);
void MenuAdmin(vector<Sorftwer*> listaSorftwers, vector<Usuario*> listaUsuarios, Usuario* user);
void Menu(vector<Sorftwer*> listaSorftwers, Usuario* user);
void agregarSoftwer(vector<Sorftwer*> listaSorftwers, Usuario* user);
Sorftwer* buscarSorftwerP(string nombre, vector<Sorftwer*> listaSorft);
Sorftwer* eliminarSoftwer(Usuario* user);
void mostrarSoftwer(Usuario* user);
void EliminarElSoftwer(vector<Usuario*> listaUsuarios, vector<Sorftwer*> listaSoftwares);
void verSoftwerUsuarios(vector<Sorftwer*> listaSoft);

// Función principal
int main()
{
    vector <Usuario*>usuarios;
    usuarios = lecturaUsuarios();

	vector <Sorftwer*> softwares;
	softwares = lecturaSoftwares(usuarios);

    login(usuarios,softwares);
};

// Función para realizar el login de usuarios
void login(vector<Usuario*> listaUsuarios, vector<Sorftwer*> listaSoftwares) {
    while (true) {
        string nombre, contrasena;
        cout << "-----------------------------" << endl;
        cout << "Login" << endl;
        cout << "-----------------------------" << endl;
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Contrasena: ";
        cin >> contrasena;
        cout << "-----------------------------" << endl;
        Usuario* user = buscarUsuarioP(nombre, listaUsuarios);
        while (user->getNombre() != nombre or contrasena != user->getContrasena()) {
            cout << "Error de autenticación. Inténtalo de nuevo." << endl;
            string nombre, contrasena;
            cout << "Login" << endl;
            cout << "Nombre: ";
            cin >> nombre;
            cout << "Contrasena: ";
            cin >> contrasena;
            user = buscarUsuarioP(nombre, listaUsuarios);
        }

		string typo = user -> getTipo();



        if (typo == "Admin") {
            cout << "-----------------------------" << endl;
			cout << "Accediendo como administrador" << endl;
            cout << "-----------------------------" << endl;
            MenuAdmin(listaSoftwares, listaUsuarios,user);
        }
        else {
            cout << "-----------------------------" << endl;
			cout << "Accediendo como usuario" << endl;
            cout << "-----------------------------" << endl;
            Menu(listaSoftwares , user);
        }
        cout << "-----------------------------" << endl;
		cout << "1) Ingresar con otro usuario" << endl;
		cout << "2) Salir" << endl;
		cout << "-----------------------------" << endl;
		cout << "Que desea hacer? (ponga un numero)" << endl;
		int op;
		cin >> op;
        if (op == 2) {
			cout << "Saliendo..." << endl;
            break;
        }
    }
}

// Función que muestra el menú para el administrador
void MenuAdmin(vector<Sorftwer*> listaSorftwers, vector<Usuario*> listaUsuarios,Usuario* user) {
    bool very = true;
    while (very) {
        cout << "-----------------------------" << endl;
        cout << "1) agregar softwer a la biblioteca del usuario" << endl;
        cout << "2) eliminar softwer de la biblioteca del usuario" << endl;
        cout << "3) mostrar softwer ocupados por Usuario" << endl;
        cout << "4) Eliminar Softwer del ordenador" << endl;
        cout << "5) ver que softwers tienen los Usuarios" << endl;
        cout << "6) Salir" << endl;
        cout << "-----------------------------" << endl;
        cout << "Que desea hacer? (ponga un numero)" << endl;
        int op;
        cin >> op;
        switch (op) {
        case 1:
            agregarSoftwer(listaSorftwers, user);
            break;
        case 2:
            eliminarSoftwer(user);
            break;
        case 3:
            mostrarSoftwer(user);
            break;
        case 4:
            EliminarElSoftwer(listaUsuarios, listaSorftwers);
            break;
        case 5:
            verSoftwerUsuarios(listaSorftwers);
        case 6:
            cout << "-----------------------------" << endl;
            cout << "Saliendo..." << endl;
            cout << "-----------------------------" << endl;
			very = false;
            break;

		default:
            break;
        }
    }
}

// Función que muestra el menú para usuarios no administradores
void Menu(vector< Sorftwer* > lS, Usuario* user) {
    bool very = true;
    Sorftwer* soft;
    vector< Usuario* > listaU;
    while (very) {
		soft = nullptr;
        cout << "-----------------------------" << endl;
        cout << "1) agregar softwer a la biblioteca del usuario" << endl;
        cout << "2) eliminar softwer de la biblioteca del usuario" << endl;
        cout << "3) mostrar softwer ocupados por Usuario" << endl;
        cout << "4) Eliminar Softwer del ordenador" << endl;
        cout << "5) Salir" << endl;
        cout << "-----------------------------" << endl;
		cout << "Que desea hacer? (ponga un numero)" << endl;
        int op;
        cin >> op;
        vector<Usuario*> listaU;
        switch (op) {
        case 1:
            agregarSoftwer(lS, user);
            break;
        case 2:
            eliminarSoftwer(user);
            break;
        case 3:
            mostrarSoftwer(user);
            break;
        case 4:
			cout << "-----------------------------" << endl;
			cout << "Eliminacion de un software" << endl;
            soft =  eliminarSoftwer(user);
            listaU = soft->getListUsuarios();
            if (listaU.size() == 0) {
				cout << "El software sera eliminado completamente" << endl;
                for (auto it = lS.begin(); it != lS.end(); ++it)
                {
                    if (*it == soft)
                    {
                        lS.erase(it);
                        break;
                    }
                }
                break;
            }
            
            else {
                cout << "Se le preguntara a los demas usuarios para eliminar la eliminacion" << endl;
                break;
            }
           
        case 5:
            cout << "-----------------------------" << endl;
            cout << "Saliendo..." << endl;
            cout << "-----------------------------" << endl;
            very = false;
            break;
        }
    }
}

// Función para ver los softwares de todos los usuarios
void verSoftwerUsuarios(vector<Sorftwer*> listaSoft) {
	cout << "-----------------------------" << endl;
	cout << "VerSoftwerUsuarios" << endl;
	cout << "-----------------------------" << endl;
	for (auto it = listaSoft.begin(); it != listaSoft.end(); ++it)
	{
		(*it)->printAll();
		
        cout << "--------------(Enter para continuar)---------------" << endl;
        cin.ignore();
        
    }
    
}

// Función para eliminar un software de la lista de softwares
void EliminarElSoftwer(vector<Usuario*> listaUsuarios, vector<Sorftwer*> listaSoftwares) {
    cout << "-----------------------------" << endl;
    cout << "EliminarSoftwer" << endl;
    cout << "-----------------------------" << endl;
	vector<Usuario*> newUsuarios;
    vector<Sorftwer*> newSoftwares = listaSoftwares;
    for (int i = 0; i < newSoftwares.size(); i++) {
        cout << newSoftwares[i]->getTipo() << " - " << newSoftwares[i]->getName() << endl;
    }
    cout << "nombre del softwer: ";
    string nombre;
    getline(cin >> ws, nombre);

    Sorftwer* newS = buscarSorftwerP(nombre, newSoftwares);
    if (newS != nullptr) {
		cout << "Borrando SOFTWARE..." << endl;
		newUsuarios = newS->getListUsuarios();
        for (auto it = newSoftwares.begin(); it != newSoftwares.end(); ++it)
        {
            if (*it == newS)
            {
                newSoftwares.erase(it);
                break;
            }
        }
        for (int i = 0; i < newUsuarios.size(); i++) {
			newUsuarios[i]->removeSoftwer(newS);
        }

    }
    else {
        cout << "El softwer no existe" << endl;
    }
	cout << "-----------------------------" << endl;
	
}

// Función para mostrar los softwares de un usuario
void mostrarSoftwer(Usuario* user) {
    vector<Sorftwer*> lS = user->getListSoftwer();
    for (int i = 0; i < lS.size(); i++) {
        cout << lS[i]->getTipo() << " - " << lS[i]->getName() << endl;
    }
}

// Función para eliminar un software de la lista de softwares de un usuario
Sorftwer* eliminarSoftwer(Usuario* user) {

	cout << "-----------------------------" << endl;
	cout << "EliminarSoftwer" << endl;
    vector<Sorftwer*> newSoftwares = user->getListSoftwer();
    for (int i = 0; i < newSoftwares.size(); i++) {
		cout << newSoftwares[i]->getTipo() << " - " << newSoftwares[i]->getName() << endl;
    }
	cout << "nombre del softwer: ";
    string nombre;

    getline(cin >> ws, nombre);

	Sorftwer* newS = buscarSorftwerP(nombre, newSoftwares);
    if (newS != nullptr) {
        if (newS->getTipo == "Ofmatica") {
			ofmatica* ofma = dynamic_cast<ofmatica*>(newS);
			int cant = ofma->getlistaarchivos();
            ofma->setlistaarchivos(cant-1);
        }
        else {
            user->removeSoftwer(newS);
            newS->removeUsuario(user);
            cout << "softwer eliminado..." << endl;
        }
        return newS;

    }
    else {
		cout << "softwer no encontrado..." << endl;
        return nullptr;
    }
    cout << "-----------------------------" << endl;
}

// Función para agregar un software a la lista de softwares de un usuario
void agregarSoftwer(vector<Sorftwer*> listaSorftwers, Usuario* user) {
    cout << "-----------------------------" << endl;
    cout << "agregarSoftwer" << endl;

    vector<Sorftwer*> newSoftwares = user->getListSoftwer();

    for (int i = 0; i < listaSorftwers.size(); i++) {
        bool very = false;
        for (int u = 0; u < newSoftwares.size(); u++) {
            if (listaSorftwers[i] == newSoftwares[u]) {
                very = true;
                break;
            }
        }
        if (very == false and user->getEdad() >= listaSorftwers[i]->getCal_edad()) {
            cout << listaSorftwers[i]->getTipo() << " - " << listaSorftwers[i]->getName() << endl;
        }
    }
    cout << "nombre del softwer: ";
    string nombre;

	getline( cin >> ws , nombre);
    
    Sorftwer* newS = buscarSorftwerP(nombre, listaSorftwers);
    if (newS != nullptr) {
        user->addSoftwer(newS);
        newS->addUsuario(user);
        cout << "softwer agregado..." << endl;
    }
    else {
		cout << "softwer no encontrado..." << endl;
    }
	
    cout << "-----------------------------" << endl;
}

// Función para buscar un software por nombre en una lista de softwares
Sorftwer* buscarSorftwerP(string nombre,vector<Sorftwer*> listaSorft) {
    for (int i = 0; i < listaSorft.size(); i++) {
        if (listaSorft[i]->getName() == nombre) {
            return listaSorft[i];
        }
    }
    return nullptr;
}

// Función para cargar los softwares desde un archivo
vector<Sorftwer*> lecturaSoftwares(vector<Usuario*> listaUsuarios) {
    ifstream archivo("Softwer.txt");
    vector < Sorftwer* > sorftwer;
    if (!archivo)
    {
        cout << "Error al abrir el archivo." << endl;
        return sorftwer;
    }
    string linea;
    while (getline(archivo, linea))
    {
        istringstream iss(linea);
        
        string token;
        
        vector<string> vec;  // Usar un vector dinámico para almacenar los tokens
        
        while (getline(iss, token, ',')) {
            vec.push_back(token);
        }
        
        string tipo;
        
        tipo = vec[0];
        
        string nombre = vec[1], developer=vec[2];
        
        int edad = stoi(vec[3]);
        
        vector< Usuario * > listU;
        
        int cant = stoi(vec[4]);
       
        if (cant == 0) {
			cout << "sofwer sin usuarios (BORRANDO...)" << endl;
            continue;
        }
        Usuario* u;
        int i;
        
        for (i = 5;i < 5 + cant;i++) {
			string nombre = vec[i];
			u = buscarUsuarioP(nombre,listaUsuarios);
			if (u != nullptr) {
				listU.push_back(u);
                
			}
        }
        
        cant = cant + 5;
        int precio = stoi(vec[cant]);
        Sorftwer* sorf{};
        if (tipo == "Juego") {
            string clasJuego[50];
            int u = 0;
            for (int i = cant + 1; i < vec.size(); i++) {
                clasJuego[u] = vec[i];
                u++;
            }
            sorf = new Juego(nombre,developer,edad,precio,listU,clasJuego);
            
        }
        
        else if (tipo == "Ofimatica") {
            int cantarch = stoi(vec[vec.size() - 1]);
            sorf = new ofmatica(nombre,developer,edad,precio,listU,cantarch);
            
        }
        else if (tipo == "Produccion") {
            string prod = (vec[vec.size() - 1]);
            sorf = new Produccion(nombre, developer, edad, precio, listU, prod);
            
        }
        else if (tipo == "Navegador") {
            string Historial[10];
            int u = 0;
            for (int i = cant + 1; i < vec.size(); i++) {
                Historial[u] = vec[i];
                u++;
                if (u >= 10) {
                    break;
                }
            }
            sorf = new Navegador(nombre, developer, edad, precio, listU, Historial);
            
        }
        else if (tipo == "Seguridad") {
            string malwere = (vec[vec.size() - 1]);
            sorf = new Seguridad(nombre, developer, edad, precio, listU, malwere);
            
        }
        else if (tipo == "Social") {
            Usuario* u1 = buscarUsuarioP(vec[cant],listaUsuarios);
            cant = cant + 3;
            vector<Usuario*> amigos;
            for (int i = cant; i < vec.size(); i++) {
				Usuario* u2 = buscarUsuarioP(vec[i], listaUsuarios);
				amigos.push_back(u2);
            }
            sorf = new social(nombre, developer, edad, precio, listU, u1, amigos);
			
        }
        else {
			cout << "Error al guardar softwer" << endl;
        }
        for (int i = 0; i < listU.size(); i++)
        {
            Usuario* sus = listU[i];
			sus->setSoftwer(sorf);
			
        }
		
		sorftwer.push_back(sorf);
    }
      archivo.close();
      return sorftwer;  
    }

// Función para buscar un usuario por nombre en una lista de usuarios
Usuario* buscarUsuarioP(string nombre, vector<Usuario*> listaUsuarios) {
	for (int i = 0; i < listaUsuarios.size(); i++) {
		if (listaUsuarios[i]->getNombre() == nombre) {
			return listaUsuarios[i];
		}
	}
	return nullptr;
}

// Función para cargar los usuarios desde un archivo
vector<Usuario*> lecturaUsuarios() {
    ifstream archivo("archivoUsuarios.txt");
    vector < Usuario* >usuarios;
    if (!archivo)
    {
        cout << "Error al abrir el archivo." << endl;
        return usuarios;
    }



    string tipo, nombre, contrasena, correo, log_str, linea;

    while (getline(archivo, linea))
    {
        istringstream iss(linea);
        string token;
        string vec[5];
        int i = 0;
        while (getline(iss, token, ' ')) {
            vec[i] = token;
            i++;
        }
        nombre = vec[0];
        contrasena = vec[1];
        int edad = stoi(vec[2]);
        if (vec[4] != "") {
            correo = vec[3];
            bool logeado = (vec[4] == "true");
            Usuario* admin = new Admin(nombre, contrasena, edad, correo, logeado);
            usuarios.push_back(admin);
        }
        else if (vec[3] != "") {
            correo = vec[3];
            Usuario* normal = new UsuarioNorm(nombre, contrasena, edad, correo);
            usuarios.push_back(normal);
        }
        else if (vec[2] != "") {
            Usuario* niño = new UsuarioNino(nombre, contrasena, edad);
            usuarios.push_back(niño);
        }

    }


    archivo.close();
    return usuarios;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
*/