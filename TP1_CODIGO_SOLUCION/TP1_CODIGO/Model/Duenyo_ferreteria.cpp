/**
 * Project Untitled
 */


#include "Duenyo_ferreteria.h"

#include <list> 




Duenyo_ferreteria::Duenyo_ferreteria() {
    this->A_cobrar = 0;
    this->A_pagar = 0;

}


void Duenyo_ferreteria::set_cobrar( unsigned int _A_cobrar) {
    this->A_cobrar = _A_cobrar; 
    cout << "El duenyo le cobra por el total de Articulos tanto comprados,repuestos o cambios al cliente:$  " << this->A_cobrar <<endl;
}




//plata c es la plata que nos da el cliente y la otra es lo que tiene que pagar
void Duenyo_ferreteria::set_pagar(unsigned int platac, unsigned int _A_pagar) {
    this->A_pagar = (platac - _A_pagar);
    if (platac < _A_pagar){
        throw NOcero();
    this->A_pagar = 0;
    }
    cout << "El Duenyo le da el vuelto al cliente, vuelto: $ " << this->A_pagar << endl;
    
    
}

void Duenyo_ferreteria::set_pagar_seguro(unsigned int seguro)
{
    this->A_pagar = seguro;
    cout << "El Duenyo le devuelve el seguro al cliente: $ " << this->A_pagar << endl;
}

void Duenyo_ferreteria::agregarEmp(Empleados Emp_Agregar)
{
    list_empleados.push_back(Emp_Agregar);

}

void Duenyo_ferreteria::contratar(Empleados empleado) {
    list_empleados.push_back(empleado);
    cout << "Empleado "<< empleado.get_name() << " contratado "<<endl;
    
}

void Duenyo_ferreteria::despedir( Empleados empleado)
{
    list<Empleados> copia = list_empleados;
    list<Empleados>::iterator it;
    for ( it = copia.begin(); it != copia.end(); it++)
    {
        if (*it == empleado)
        {
            list_empleados.remove(*it);
            cout << "Empleado: " << empleado.get_name() << " Despedido "<<endl;
            break;
            
        }
    }
    if (it==copia.end())
    {
        throw ExpDesp();
    }
    
}


Duenyo_ferreteria::~Duenyo_ferreteria() {

}