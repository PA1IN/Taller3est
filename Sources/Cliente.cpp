#include "Cliente.h"

Cliente::Cliente(string nombre, string rut){

    this -> nombre = nombre;
    this -> rut = rut;   
}

Cliente::~Cliente(){}

string Cliente::getNombre()
{
    return nombre;
}

string Cliente::getRut()
{
    return rut;
}

void Cliente::mostrar()
{
    cout<<"Nombre: " << nombre <<", Rut: " << rut << endl;
}