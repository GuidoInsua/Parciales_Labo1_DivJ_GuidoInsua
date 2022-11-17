
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Compras.h"
#include "parser.h"
#include "controller.h"
#include "funcionesDeIngreso.h"

int main(void)
{
	setbuf(stdout,NULL);

	LinkedList* listaCompras = ll_newLinkedList();
	LinkedList* listaResultados = NULL;
	int opcion;
	char continuar;
	int seGuardo = 1;
	char path[100];

	do
	{
		controller_mostrarMenu(&opcion);
		switch(opcion)
		{
			case 1: //Cargar archivo

            	if(ll_isEmpty(listaCompras) == 0)
            	{
            		printf("\nLos archivos ya fueron cargados, Si desea cargar una nueva lista todos los datos no guardados se perderan");
            		pedirCharDosOpciones(&continuar, 's', 'n', "\nDesea eliminar la lista cargada? (s/n): ", "\nERROR, Ingrese 's' para si o 'n' para no");

            		if(continuar == 's')
            		{
            			ll_deleteLinkedList(listaCompras);
            			ll_deleteLinkedList(listaResultados);

            			listaCompras = ll_newLinkedList();
            			listaResultados = NULL;

            			printf("\nLista eliminada con exito, ya puede cargar un nuevo archivo");
            		}
            		else
            		{
            			printf("\nNo se elimino la lista");
            		}
            	}
            	else
            	{
            		pedirNombreArchivoTexto(path, 100, "\nIngrese el nombre del archivo que quiere leer: ", "\nERROR, El nombre del archivo no puede contener: /:*?<>|"); /* Tampoco \ ni " */
            		controller_cargarComprasDedeTexto(path, listaCompras);
            	}
			break;

			case 2: //Imprimir lista

            	if(ll_isEmpty(listaCompras) == 0)
            	{
            		ll_sort(listaCompras, comp_ordenarComprasPorCodigo, 1);
            		controller_listarCompras(listaCompras);
            	}
            	else
            	{
            		printf("\nERROR, Primero tiene que cargar los archivos");
            	}
			break;

			case 3: //Asignar totales

            	if(ll_isEmpty(listaCompras) == 0)
            	{
            		listaResultados = ll_map(listaCompras, comp_calacularTotalCompra);
            	}
            	else
            	{
            		printf("\nERROR, Primero tiene que cargar los archivos");
            	}
			break;

			case 4: //Filtrar por tipo

            	if(ll_isEmpty(listaCompras) == 0)
            	{
  				  controller_opcionesDeFiltro(listaCompras);
            	}
            	else
            	{
            		printf("\nERROR, Primero tiene que cargar los archivos");
            	}
			break;

			case 5: //Mostrar compras

            	if(ll_isEmpty(listaCompras) == 0)
            	{
            		ll_sort(listaCompras, comp_ordenarComprasPorDescripcion, 1);
            		ll_sort(listaResultados, comp_ordenarComprasPorDescripcion, 1);
            		controller_listarCompras(listaCompras);
            	}
            	else
            	{
            		printf("\nERROR, Primero tiene que cargar los archivos");
            	}
			break;

			case 6: //Guardar compras

            	if(ll_isEmpty(listaResultados) == 0)
            	{
            		pedirNombreArchivoTexto(path, 100, "\nIngrese el nombre del archivo que quiere guardar: ", "\nERROR, El nombre del archivo no puede contener: /:*?<>|"); /* Tampoco \ ni " */
            		controller_guardarComprasDedeTexto(path, listaResultados);
            	}
            	else
            	{
            		printf("\nERROR, Primero tiene que asignar los totales");
            	}
			break;

			default: //Salir

            	if(seGuardo == 0)
            	{
            		printf("\nNo guardo los cambios");
            	}

            	pedirCharDosOpciones(&continuar, 's', 'n', "\nEsta seguro que desea salir? (s/n): ", "\nERROR, Ingrese 's' para si o 'n' para no");

            	if(continuar == 's')
            	{
            		printf("\nSaliendo");
            	}
            	else
            	{
            		opcion = 1;
            	}
			break;
		}

	}while(opcion != 7);

	ll_deleteLinkedList(listaCompras);
	ll_deleteLinkedList(listaResultados);
	return 0;
}
