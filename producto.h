//
//  producto.h
//  inventario_tienda
//
//  Created by Isabel Vaca on 20/09/25.
//
#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>
#include <sstream>
using namespace std;

/*
 *Clase Producto,tiene atributos: id, nombre de producto, costo, precio de venta, cantidad en stock.
 *Metodos: getters, setters, tostring
 *Estos objetos seran guardados en un arreglo en el main.
 *
 */

class Producto{
private:
    //atributos privados
    int id;
    string nombre;
    double costo;
    double precioVenta;
    int stock;
    
public:
    //constructores
    Producto();
    Producto(const Producto& c);
    Producto(int i, string n, double c, double v, int s );
    
    virtual ~Producto();
    //metodos, getters, setters
    int getId() const;
    string getNombre() const;
    double getCosto() const;
    double getPrecioVenta() const;
    int getStock() const;
    
    void setId(int i);
    void setNombre(string n);
    void setCosto(double c);
    void setPrecioVenta(double v);
    void setStock(int s);
    
    string toString();
    
};

//Constructores
Producto::Producto()
: id(0), nombre("noname"), costo(0), precioVenta(0), stock(0)
{}

Producto::Producto(const Producto&c)
: id(c.id), nombre(c.nombre), costo(c.costo), precioVenta(c.precioVenta), stock(c.stock)
{}

Producto::Producto(int i, string n, double c, double v, int s )
: id(i), nombre(n), costo(c), precioVenta(v), stock(s)
{}

Producto::~Producto() {}

/*
*getter Id
*@param:
*@return: string:Id
*/
int Producto::getId()const {
    return id;
}

string Producto::getNombre()const {
    return nombre;
}

double Producto::getCosto()const {
    return costo;
}

double Producto::getPrecioVenta()const {
    return precioVenta;
}

int Producto::getStock()const {
    return stock;
}

void Producto::setId(int i) {
    id = i;
}

void Producto::setNombre(string n) {
    nombre = n;
}

void Producto::setCosto(double c) {
    costo = c;
}

void Producto::setPrecioVenta(double v) {
    precioVenta = v;
}

void Producto::setStock(int s) {
    stock = s;
}
/*
*tostring
*@param:
*@return: string
*/
string Producto::toString() {
    stringstream salida;
    salida << "ID: " << id
           << " | nombre: " << nombre
           << " | costo: " << costo
           << " | precio: " << precioVenta
           << " | stock: " << stock;
    return salida.str();
}

#endif
