//  main.cpp
//  inventario_tienda
//
//  Created by Isabel Vaca on 20/09/25
#include <sstream>
#include <queue>
#include <iostream>
#include <vector>
#include "producto.h"
#include <fstream>
#include "pedido.h"
using namespace std;

/*
*
* Este proyecto permite guardar un registro de un inventario de una tienda y acciones relacionadas.
*
*
*
*/

//Vector con objetos tipo producto
vector<Producto> inventario;
//estructura: queue
queue<Pedido> pedidos;
//variable global para registro de pedidos
int ultimoId = 0;




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
/*
 * Se despliegan los productos del inventario
 *@param:vector<Producto> &v
 *@return:
 *
 */
void printInventario(vector<Producto> &v ){
    int size = v.size();
    for(int i =0; i<size; i++){
        cout << v[i].toString() << '\n';
    }
}
/*
 * busca producto por id en el inventario, regresa ptr o null
 *@param:vector<Producto>& inventario, int id
 *@return: Producto*
 *
 */

Producto* buscarProducto(vector<Producto>& inventario, int id) {
    for (int i = 0; i < inventario.size(); ++i) {
        if (inventario[i].getId() == id) {
            return &inventario[i];
        }
    }
    return nullptr;
}
/*
 * imprime contenido de la queue (pedidos activos)
 *@param:queue<Pedido>& q
 *@return:
 *
 */

void printQueue(const queue<Pedido>& q) {
    if (q.empty()) {
        cout << "No hay pedidos \n";
        return;
    }
    queue<Pedido> copia = q;
        cout << "Pedidos en queue :\n";
        while (!copia.empty()) {
            cout << "  " << copia.front().toString() << '\n';
            copia.pop();
        }
    }

/*
 * maneja las ordenes que llegan a la tienda y las va procesando de manera FIFO.
 *@param:queue<Pedido>& pedidos, vector<Producto>& inventario, int& ultimoId
 *@return:
 *
 */
void Orders(queue<Pedido>& pedidos, vector<Producto>& inventario, int& ultimoId) {
   
    printInventario(inventario);

    while (true) {
        cout << "\n -opciones-\n"
             << "0) Ver inventario\n"
             << "1) Agregar pedido (1 producto)\n"
             << "2) Ver queue de pedidos\n"
             << "3) Enviar siguiente pedido(eliminar pedido de queue)\n"
             << "4) Salir\n"
             << "ingresa opcion: ";

        int opcion;
        cin >> opcion;

        switch (opcion) {
        case 0:
            printInventario(inventario);
            break;

        case 1: {
            // pedido de un solo producto
            string cliente;
            cout << "Nombre del cliente: ";
            cin.ignore(); 
            getline(cin, cliente);
            if (cliente.empty()) {
                cout << "Cliente no puede estar vacio\n";
                break;
            }
            
            int pid;
            cout << "ID de producto: ";
            cin >> pid;

            Producto* prod = buscarProducto(inventario, pid);
            if (prod == 0) {
                cout << "No existe un producto con ese ID\n";
                break;
            }

            cout << "Producto: " << prod->getNombre()
                 << "Stock disponible: " << prod->getStock() << '\n';

            int cantidad;
            cout << "Cantidad: ";
            cin >> cantidad;
            if (cantidad <= 0) {
                cout << "La cantidad debe ser > 0\n";
                break;
            }
            if (cantidad > prod->getStock()) {
                cout << "Stock insuficiente\n";
                break;
            }

           
            prod->setStock(prod->getStock() - cantidad);

            Pedido p(++ultimoId, cliente, pid, cantidad);
            
            pedidos.push(p);
            cout << " Pedido agregado :\n  " << p.toString() << '\n';
            break;
        }

        case 2:
            printQueue(pedidos);
            break;

        case 3:
            if (pedidos.empty()) {
                cout << "No hay pedidos por enviar.\n";
            } else {
                const Pedido& pf = pedidos.front();
                cout << "Enviando: " << pf.toString() << '\n';
                pedidos.pop();
                cout << "Enviado\n";
            }
            break;

        case 4:
            cout << "Saliendo \n";
            return;

        default:
            cout << "Opcion no valida\n";
            break;
        }
    }
}




/*
 * sort by costo = 1, stock = 2, precio venta = 3
 *@param:vector<Producto>&A, vector<Producto>&B, int low, int mid, int high, int sort
 *@return:
 *
 */

void mergeArr(vector<Producto>&A, vector<Producto>&B, int low, int mid, int high, int sort ){
    int i = low;
    int j = mid+1;
    int k = low;
    
    switch (sort) {
        case 1: // costo
            while (i<=mid && j<=high) {
                if (A[i].getCosto() <= A[j].getCosto()) B[k++] = A[i++];
                else                                     B[k++] = A[j++];
            }
            break;
        case 2: // stock
            while (i<=mid && j<=high) {
                if (A[i].getStock() <= A[j].getStock()) B[k++] = A[i++];
                else                                     B[k++] = A[j++];
            }
            break;
        default: // precio venta
            while (i<=mid && j<=high) {
                if (A[i].getPrecioVenta() <= A[j].getPrecioVenta()) B[k++] = A[i++];
                else                                                 B[k++] = A[j++];
            }
            break;
        }
        
    if(i>mid){
        for(;j<=high;j++){
            B[k++]=A[j];
        }
    }else{
        for(;i<=mid;i++){
            B[k++]=A[i];
        }
    }
    
    //Copia vector temporal al original
    for(int l=low; l<=high;l++){
        A[l] = B[l];
    }
        
}


void mergeSplit(vector<Producto> &A,vector <Producto> &B, int low, int high, int sort){
    if((high-low)<1){
        return;
    }
    
    int mid = (high+low)/2;
    mergeSplit(A,B,low, mid, sort);
    mergeSplit(A,B,mid+1, high, sort);
    mergeArr(A,B,low,mid,high, sort);
    
        
}





//Sort utilizando merge sort
void mergeSort(vector<Producto> &s, int sort){
    vector<Producto> tmp(s.size());
    
    int high = s.size()-1;
    int low = 0;
    
    mergeSplit(s, tmp, low, high, sort);
    
    
}
/*
 * agrega productos al inventario
 *@param:vector<Producto>
 *@return:bool (regresa bool para verificar que se haya ingresado de manera correcta)
 *
 */

bool addProduct(vector<Producto> &v){
    string nombre;
    cout << "Ingrese el nombre del producto: \n";
    cin.ignore();
    getline(cin,nombre);//para poder ingresar nombres con espacios
    double costo;
    cout << "Ingrese el costo del producto (con dos decimales) \n";
    cin >> costo;
    double precioVenta;
    cout << "Ingrese el precio de venta del producto (con dos decimales) \n";
    cin >> precioVenta;
    int stock;
    cout << "Ingrese el la cantidad en stock del producto (numero entero) \n";
    cin >> stock;
    //abre el archivo original y crea uno temporal para reescribir el antiguo
    //pero con el producto nuevo
    ofstream aux;
    ifstream lect;
    aux.open("auxiliar.txt", ios::out);
    lect.open("Inventario.txt", ios::in);
    
    if(aux.is_open() && lect.is_open()){
        //lee la primer linea que es el num de productos, con esto calcula el nuevo id
        int n;
        lect.seekg(0);
        string l;
        if (!getline(lect, l)) {
               std::cout << "Error leyendo el número de productos\n";
               return false;
           }
        n = stoi(l);
        //nuevo id
        n+=1;
        aux<<n<< '\n';

        string linea;
        while (std::getline(lect, linea)) {
            aux << linea << '\n';
        }
        //string del nuevo producto
        string s = to_string(n)+"|"+nombre+"|"+to_string(costo)
        +"|"+to_string(precioVenta)+"|"+to_string(stock);
        //se agrega al inventario
        inventario.push_back( Producto(n, nombre, costo, precioVenta, stock));
        aux << s << '\n';
        
        aux.close();
        lect.close();
        std::remove("Inventario.txt");
        std::rename("auxiliar.txt", "Inventario.txt");
        return true;
        
        
    }else{
        cout<<"no se pudo abrir"<<endl;
        return false;
    }
}
    

//menu
void menu() {
    cout << "\nMenu:\n";
    cout << "1. Desplegar inventario\n";
    cout << "2. Ordenar inventario por costo\n";
    cout << "3. Ordenar inventario por stock\n";
    cout << "4. Ordenar inventario por precio de venta\n";
    cout << "5. Registrar, enviar o consultar pedido\n";
    cout << "6. Agregar nuevo producto al inventario\n";
    cout << "7. Salir\n";
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
                //sort costo
                inv = inventario;
                mergeSort(inv,1);
                printInventario(inv);
                break;
            }
            case 3: {
                //sort stock
                inv = inventario;
                mergeSort(inv,2);
                printInventario(inv);
                break;
            }
            case 4: {
                //sort precio de venta
                inv = inventario;
                mergeSort(inv,3);
                printInventario(inv);
                break;
            }
            case 5:{
                Orders(pedidos, inventario, ultimoId);
                break;
            }
            case 6:{
                if(addProduct(inventario)){
                    cout<< "Se agregó el producto correctamente";
                }
                else{
                    cout<< "No se agregó correctamente";
                }
                break;
            }
            case 7:{
                cout << "Saliendo del programa\n";
                return 0;
            }
            default:
                cout << "Opcion no valida. Intenta de nuevo.\n";
            }
        }
    }



