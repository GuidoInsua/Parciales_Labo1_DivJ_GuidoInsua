/*
 * Primer Parcial Laboratorio
 * Nombre: Guido Insua
 * Legajo: 112419
 * DNI: 42806238
 */

/*
			{
					{1001,"Parlante",24234,131312,1003,1},
					{1002,"Celu",24234,131312,1001,1},
					{1003,"Linterna",24234,131312,1001,1},
					{1004,"Proyector",24234,131312,1004,1},
					{1005,"Camara",24234,131312,1004,1},
					{1006,"Auriculares",24234,131312,1003,1},
					{1007,"Tele",24234,131312,1004,1},
					{1008,"Arduino",24234,131312,1001,1}
			}; //Articulos


			{
					{20001,1001,312,99422,{11,3,2001},1},
					{20002,1002,3123,532422,{22,5,2003},1},
					{20003,1001,323,441122,{5,9,2012},1},
					{20004,1002,31233,54422,{29,11,1998},1},
					{20005,1001,3123,234422,{13,2,2001},1},
					{20006,1002,4123,634422,{8,12,2021},1},
					{20007,1002,3123,934422,{13,10,2022},1},
					{20008,1002,3123,934422,{22,8,2022},1},
					{20009,1002,3123,934422,{6,11,2022},1},
					{20010,1001,3123,934422,{11,10,2022},1},
					{20011,1001,8823,45422,{19,8,2022},1}
			}; //Ventas
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionesDistribuidora.h"
#include "funcionesDeIngreso.h"

#define TAMRUBROS 4
#define TAMARTICULOS 100
#define TAMVENTAS 100

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

	idAutoIncrementalArticulos = 1000; //Para hardcodear poner en 1009
	idAutoIncrementalVentas = 20000; //Para hardcodear poner en 20012

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
					modificarArticulo(articulos, TAMARTICULOS, rubros, TAMRUBROS);
				}
				else
				{
					printf("\nPrimero tiene que dar de alta un articulo");
				}
			break;

			case 'C': //BAJA ARTICULOS

				if(existeArticulo(articulos, TAMARTICULOS) == 0)
				{
					darDeBajaArticulo(articulos, TAMARTICULOS, rubros, TAMRUBROS);
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
					altaVenta(ventas, TAMVENTAS, articulos, TAMARTICULOS, rubros, TAMRUBROS, &idAutoIncrementalVentas);
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
					printf("\nSin terminar");
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

	}while(opcion != 9);


	return 0;
}
