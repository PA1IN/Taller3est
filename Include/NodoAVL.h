#pragma once 
#include <iostream>
#include "Transaccion.h"
using namespace std;

class NodoAVL {
public:
    Transaccion* transaccion;
    NodoAVL* hijoIzq;
    NodoAVL* hijoDer;
    int altura;

    NodoAVL(Transaccion*);
    ~NodoAVL();

};