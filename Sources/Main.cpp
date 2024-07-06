#include <iostream>
#include <queue>
//#include "Nodo.h" //nodo para el arbol ABB
//#include "NodoAVL.h" //nodo para el arbol avl
#include "Transaccion.h"
#include "Cliente.h"
#include "ABB.h"
#include "AVL.h"
#include <fstream>
#include <sstream>
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
 
    cout << "Ingrese hora (hh:mm): ";// cambiar para leer estos datos desde el archivo
    string hora; cin >> hora; cout <<endl;

    cout <<"Ingrese un monto (ej: 1000): ";
    string mon; cin >> mon; cout << endl;

    int monto = stoi(mon);

    Transaccion* transaccion = new Transaccion(id,rut,ctaDest, monto, ciudad, fecha, hora);
    arbolABB.insertar(transaccion);
    arbolAVL.insertar(transaccion);

    cout << "Transaccion correctamente ingresada." << endl;
    cout << "ID de transaccion: " << id << endl;
    id++;
}

void buscarTransaccion(){

    cout << "Ingresa id a buscar: ";
    string input; cin >> input; cout << endl;
    int id = stoi(input);
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

vector <string> dividirLinea(string str, char chr){ //divide la linea en partes usando el char ',' y retorna un vector de strings que son las partes
    vector<string> partes;
    stringstream ss(str);
    string parte;

    while(getline(ss, parte, chr)){
        partes.push_back(parte);
    }
    return partes;
}//fin splitLine

void leerClientes(){ //lee el archivo de clientes

    string linea;
    ifstream arch ("Clientes.txt");
    char split = ',';

    if (!arch.is_open()) {
    cout << "No se pudo abrir el archivo de clientes." << endl;
    return;
    }

    while(getline(arch,linea)){

        vector<string> partes = dividirLinea(linea,split);
        string nombre = partes[0];
        string rut = partes[1];

        Cliente* c = new Cliente(nombre,rut);
        clientes.push(c);
    }

    arch.close();

}

/*Cliente* buscarCliente(string ctaOrigen){ //busca si existe un cliente con su rut para asociarlo a la transaccion

    queue<Cliente*> aux = clientes;

    while(!aux.empty()){
        Cliente* temp = aux.front();
        if(temp -> getRut() == ctaOrigen){
            return temp;
        }
        aux.pop();
    }
    return new Cliente("nuevoUsuario",ctaOrigen);
}
*/

void leerTransacciones(){

    string linea;
    ifstream arch ("Transacciones.txt");
    char split = ',';

    if (!arch.is_open()) {
        cout << "No se pudo abrir el archivo de clientes." << endl;
        return;
    }

    while(getline(arch,linea)){

        vector<string> partes = dividirLinea(linea,split);
        int id = stoi(partes[0]);
        string ctaOr = partes[1];
        string ctaDe = partes[2];
        int monto = stoi(partes[3]);
        string ubi = partes[4];
        string fecha = partes[5];
        string hora = partes[6];

        //Cliente* c = buscarCliente(ctaOr);

        Transaccion* t = new Transaccion(id,ctaOr,ctaDe,monto,ubi,fecha,hora);
        arbolABB.insertar(t);
        arbolAVL.insertar(t);
    }

    arch.close();

}

int main()
{
    leerClientes(); leerTransacciones();
    menuBanco();
    return 0;
}