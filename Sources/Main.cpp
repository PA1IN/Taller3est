#include <iostream>
#include <queue>
//#include "Nodo.h" //nodo para el arbol ABB
//#include "NodoAVL.h" //nodo para el arbol avl
#include "Transaccion.h"
#include "Cliente.h"
#include "ABB.h"
#include "AVL.h"

using namespace std;

queue<Transaccion*> fraudulentas;
queue<Cliente*> clientes;
ABB arbolABB;
AVL arbolAVL;
int id = 1; // variable para probar el menu

void ingresarTransaccion(){ //despliega la opcion 1 del menú

    cout << "Ingrese datos de cliente: " << endl;
    cout << "Nombre: ";
    string name; cin >> name; cout << endl;
    cout << "rut: ";
    string rut; cin >> rut; cout << endl;

    Cliente* c = new Cliente(name,rut);
    clientes.push(c);

    cout << "Ingrese rut de la cuenta de destino: ";
    string ctaDest; cin >> ctaDest; cout << endl;

    cout << "Ingrese su ubicacion: ";
    string ciudad; cin >> ciudad; cout << endl;
    
    cout << "Ingrese fecha (dd/mm/yyyy): ";
    string fecha; cin >> fecha; cout << endl;
 
    cout << "Ingrese hora (hh:mm): ";            // cambiar para leer estos datos desde el archivo
    string hora; cin >> hora; cout <<endl;

    cout <<"Ingrese un monto: ";
    int monto; cin >> monto; cout << endl;

    Transaccion* transaccion = new Transaccion(id++,c,ctaDest, monto, ciudad, fecha, hora);
    arbolABB.insertar(transaccion);
    arbolAVL.insertar(transaccion);

    cout << "Transaccion correctamente ingresada." << endl;
}

void buscarTransaccion(){

    cout << "Ingresa id a buscar: ";
    int id; cin >> id; cout << endl;
    arbolAVL.buscarPorID(id);
}

void detectarFraudes(){         // cambiar logica para leer el limite desde txt o rectificar bien
    int monto_limite;
    monto_limite = 100000; // el monto limite para detectar un fraude definido en este caso es 100.000

    arbolABB.detectarFraude(monto_limite);
}

void generarInforme() //agregar logica para generar informe 
{
    cout << "Generando informe de todas las transacciones..." << endl;

}

void leerTransacciones(){ //logica para leer txt de transacciones y tambien para leer el de clientes 
    
}

void menuBanco(){

    while(true)
    {
        cout << "-------------------------------" << endl;
        cout << "**********Menu del Banco**********" << endl; cout << endl;
        cout << "1) Ingresar Transaccion." << endl;
        cout << "2) Buscar Transaccion." << endl;
        cout << "3) Detectar Fraudes." << endl;
        cout << "4) Generar Informe." << endl;
        cout << "5) Salir" << endl; cout << endl;
        cout << "-------------------------------" << endl;

        cout << ">";

        int opt; cin >> opt; cout << endl;

        switch(opt)
        {
            case 1:
                ingresarTransaccion();
                break;
            case 2:
                buscarTransaccion();
                break;
            case 3:
                detectarFraudes();
            case 4:
                generarInforme();
            case 5:
                return;
            default:
                cout << "Error opcion incorrecta, intente nuevamente" << endl;
        }
        cout << endl;
    }
}

int main()
{
    menuBanco();
    return 0;
}