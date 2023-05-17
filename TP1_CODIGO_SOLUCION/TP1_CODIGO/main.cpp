#include"Bibliotecas.h" 
using namespace std;

int main()
{

	
//Creamos la Ferreteria y Duenyo
	Duenyo_ferreteria* ELDuenyo = new Duenyo_ferreteria(); 
	Ferreteria* Ferreteria1 = new Ferreteria("FERRETUTI");
	Ferreteria1->set_direccion("Callao 1345");
	cout << Ferreteria1->get_nombre() << endl;

//"Llenamos el stock"
	stock* stockp = new stock(); 
	std::list<Articulos> Articulos_stock;
	
	Articulos*A1 = new Articulos_Ferreteria ("Clavo", 0.5, "Ferreteria", "Metal", TipoF1);
	Articulos* A2 = new Articulos_CocinayBano_Bazar ("Cortina", 200.0, "cocinabano", Amarillo);
	Articulos* A3 = new Articulos_Electricidad ("Enchufe", 3.9, "Electricidad", Tipo1, Nopedidol);
	Articulos* A4 = new Herramientas ("Pulidora", 90, "Herramientas");
	Articulos* A5 = new Articulos_Ferreteria("Tornillo", 1.5, "Ferreteria", "Metal", TipoF2);
	
	A1->set_cant_art(100);
	Articulos_stock.push_back(*A1);

	A2->set_cant_art(90);
	Articulos_stock.push_back(*A2);

	A3->set_cant_art(50);
	Articulos_stock.push_back(*A3);

	A4->set_cant_art(70);
	Articulos_stock.push_back(*A4);

	A5->set_cant_art(100);
	Articulos_stock.push_back(*A5);

	stockp->agregar_stock(Articulos_stock);

//Ingresamos Dia y "tomamos hora"

	time_t now = time(0);//tiempo actual
	string Dia;//ingresamos el dia nosotros
	cout << "DIA: ";
	cin >> Dia;



	if (Ferreteria1->ingreso_horario(now,Dia) == true)//me fijo que este abierta
	{
	//Creamos Cliente
		Cliente* Cliente1 = new Cliente("Sol", "PPPP33", "66739973");
		

	//Articulos que pide el cliente, con sus set
	
			Articulos* Articulo1 = new Articulos_Ferreteria("Clavo", 0.5, "Ferreteria", "Metal", TipoF1); 
			Articulos* Articulo2 = new Herramientas("Pulidora", 90, "Herramientas");
			Articulos* Articulo3 = new Articulos_CocinayBano_Bazar("Cortina", 200.0, "cocinabano", Amarillo);
			Articulos* Articulo4 = new Articulos_Electricidad("Lampara", 34.9, "Electricidad", Nopedidoe, LED);
			Articulos* Articulo5 = new Articulos_Electricidad("Enchufe", 3.9, "Electricidad", Tipo1, Nopedidol);
			
		
		Articulo1->set_cant_art(30);
		Articulo1->set_precio(20);
		Articulo1->set_cambio(false);

		Articulo2->set_cant_art(1);
		Articulo2->set_cambio(false);
		

		Herramientas* Herramienta1 = dynamic_cast<Herramientas*>(Articulo2);
		Herramienta1->set_Alquiler(true);
		
		if (Herramienta1 != nullptr)
		{
			if (Herramienta1->get_Alquiler() == true)//me fijo que la herramienta se pueda alquilar
			{
				Herramienta1->set_Estado_art_a_alquilado(true);//lo pongo en true porque lo estan alquilando ahora
				Herramienta1->set_tiempo(5);
				Herramienta1->set_Precio_D(500);
				Herramienta1->set_Precio_s(3000);
				cout << "Precio total al alquilarlo:  " << Herramienta1->get_total_alquilar() << endl;

			}
		}
		Articulo2->set_precio(Herramienta1->get_total_alquilar());

		Articulo3->set_cant_art(1);
		Articulo3->set_precio(1000);
		Articulo3->set_cambio(true);

		Articulo4->set_cant_art(2);
		Articulo4->set_precio(2500);
		Articulo4->set_cambio(true);

		Articulo5->set_cant_art(3);
		Articulo5->set_precio(40);
		Articulo5->set_cambio(false);

		Cliente1->set_foto(true);
		if (Cliente1->get_foto() == true)
		{
			Articulos* Repuesto1 = new Articulos_Ferreteria("Tornillo", 1.5, "Ferreteria", "Metal", TipoF2);
			Repuesto1->set_cant_art(1);
			Repuesto1->set_precio(100);
			Repuesto1->set_cambio(false);
			Cliente1->agregarArt(*Repuesto1);

			delete Repuesto1;
			
		}

		//agregamos los articulos pedidos por el cliente
				Cliente1->agregarArt(*Articulo1);
				Cliente1->agregarArt(*Articulo2);
				Cliente1->agregarArt(*Articulo3);
				Cliente1->agregarArt(*Articulo4);
				Cliente1->agregarArt(*Articulo5);

		//Generamos presupuesto y revisamos de tener todo en stock
			unsigned int PresupuestoTotal = 0;
			unsigned int PlataCliente = 0; //es la plata con la que nos paga el cliente
			unsigned int PlataSeguro;

			PresupuestoTotal = Cliente1->generarPresupuestos(*stockp);
				ELDuenyo->set_cobrar(PresupuestoTotal);//aca se le informa al cliente cuanto abonar
				cout << "Con cuanto desea abonar: ";
				cin >> PlataCliente;

			ELDuenyo->set_pagar_Articulos(PlataCliente, PresupuestoTotal);//esto te da el vuelto de tu presupueto
			
			if (Herramienta1->get_Estado_art_a_alquilado() == true)//aca nos fijamos esto porque si no esta alquilado no hya seguro a devolver
			{
				PlataSeguro = Herramienta1->get_Precio_S();
				ELDuenyo->set_pagar_seguro(PlataSeguro);//esta devuelve la plata del seguro y por eso lo hacemos en otr funcion
				Herramienta1->set_Estado_art_a_alquilado(false);//cuando le devulevo el seguro el me devuleve la Herramienta alquilada

			}	
		
			//imprimimos como pureba un Articulo y al cliente
				cout << Articulo1->get_nombre_art() << " " << Articulo1->get_Tam() << " " << Articulo1->get_Cant_art() << " " << Articulo1->get_precio() << endl;
				Cliente1->imprimir();


//Ahora vamos a probar las fucniones relacionadas con el Duenyo y los empleados
	//Creamos un Empleado de cada tipo
		Empleados* Empleado1 = new Plomero("Plomero", "Pedro", "Perez", "35241975", 100000);
		Plomero* Plomero1 = dynamic_cast<Plomero*>(Empleado1);
		

		if (Plomero1 != nullptr) {    //Usamos dynamic_cast para poder acceder a los metodos de la clase hija(plomero)
			Plomero1->set_rep_inst(true);
			Plomero1->set_Mantenimiento(false);
		}

		Empleados* Empleado2 = new Despachante("Despachante", "Daniela", "Diaz", "43950018", 70000, 10, 50);
		Despachante* Despachante1 = dynamic_cast<Despachante*>(Empleado2);
		

		if (Despachante1 != nullptr) {
			cout << "Cant entregas: " << Despachante1->get_Cant_entreg() << endl << "Cant productos: " << Despachante1->get_cant_prod() << endl;
		}

		Empleados* Empleado3 = new Servicio_cerrajeria("Servicio de cerrajeria", "Sebastian", "Castro", "16000001", 90000, "llave", "magnetica");
		Servicio_cerrajeria* Cerrajero1 = dynamic_cast<Servicio_cerrajeria*>(Empleado3);
		
		
		Cerrajero1->set_permiso(true);
		if (Cerrajero1 != nullptr)
		{
			if(Cerrajero1->Permiso_llave()==true){
			cout << "Tipo servicio: " << Cerrajero1->get_tipo_serv() << endl << "Tipo llave: " << Cerrajero1->get_tipo_llave() << endl;
			}
		}
		ELDuenyo->agregarEmp(*Empleado1);
		ELDuenyo->agregarEmp(*Empleado2);
		ELDuenyo->agregarEmp(*Empleado3);
		

		//imprimimos como pureba un Empleado
			cout << Empleado1->get_name() << " " << Empleado1->get_surname() << " " << Empleado1->get_dni() << " " << Empleado1->get_sueldos() << endl;

		//Funcion Virtual Heredada redefinida en c/u
		Empleado1->realizar_trabajo();
		Empleado2->realizar_trabajo();
		Empleado3->realizar_trabajo();

		ELDuenyo->despedir(*Empleado3);
	
		
			Empleados* Empleado4 = new Plomero("Plomero", "Pablo", "Perez", "46788900", 100000); //Este lo creamos para contratarlo
			Plomero* Plomero2 = dynamic_cast<Plomero*>(Empleado4);
			ELDuenyo->contratar(*Empleado4);
			if (Plomero1 != nullptr) {    
				Plomero1->set_rep_inst(false);
				Plomero1->set_Mantenimiento(true);
			}
		
			

			try
			{
				Empleados* Empleado5 = new Despachante("Despachante", "Daniel", "Dim", "34567897", 70000, 10, 50);
				Despachante* Despachante2 = dynamic_cast<Despachante*>(Empleado5);
				ELDuenyo->despedir(*Empleado5);
			}
			catch (const std::exception& e)
			{
				cout << "Error: " << e.what() << endl;
			}

		

		try
		{
			
			ELDuenyo->set_pagar_Articulos(90, 100);
		}
		catch (const std::exception& e)
		{
			cout << "Error: " << e.what() << endl;

		}

		//CLIENTE 2
		string name, direc, tel;
		cout << "Ingrese nombre cliente: " << endl;
		cin >> name;
		cout << "Ingrese Direccion del cliente: " << endl;
		cin >> direc;
		cout << "Ingrese telefono del cliente: " << endl;
		cin >> tel;

	Cliente* Cliente2=new Cliente(name, direc, tel);

	unsigned int k;
	int i,num;
	cout << "cuantos articulos quiere comprar: ";
	cin >> k;
	
	cout << "1=clavos, tamanyo 0.5" << endl << "2=clavos, tamanyo 1" << endl << "3= Pulidora" << endl << "4=Cortinas color Amarillo" << endl;
	for ( i = 0; i < k; i++)
	{
		cout << "Elija que articulo quiere: " << endl;
		cin >> num;
		switch (num)
		{
		case 1: 
			Articulos * Articulo6 = new Articulos_Ferreteria("Clavo", 0.5, "Ferreteria", "Metal", TipoF1);
			
			unsigned int Cant_Art;
			cout << " Ingrese la cantidad de articulos que quiere: ";
			cin >> Cant_Art;
			Articulo6->set_cant_art(Cant_Art);
			Articulo6->set_precio(20);//estos los decimos nosotras porque vendria a ser algo que decide el duenyo
			Articulo6->set_cambio(false);
			Cliente2->agregarArt(*Articulo6);
			break;

		case 2:
			Articulos * Articulo7 = new Articulos_Ferreteria("Clavo", 1, "Ferreteria", "Metal", TipoF1);
			unsigned int Cant_Art,Precio;
			bool Cambio;
			cout << " Ingrese la cantidad de articulos que quiere: "<<endl;
			cin >> Cant_Art;

			Articulo7->set_cant_art(Cant_Art);
			Articulo7->set_precio(20);
			Articulo7->set_cambio(false);
			Cliente2->agregarArt(*Articulo7);
			break;

		case 3:
			Articulos * Articulo8 = new Herramientas("Pulidora", 90, "Herramientas");
			Herramientas* Herramienta3 = dynamic_cast<Herramientas*>(Articulo8);
			unsigned int tiempo;
			cout << "Cuantos dias quiere alquilar la Herramineta? ";
			cin >> tiempo;

			Herramienta1->set_Alquiler(true);

			if (Herramienta1 != nullptr)
			{
				if (Herramienta1->get_Alquiler() == true)//me fijo que la herramienta se pueda alquilar
				{

					Herramienta3->set_Estado_art_a_alquilado(true);//lo pongo en true porque lo estan alquilando ahora
					Herramienta3->set_tiempo(tiempo);
					Herramienta3->set_Precio_D(500);
					Herramienta3->set_Precio_s(3000);
					cout << "Precio total al alquilarlo:  " << Herramienta3->get_total_alquilar() << endl;

				}
			}
			Articulo8->set_precio(Herramienta3->get_total_alquilar());
			Cliente2->agregarArt(*Articulo8);

			if (Herramienta3->get_Estado_art_a_alquilado() == true)//aca nos fijamos esto porque si no esta alquilado no hya seguro a devolver
			{
				PlataSeguro = Herramienta3->get_Precio_S();
				ELDuenyo->set_pagar_seguro(PlataSeguro);//esta devuelve la plata del seguro y por eso lo hacemos en otr funcion
				Herramienta1->set_Estado_art_a_alquilado(false);//cuando le devulevo el seguro el me devuleve la Herramienta alquilada

			}
			break;

			case 4:
				Articulos * Articulo9 = new Articulos_CocinayBano_Bazar("Cortina", 200.0, "cocinabano", Amarillo);
				unsigned int Cant_Art1;
				cout << " Ingrese la cantidad de articulos que quiere: ";
				cin >> Cant_Art1;
				Articulo9->set_cant_art(Cant_Art1);
				Articulo9->set_precio(1000);
				Articulo9->set_cambio(true);
				Cliente2->agregarArt(*Articulo9);
				break;

		
		}
	}
	 PresupuestoTotal = 0;
	 PlataCliente = 0; //es la plata con la que nos paga el cliente
	
	PresupuestoTotal = Cliente2->generarPresupuestos(*stockp);
	ELDuenyo->set_cobrar(PresupuestoTotal);//aca se le informa al cliente cuanto abonar
	cout << "Con cuanto desea abonar: ";
	cin >> PlataCliente;

	ELDuenyo->set_pagar_Articulos(PlataCliente, PresupuestoTotal);//esto te da el vuelto de tu presupueto

		cout << "La cantidad de cliente atendidos hoy fue: " << Cliente::get_cantclientes()<<endl;
	
		
		delete Cliente1;
		delete Articulo1;
		delete Articulo3;
		delete Articulo4;
		delete Articulo5;
		delete Empleado1;
		delete Empleado2;
		delete Empleado3;
		delete Herramienta1;
		delete ELDuenyo;
		delete stockp;
		delete A1;
		delete A2;
		delete A3;
		delete A4;
		delete A5;
}
	else
	{
	cout << "ESTA CERRADO";
	}

	return 0;
}

