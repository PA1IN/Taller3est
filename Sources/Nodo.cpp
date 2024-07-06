#include "Nodo.h"

Nodo::Nodo(Transaccion* trans){

    this -> transaccion = trans;
    this -> hijoDer = nullptr;
    this -> hijoIzq = nullptr;

}

Nodo::~Nodo() {delete transaccion;};