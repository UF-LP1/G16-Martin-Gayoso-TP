/**
 * Project Untitled
 */



#include "stock.h"
using namespace std;

stock::stock()
{
    this->Cant_art_stock = 0;
    this->Nombre_art_pedido ="";
}

void stock::agregar_stock(const list<Articulos>& art)
{
    list_stock = art;
}



void stock::set_nomb_art(string Nombre_art_ped) {
    this->Nombre_art_pedido = Nombre_art_ped;
}

void stock::set_cant_art(unsigned int Cant_art_s) {
    this->Cant_art_stock = Cant_art_s;
}


bool stock::Cant_necesaria() {
    return false;
}



stock::~stock() {

}

//bool stock::buscar_art(Cliente clienteA)
//{
//    list<Articulos>::iterator it = clienteA.lista_Art_Pedidos.begin();
//    list<Articulos>::iterator it2 = list_stock.begin(); //no se crea la lista de stock
//    int N = clienteA.lista_Art_Pedidos.size();
//    int N1 = list_stock.size();
//
//
//    for (int i = 0; i < N; i++)
//    {
//        for (int j = 0; j < N1; j++)
//        {
//            if (it == it2)
//                return true;
//            else
//                return false;
//
//            it2++;
//        }
//        it++;
//    }
//    
//}
