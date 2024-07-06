#include "AVL.h"

AVL::AVL()
{
    this -> raiz = nullptr;

}
AVL::~AVL(){
    destruir(raiz);
}

void AVL::insertar(Transaccion* transaccion)
{
    raiz = insertarRec(raiz,transaccion);
}

NodoAVL* AVL::insertarRec(NodoAVL* nodo, Transaccion* transaccion)
{
    if(nodo == nullptr)
    {
        return new NodoAVL(transaccion);
    }
    if(transaccion->getMonto() < nodo->transaccion->getMonto())
    {
        nodo -> hijoIzq = insertarRec(nodo->hijoIzq, transaccion);
    }
    else if(transaccion->getMonto() > nodo->transaccion->getMonto())
    {
        nodo -> hijoDer = insertarRec(nodo->hijoDer, transaccion);
    }

    if(altura(nodo->hijoIzq) > altura(nodo->hijoDer))
    {
        nodo->altura = 1 + altura(nodo-> hijoIzq);
    }
    else
    {
        nodo->altura = 1 + altura(nodo->hijoDer);
    }

    int balance = balancear(nodo); //obtiene el balanceo del nodo padre


    if(balance > 1 && transaccion->getMonto() < nodo->hijoIzq->transaccion->getMonto()) //si hay un desbalanceo LL o izquierda-izquierda
    {
        return rotarDer(nodo);
    }
    if(balance < -1 && transaccion->getMonto() > nodo->hijoDer->transaccion->getMonto()) //si hay un desbalanceo RR o derecha-derecha
    {
        return rotarIzq(nodo);
    }
    if(balance > 1 && transaccion->getMonto() > nodo->hijoDer->transaccion->getMonto()) //si hay un desbalanceo LR o izquierda-derecha
    {
        nodo->hijoIzq = rotarIzq(nodo->hijoDer);
        return rotarDer(nodo);
    }
    if(balance < -1 && transaccion->getMonto() < nodo->hijoDer->transaccion->getMonto()) //si hay un desbalanceo RL o derecha-izquierda
    {
        nodo->hijoDer = rotarDer(nodo->hijoDer);
        return rotarIzq(nodo);
    }
    return nodo;
}

NodoAVL* AVL::buscarRec(NodoAVL* nodo, int id)
{
    if(nodo == nullptr || nodo->transaccion->getID() == id)
    {
        return nodo;
    }
    if(id < nodo->transaccion->getID())
    {
        return buscarRec(nodo->hijoIzq, id);
    }
    return buscarRec(nodo->hijoDer, id);
}

void AVL::buscarPorID(int id)
{
    NodoAVL* nodo = buscarRec(raiz, id);
    if(nodo != nullptr)
    {
        nodo->transaccion->mostrar();
    }else
    {
        cout << "No se pudo encontrar la transaccion" <<endl;
    }
}

int AVL::altura(NodoAVL* nodo)
{
    if(nodo == nullptr)
    {
        return 0;
    }
    return nodo->altura;
}

int AVL::balancear(NodoAVL* nodo)
{
    if(nodo == nullptr)
    {
        return 0;
    }
    return altura(nodo->hijoIzq) - altura(nodo->hijoDer); // se obtiene el factor de balanceo de la formula altura -> hijoizq - altura -> hijoder 
}

NodoAVL* AVL::rotarDer(NodoAVL* der)
{
    NodoAVL* izq = der->hijoIzq;
    NodoAVL* subarboltemp = izq->hijoDer;

    //rotan los nodos para mantener el balanceo
    izq->hijoDer = der;
    der->hijoIzq = subarboltemp;

    //actualiza las alturas del arbol balanceado
    if(altura(der->hijoIzq) > altura(der->hijoDer))
    {
        der->altura = 1 + altura(der->hijoIzq);
    }
    else
    {
        der->altura = 1 + altura(der->hijoDer);
    }

    if(altura(izq->hijoIzq) > altura(izq->hijoDer))
    {
        izq->altura = 1 + altura(izq->hijoIzq);
    }
    else
    {
        izq->altura = 1 + altura(izq->hijoDer);
    }

    return izq; //devuelve la nueva raiz
}

NodoAVL* AVL::rotarIzq(NodoAVL* izq)
{
    NodoAVL* der = izq->hijoDer;
    NodoAVL* subarboltemp = der->hijoIzq;
    //rota los nodos para balancear
    der->hijoIzq = izq;
    izq->hijoDer = subarboltemp;

    //actualiza las alturas de los nodos
    if(altura(izq->hijoIzq) > altura(izq->hijoDer))
    {
        izq->altura = 1 + altura(izq->hijoIzq);
    }
    else
    {
        izq->altura = 1 + altura(izq->hijoDer);
    }

    if(altura(der->hijoIzq) > altura(der->hijoDer))
    {
        der->altura = 1 + altura(der->hijoIzq);
    }
    else
    {
        der->altura = 1 + altura(der->hijoDer);
    }

    return der; //devuelve la nueva raiz

}

void AVL::destruir(NodoAVL* nodo)   //destruye el arbol
{
    if(nodo != nullptr)
    {
        destruir(nodo->hijoIzq);
        destruir(nodo->hijoDer);
        delete nodo;
    }
}
