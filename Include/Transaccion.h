#pragma once
#include <iostream>
#include "Cliente.h"
using namespace std;


class Transaccion{
private:
    int id; 
    string cuentaOrigen;
    string cuentaDestino;
    int monto;
    string ubicacion;
    string fecha,hora;

public:

    Transaccion(int,string,string,int,string,string,string);
    ~Transaccion();

    int getID();
    string getCtaOrigen();
    string getCtaDestino();
    int getMonto();
    string getUbicacion();
    string getFecha();
    string getHora();
    void mostrar();
};