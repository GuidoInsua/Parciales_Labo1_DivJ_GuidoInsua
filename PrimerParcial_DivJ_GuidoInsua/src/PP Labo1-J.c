/*
 * Primer Parcial Laboratorio
 * Nombre: Guido Insua
 * Legajo: 112419
 * DNI: 42806238
 */

/*
	{
			{1000,"Mouse",76234,871312,1000,1},
			{1001,"Parlante",91234,221312,1002,1},
			{1002,"Celu",5234,444312,1000,1},
			{1003,"Linterna",24234,131312,1000,1},
			{1004,"Proyector",87234,531312,1002,1},
			{1005,"Camara",22234,991312,1001,1},
			{1006,"Auriculares",33234,431312,1002,1},
			{1007,"Tele",111234,231312,1003,1},
			{1008,"Teclado",24234,131312,1001,1},
			{1009,"Heladera",87234,531312,1001,1},
			{1010,"Consola",22234,991312,1003,1},
			{1011,"Bateria",33234,431312,1001,1},
			{1012,"Calculadora",111234,231312,1000,1},
			{1013,"Arduino",43434,831312,1001,1}
	}; //Articulos


	{
			{20000,1000,3123,78915,{11,6,2019},1},
			{20001,1001,312,28891,{3,11,2001},1},
			{20002,1002,3123,83517,{5,22,2003},1},
			{20003,1003,323,462512,{9,5,2012},1},
			{20004,1004,31233,243481,{11,29,1998},1},
			{20005,1001,3123,64139,{11,29,1998},1},
			{20006,1002,4123,21385,{12,8,2021},1},
			{20007,1007,3123,134531,{10,13,2000},1},
			{20008,1011,3123,71845,{8,22,2022},1},
			{20009,1012,3123,12415,{11,6,2022},1},
			{20010,1011,3123,101715,{10,11,2022},1},
			{20011,1001,3123,241445,{11,6,2019},1},
			{20012,1003,312,94372,{3,11,2001},1},
			{20013,1004,3123,245572,{5,22,2003},1},
			{20014,1008,323,824378,{9,5,2012},1},
			{20015,1001,31233,234571,{11,29,1998},1},
			{20016,1011,3123,23471,{11,29,1998},1},
			{20017,1000,4123,114555,{8,12,2021},1},
			{20018,1000,3123,83546,{1,10,2000},1},
			{20019,1003,3123,45256,{2,18,2022},1},
			{20020,1009,3123,626612,{6,17,2022},1},
			{20021,1002,3123,766113,{11,23,2022},1},
			{20022,1008,8823,245614,{6,8,2022},1}
	}; //Ventas
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionesArticulo.h"
#include "funcionesVenta.h"
#include "funcionesDeIngreso.h"
#include "funcionesInforme.h"

#define TAMRUBROS 4
#define TAMARTICULOS 200
#define TAMVENTAS 200

int main(void)
{
	setbuf(stdout,NULL);

	eRubro rubros[TAMRUBROS] =
			{
					{1000,"Electronica"},
					{1001,"Blanco"},
					{1002,"Audio"},
					{1003,"Video"}
			};
	eArticulo articulos[TAMARTICULOS];
	eVenta ventas[TAMVENTAS];
	char opcion;
	char continuar;
	int idAutoIncrementalArticulos;
	int idAutoIncrementalVentas;
	int unId;
	int unIndice;

	idAutoIncrementalArticulos = 1000; //Para hardcodear poner en 1014
	idAutoIncrementalVentas = 20000; //Para hardcodear poner en 20023

	iniciarIsEmpty(articulos, TAMARTICULOS, ventas, TAMVENTAS); //Para hardcodear comentar funcion

	do
	{
		mostrarMenu(&opcion);

		switch(opcion)
		{
			case 'A': //ALTA ARTICULOS

				altaArticulo(articulos, TAMARTICULOS, rubros, TAMRUBROS, &idAutoIncrementalArticulos);
			break;

			case 'B': //MODIFICAR ARTICULOS

				if(existeArticulo(articulos, TAMARTICULOS) == 0)
				{
					modificarArticulo(articulos, TAMARTICULOS, rubros, TAMRUBROS, opcionModificar);
				}
				else
				{
					printf("\nPrimero tiene que dar de alta un articulo");
				}
			break;

			case 'C': //BAJA ARTICULOS

				if(existeArticulo(articulos, TAMARTICULOS) == 0)
				{
					modificarArticulo(articulos, TAMARTICULOS, rubros, TAMRUBROS, opcionDarBaja);
				}
				else
				{
					printf("\nPrimero tiene que dar de alta un articulo");
				}
			break;

			case 'D': //LISTAR ARTICULOS

				if(existeArticulo(articulos, TAMARTICULOS) == 0)
				{
					listarArticulos(articulos, TAMARTICULOS, rubros, TAMRUBROS);
				}
				else
				{
					printf("\nPrimero tiene que dar de alta un articulo");
				}
			break;

			case 'E': //LISTAR RUBROS

					mostrarRubros(rubros, TAMRUBROS);
			break;

			case 'F': //ALTA VENTA

				if(existeArticulo(articulos, TAMARTICULOS) == 0)
				{
					if(pedirArticulo(articulos, TAMARTICULOS, rubros, TAMRUBROS, &unId, &unIndice) == 0)
					{
						altaVenta(ventas, TAMVENTAS, &idAutoIncrementalVentas, unId);
					}
				}
				else
				{
					printf("\nPrimero tiene que dar de alta un articulo");
				}
			break;

			case 'G': //LISTAR VENTAS

				if(idAutoIncrementalVentas > 20000)
				{
					listarVentas(ventas, TAMVENTAS, articulos, TAMARTICULOS);
				}
				else
				{
					printf("\nPrimero tiene que dar de alta alguna venta");
				}
			break;

			case 'H': //INFORMES Sin terminar

				if(existeArticulo(articulos, TAMARTICULOS) == 0)
				{
					listarInformes(articulos, TAMARTICULOS, rubros, TAMRUBROS, ventas, TAMVENTAS, idAutoIncrementalVentas);
				}
				else
				{
					printf("\nPrimero tiene que dar de alta un articulo");
				}
			break;

			default: //Salir

				pedirCharDosOpciones(&continuar, 's', 'n', "\nEsta seguro que desea salir? (s/n): ", "\nERROR, Ingrese 's' o 'n'");

				if(continuar == 's')
				{
					printf("\nAh salio con exito.");
				}
				else
				{
					opcion = 0;
				}
			break;
		}

	}while(opcion != 'I');


	return 0;
}
