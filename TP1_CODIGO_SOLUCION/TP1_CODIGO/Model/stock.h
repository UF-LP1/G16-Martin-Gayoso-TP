/**
 * Project Untitled
 */

#ifndef _STOCK_H
#define _STOCK_H

#include <string>
#include"Articulos.h"
#include <algorithm>
#include <list>

class Cliente; // lo buscamos y para hacer el friend nos decia que teniamos que hacer esta "Forward declaration" si no nos funcionaba

using namespace std;

class stock {
public:

    stock();
    ~stock();


 // bool buscar_art(Cliente clienteA);

  friend unsigned int Cliente::generarPresupuestos(stock stock1);     

    void set_nomb_art(string Nombre_art_ped);


    void set_cant_art(unsigned int Cant_art_s);

    bool Cant_necesaria();

    list<Articulos>list_stock;

    void agregar_stock( list<Articulos> art);
public:
    stock& operator=( const list<Articulos>& art)
    {
        list_stock = art;
        return *this;
    }
    
protected:
    string Nombre_art_pedido;
    unsigned int Cant_art_stock;
   

};

#endif //_STOCK_H