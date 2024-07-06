#include "Transaccion.h"


Transaccion::Transaccion(int id, Cliente* cuentaOrigen, string cuentaDestino, int monto, string ubicacion, string fecha, string hora){

    this -> id = id;
    this -> cuentaOrigen = cuentaOrigen;
    this -> cuentaDestino = cuentaDestino;
    this -> monto = monto;
    this -> ubicacion = ubicacion;
    this -> fecha = fecha;
    this -> hora = hora;

}
Transaccion::~Transaccion(){
    delete cuentaOrigen;
}

int Transaccion::getID(){
    return id;
}

Cliente* Transaccion::getCtaOrigen(){
    return cuentaOrigen;
}

string Transaccion::getCtaDestino(){
    return cuentaDestino;
}

int Transaccion::getMonto(){
    return monto;
}

string Transaccion::getUbicacion(){
    return ubicacion;
}

string Transaccion::getFecha(){
    return fecha;
}

string Transaccion::getHora(){
    return hora;
}


void Transaccion::mostrar()
{
    cout<<"ID: " << id << ", Cuenta Origen: ";
    cuentaOrigen->mostrar();
    cout<<", Cuenta Destino: " << cuentaDestino << ", Monto: " << monto << ", Ubicacion: " << ubicacion << ", Fecha: " << fecha << ", Hora: " << hora << endl;
}