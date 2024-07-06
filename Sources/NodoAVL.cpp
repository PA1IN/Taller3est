#include "NodoAVL.h"

NodoAVL::NodoAVL(Transaccion* transaccion)
{
    this -> transaccion = transaccion;
    this -> hijoDer = nullptr;
    this -> hijoIzq = nullptr;
    this -> altura = 1;         // parte de 1 para verificar que este balanceado             

};

NodoAVL::~NodoAVL() {delete transaccion;}; // destructor del nodo