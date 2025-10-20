//
//  pedido.h
//  inventario_copy
//
//  Created by Isabel Vaca on 19/10/25.
//

#include <string>
#include <sstream>
using namespace std;

class Pedido{
private:
    int IDpedido;
    string cliente;
    int IDproducto;
    int cantidad;
    
public:
    Pedido();
    Pedido(int iped, string cl, int iprod, int ca);
    
    virtual ~Pedido();
    int getIDpedido() ;
    string getCliente();
    int getIDproducto();
    int getCantidad();
    string toString()const;
    
    void setIDpedido(int iped);
    void setCliente(string cl);
    void setIDproducto(int iprod);
    void setCantidad(int ca);
    
    
};

Pedido::Pedido()
: IDpedido(0), cliente("noname"), IDproducto(0), cantidad(0)
{}

Pedido::Pedido(int iped, string cl, int iprod, int ca)
: IDpedido(iped),cliente(cl),IDproducto(iprod), cantidad(ca){}

Pedido::~Pedido() {}



int Pedido::getIDpedido() {
    return IDpedido;
}

string Pedido::getCliente() {
    return cliente;
}

int Pedido::getIDproducto() {
    return IDproducto;
}

int Pedido::getCantidad(){
    return cantidad;
}

void Pedido::setIDpedido(int iped){
    IDpedido= iped;
}

void Pedido::setCliente(string cl){
    cliente= cl;
}

void Pedido::setIDproducto(int iprod){
    IDproducto = iprod;
}


void Pedido::setCantidad(int ca){
    cantidad = ca;
}

string Pedido::toString() const{
    stringstream salida;
    salida << "IDpedido: " << IDpedido
           << " | cliente: " << cliente
           << " | ID producto: " << IDproducto
    << " | cantidad: " << cantidad;
    return salida.str();
}

