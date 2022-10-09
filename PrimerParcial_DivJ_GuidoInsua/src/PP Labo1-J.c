/*
 * Primer Parcial Laboratorio
 * Nombre: Guido Insua
 * Legajo:
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
			};
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
					{1001,"Electronica"},
					{1002,"Blanco"},
					{1003,"Audio"},
					{1004,"Video"}
			};
	eArticulo articulos[TAMARTICULOS];
	eVenta ventas[TAMVENTAS];

	char opcion;
	char continuar;
	int idAutoIncrementalArticulos;

	idAutoIncrementalArticulos = 1000;

	iniciarIsEmpty(articulos, TAMARTICULOS, ventas, TAMVENTAS);

	do
	{
		mostrarMenu(&opcion);

		switch(opcion)
		{
			case 'A': //ALTA ARTICULOS

				altaArticulo(articulos, TAMARTICULOS, rubros, TAMRUBROS, &idAutoIncrementalArticulos);
			break;

			case 'B': //MODIFICAR ARTICULOS

				if(idAutoIncrementalArticulos > 1000)
				{
					modificarArticulo(articulos, TAMARTICULOS, rubros, TAMRUBROS);
				}
				else
				{
					printf("\nNo se cargo ningun articulo");
				}
			break;

			case 'C': //BAJA ARTICULOS

				if(idAutoIncrementalArticulos > 1000)
				{
					darDeBajaArticulo(articulos, TAMARTICULOS, rubros, TAMRUBROS);
				}
				else
				{
					printf("\nNo se cargo ningun articulo");
				}
			break;

			case 'D': //LISTAR ARTICULOS

				if(idAutoIncrementalArticulos > 1000)
				{
					listarArticulos(articulos, TAMARTICULOS, rubros, TAMRUBROS);
				}
				else
				{
					printf("\nNo se cargo ningun articulo");
				}
			break;

			case 'E': //LISTAR RUBROS

				if(idAutoIncrementalArticulos > 1000)
				{
					mostrarRubros(rubros, TAMRUBROS);
				}
				else
				{
					printf("\nNo se cargo ningun articulo");
				}
			break;

			case 'F': //ALTA VENTA

				if(idAutoIncrementalArticulos > 1000)
				{
					printf("\nK");
				}
				else
				{
					printf("\nNo se cargo ningun articulo");
				}
			break;

			case 'G': //LISTAR VENTAS

				if(idAutoIncrementalArticulos > 1000)
				{
					printf("\nK");
				}
				else
				{
					printf("\nNo se cargo ningun articulo");
				}
			break;

			case 'H': //Informes

				if(idAutoIncrementalArticulos > 1000)
				{
					printf("\nK");
				}
				else
				{
					printf("\nNo se cargo ningun articulo");
				}
			break;

			default: //INFORMES

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
