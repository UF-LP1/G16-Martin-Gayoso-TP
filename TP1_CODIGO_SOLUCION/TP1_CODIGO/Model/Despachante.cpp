/**
 * Project Untitled
 */


#include "Despachante.h"

/**
 * Despachante implementation
 */


/**
 * @param unsigned int Cant_entreg usigned int Cant_prods
 */




Despachante::Despachante(string _Tipo_empleado, string _Nombre, string _Apellido, string _Dni, unsigned int _Sueldos, unsigned int Cant_entreg, unsigned int Cant_prods): Empleados(_Tipo_empleado,_Nombre, _Apellido, _Dni, _Sueldos), Cantidad_entregas(Cant_entreg),Cantidad_productos_entregar(Cant_prods)
{
	
}

Despachante::~Despachante() {

}


