/**
 * Project Untitled
 */


#include "Cliente.h"
#include <list>



Cliente::Cliente(string nombre_cli, string direc_cli, string tel_cli):Nombre_cliente(nombre_cli),Direc_cliente(direc_cli),Telefono_cliente(tel_cli)
{
}

 
string Cliente::get_name() {
    return this->Nombre_cliente;
}


string Cliente::get_direc() {
    return this->Direc_cliente;
}

string Cliente::get_tel() {
    return this->Telefono_cliente;
}

unsigned int Cliente::generarPresupuestos()
{
    
    int i;
    int N = lista_Art_Pedidos.size();
    unsigned int Presupuesto = 0;
    list<Articulos>::iterator it = lista_Art_Pedidos.begin();
    for(i=0 ;i <N;i++)
    {
        Presupuesto += it->get_precio() * it->get_Cant_art();
            it++;
    }
    
    
    return Presupuesto;
}
void Cliente::agregarArt(Articulos Art_pedido)
{
    lista_Art_Pedidos.push_back(Art_pedido);
   
}
 
 Cliente::~Cliente() {

}