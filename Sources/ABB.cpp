#include "ABB.h"

ABB::ABB(){

    this -> raiz = nullptr;

}
ABB::~ABB(){
    destruir(raiz);
}

void ABB::insertar(Transaccion* transaccion)
{
    raiz = insertarRec(raiz, transaccion);
}

Nodo* ABB::insertarRec(Nodo* nodo, Transaccion* transaccion){ //ingresa un nodo al árbol de transacciones

    if(raiz == nullptr){
         return new Nodo(transaccion);
    }

    if(transaccion -> getMonto() < nodo -> transaccion -> getMonto()){
        nodo->hijoIzq = insertarRec(nodo->hijoIzq,transaccion);
    }
    else if (transaccion -> getMonto() > nodo -> transaccion -> getMonto()){
        nodo->hijoDer = insertarRec(nodo->hijoDer, transaccion);
    }
    return nodo;
}

void ABB::detectarFraude(int monto_limite)
{
    detectarFraudeRec(raiz,monto_limite);
}

void ABB::detectarFraudeRec(Nodo* nodo, int monto_limite)
{
    if(nodo == nullptr)
    {
        return;
    }

    if(nodo->transaccion->getMonto() > monto_limite)
    {
        nodo->transaccion->mostrar();
        transaccionesFraudulentas.push(nodo->transaccion);
    }

    detectarFraudeRec(nodo->hijoIzq, monto_limite);
    detectarFraudeRec(nodo->hijoDer, monto_limite);
}

void ABB::procesarFraude()
{
    cout << "Procesando transacciones fraudulentas..." << endl;
    while(!transaccionesFraudulentas.empty())
    {
        Transaccion* transaccion = transaccionesFraudulentas.front();
        transaccion->mostrar();
        transaccionesFraudulentas.pop();
    }
}

Transaccion* ABB::buscar(int id)
{
    Nodo* nodo = buscarRec(raiz,id);
    if(nodo != nullptr)
    {
        return nodo->transaccion;
    }
    return nullptr;
}

Nodo* ABB::buscarRec(Nodo* nodo, int id)
{
    if(nodo == nullptr || nodo->transaccion->getID() == id)
    {
        return nodo;
    }
    if(id < nodo->transaccion->getID())
    {
        return buscarRec(nodo->hijoIzq,id);
    }

    return buscarRec(nodo->hijoDer,id);
}

void ABB::destruir(Nodo* nodo)
{
    if(nodo != nullptr)
    {
        destruir(nodo->hijoDer);
        destruir(nodo->hijoDer);
        delete nodo;

    }
}