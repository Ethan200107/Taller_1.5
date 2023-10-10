#include "social.h"
#include "Usuario.h" // Asegúrate de incluir el archivo de encabezado de Usuario si es necesario.

social::social(string name, string developer, int edad, int precio, vector<Usuario*> listUo, Usuario* usuario, vector<Usuario*> listU) 
    : Sorftwer(name, developer, edad, precio, listUo) {
    this->usuario = usuario;
    listamigos = listU;
}

social::~social() {
    // Destructor
}

void social::obtenerAmigos() {
    // Implementa la lógica para obtener amigos, si es necesario.
}

void social::mostrarAmigos() {
    // Implementa la lógica para mostrar amigos, si es necesario.
}

Usuario* social::getUsuario() {
    return usuario;
}

void social::setUsuario(Usuario* usuario) {
    this->usuario = usuario;
}

void social::addAmigo(Sorftwer* sorftwer) {
    // Implementa la lógica para agregar amigos, si es necesario.
}

void social::removeAmigo(Sorftwer* sorftwer) {
    // Implementa la lógica para eliminar amigos, si es necesario.
}
