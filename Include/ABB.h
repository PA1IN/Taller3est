#pragma once
#include "Nodo.h"
#include <queue>

class ABB {
private:
    Nodo* raiz;
    queue<Transaccion*> transaccionesFraudulentas;

    Nodo* insertarRec(Nodo*, Transaccion*);
    Nodo* buscarRec(Nodo*,int);
    void detectarFraudeRec(Nodo*, int);

public:
    ABB();
    ~ABB();

    void insertar(Transaccion*);
    //void inOrden();
    void detectarFraude(int);
    void procesarFraude();
    Transaccion* buscar(int);
    void destruir(Nodo*);

};