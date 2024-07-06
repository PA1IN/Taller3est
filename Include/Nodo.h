#pragma once
#include <iostream>
#include "Transaccion.h"
using namespace std;


class Nodo{
public:
    Transaccion* transaccion;
    Nodo* hijoIzq;
    Nodo* hijoDer;
    
    Nodo(Transaccion*);
    ~Nodo();
};