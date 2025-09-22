//
//  main.cpp
//  inventario_tienda
//
//  Created by Isabel Vaca on 20/09/25.
//

#include <iostream>
#include <vector>
#include "producto.h"
#include <fstream>
using namespace std;

//Vector con objetos tipo producto
vector<Producto> inventario;



//Función para cargar archivo y leer información, se crean objetos y se
//guardan en el vector inventario
bool loadFile(const std::string& filename){
    std::ifstream file(filename);
    if (!file) return false;

    int n;
    if (!(file >> n)) return false;
    std::string line;
    std::getline(file, line); 

    inventario.clear();
    inventario.resize(n);

    for (int i = 0; i < n; ++i) {
        if (!std::getline(file, line)) return false;

        std::stringstream ss(line);
        std::string tok;


        if (!std::getline(ss, tok, '|')) return false;
        int id = std::stoi(tok);


        std::string nombre;
        if (!std::getline(ss, nombre, '|')) return false;


        if (!std::getline(ss, tok, '|')) return false;
        double costo = std::stod(tok);


        if (!std::getline(ss, tok, '|')) return false;
        double precio = std::stod(tok);

        
        if (!std::getline(ss, tok, '|')) return false;
        int stock = std::stoi(tok);

        inventario[i] = Producto(id, nombre, costo, precio, stock);
    }
    return true;
}

//Se despliegan los productos en el inventario
void printInventario(vector<Producto> &v ){
    int size = v.size();
    for(int i =0; i<size; i++){
        cout << v[i].toString() << '\n';
    }
}

//Función swap para el selection sort
void swap(vector<Producto> &v, int i, int j){
    Producto aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

//Sort utilizando selection sort, ordena por costo de manera ascendente
void sortCosto(vector<Producto> &v){
    int size = v.size();
    for(int i=0;i<size-1; i++){
        int id_min = i;
        for(int j = i+1; j<size; j++){
            if(v[id_min].getCosto()>v[j].getCosto()){
                id_min = j;
            }
        }
        if (i != id_min){
            swap(v, i, id_min);
        }
    }
    
}

//Sort utilizando selection sort, ordena por stock de manera ascendente
void sortStock(vector<Producto> &v){
    int size = v.size();
    for(int i=0;i<size-1; i++){
        int id_min = i;
        for(int j = i+1; j<size; j++){
            if(v[id_min].getStock()>v[j].getStock()){
                id_min = j;
            }
        }
        if (i != id_min){
            swap(v, i, id_min);
        }
    }
    
}

void menu() {
    cout << "\nMenu:\n";
    cout << "1. Desplegar inventario\n";
    cout << "2. Ordenar inventario por costo\n";
    cout << "3. Ordenar inventario por stock\n";
    cout << "4. Salir\n";
    cout << "Selecciona una opcion: \n";
    cout << "(Si selecciona una opcion y no sucede nada vuelva a ingresar el numero)\n";
}




//menu
//opciones, desplegar inventario, ordenar lista por costo, precio venta y stock
int main(int argc, const char * argv[]) {

    if (!loadFile("Inventario.txt")) {
        cerr << "Error al leer archivo\n";
        return 1;
    }

    int opcion;
    
    while(true){
        menu();
        cin>>opcion;
        vector<Producto> inv;
        switch(opcion){
            case 1: {
                printInventario(inventario);
                break;
            }
            case 2: {
                inv = inventario;
                sortCosto(inv);
                printInventario(inv);
                break;
            }
            case 3: {
                inv = inventario;
                sortStock(inv);
                printInventario(inv);
                break;
            }
            case 4:{
                cout << "Saliendo del programa\n";
                return 0;
            default:
                cout << "Opcion no valida. Intenta de nuevo.\n";
            }
        }
    }

}
