#pragma once
#include "NodoAVL.h"

class AVL
{
private:
    NodoAVL* raiz;

    NodoAVL* insertarRec(NodoAVL*, Transaccion*);
    NodoAVL* buscarRec(NodoAVL*, int);
    int altura(NodoAVL*);
    int balancear(NodoAVL*);
    NodoAVL* rotarDer(NodoAVL*);
    NodoAVL* rotarIzq(NodoAVL*);
public:
    AVL();
    ~AVL();

    void insertar(Transaccion*);
    void buscarPorID(int);
    void destruir(NodoAVL*);
};