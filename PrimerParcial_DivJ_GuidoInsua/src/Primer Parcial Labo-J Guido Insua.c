/*
 * Primer Parcial Laboratorio
 * Nombre: Guido Insua
 * Legajo:
 * DNI: 42806238
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
					{1,"Electronica"},
					{2,"Blanco"},
					{3,"Audio"},
					{4,"Video"}
			};
	eArticulo articulos[TAMARTICULOS];
	eVenta ventas[TAMVENTAS];

	int opcion;
	char continuar;
	int idAutoIncrementalArticulos;

	idAutoIncrementalArticulos = 1000;

	iniciarIsEmpty(articulos, TAMARTICULOS, ventas, TAMVENTAS);

	do
	{
		mostrarMenu(&opcion);

		switch(opcion)
		{
			case 1: //ALTA ARTICULOS

				altaArticulo(articulos, TAMARTICULOS, rubros, TAMRUBROS, &idAutoIncrementalArticulos);
			break;

			case 2: //MODIFICAR ARTICULOS

				if(opcion == 1)
				{
					printf("\nK");
				}
				else
				{
					printf("\nNo se cargo ningun articulo");
				}
			break;

			case 3: //BAJA ARTICULOS

				if(opcion == 1)
				{
					printf("\nK");
				}
				else
				{
					printf("\nNo se cargo ningun articulo");
				}
			break;

			case 4: //LISTAR ARTICULOS

				if(opcion == 4)
				{
					listarArticulos(articulos, TAMARTICULOS, rubros, TAMRUBROS);
				}
				else
				{
					printf("\nNo se cargo ningun articulo");
				}
			break;

			case 5: //LISTAR RUBROS

				if(opcion == 1)
				{
					printf("\nK");
				}
				else
				{
					printf("\nNo se cargo ningun articulo");
				}
			break;

			case 6: //ALTA VENTA

				if(opcion == 1)
				{
					printf("\nK");
				}
				else
				{
					printf("\nNo se cargo ningun articulo");
				}
			break;

			case 7: //LISTAR VENTAS

				if(opcion == 1)
				{
					printf("\nK");
				}
				else
				{
					printf("\nNo se cargo ningun articulo");
				}
			break;

			case 8: //Informes

				if(opcion == 2)
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
