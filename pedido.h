//
//  pedido.h
//  inventario_copy
//
//  Created by Isabel Vaca on 19/10/25.
//

#include <string>
#include <sstream>
using namespace std;
/*
 * Clase Pedido, esta clase registra los pedidos, estos pedidos serán almacenados en una queue hasta ser enviados.
 *Atributos: IDpedido,nombre de cliente, IDproducto, cantidad de unidades.
 * metodos: getters, setters, to string
 */

class Pedido{
private:
    //atrbutos
    int IDpedido;
    string cliente;
    int IDproducto;
    int cantidad;
    
public:
    //constructores
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
//constructores
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
/*
*tostring
*@param:
*@return: string
*/
string Pedido::toString() const{
    stringstream salida;
    salida << "IDpedido: " << IDpedido
           << " | cliente: " << cliente
           << " | ID producto: " << IDproducto
    << " | cantidad: " << cantidad;
    return salida.str();
}

