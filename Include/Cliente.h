#pragma once
#include <iostream>
using namespace std;

class Cliente{

private:
    string nombre, rut;
    
public:
    
    Cliente(string,string);
    ~Cliente();

    string getNombre();
    string getRut();
    void mostrar();
};