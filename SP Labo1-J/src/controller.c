
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Compras.h"
#include "parser.h"
#include "controller.h"
#include "funcionesDeIngreso.h"

//-----------------------------------------------------------------------------------------------

/// \fn int mostrarMenu(int*)
/// \brief Imprime el menu principal
///
/// \param opcion , puntero int por donde se pasa la eleccion
/// \return retorna 0 si todo sale bien o -1 si se pasa mal algun parametro
int controller_mostrarMenu(int* opcion)
{
	int retorno;
	int buffer;

	retorno = -1;

	if(opcion != NULL)
	{
		printf("\n\n+----------------------------+");
		printf("\n|\t %-*s|",20,"  MENU");
		printf("\n+----------------------------+");
		printf("\n| %-*s|",27,"1. Cargar archivo");
		printf("\n| %-*s|",27,"2. Imprimir lista");
		printf("\n| %-*s|",27,"3. Asignar totales");
		printf("\n| %-*s|",27,"4. Filtrar por tipo");
		printf("\n| %-*s|",27,"5. Mostrar compras");
		printf("\n| %-*s|",27,"6. Guardar compras");
		printf("\n| %-*s|",27,"7. Salir");
		printf("\n+----------------------------+");

		pedirEntero(&buffer, 1, 11, "\n---Ingrese una opcion: ", "\nERROR, Ingrese una opcion entre 1 y 7");

		*opcion = buffer;

		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int controller_cargarComprasDedeTexto(char*, LinkedList*)
/// \brief Abre la ruta pasada por parametro en modo lectura y llama a una funcion para que cargue una lista con los datos
///
/// \param path , puntero char donde se encuentra la ruta del archivo
/// \param pArrayListCompras , LinkedList lista donde se van a guardar los datos del archivo
/// \return retorna 0 si la lista fue cargada 1 si la lista no fue cargada y -1 si se paso mal algun parametro
int controller_cargarComprasDedeTexto(char* path,LinkedList* pArrayListCompras)
{
	FILE* pFile = NULL;
	int retorno;

	retorno = -1;

	if(path != NULL && pArrayListCompras != NULL)
	{
		pFile=fopen(path,"r");

		if(pFile != NULL)
		{
			if(parser_CompraFromText(pFile ,pArrayListCompras) == 0)
			{
				printf("\nCompras cargadas");
				retorno = 0;
			}
			else
			{
				printf("\nERROR, Compras no cargadas");
				retorno = 1;
			}

			fclose(pFile);
		}
		else
		{
			printf("\nERROR, El archivo ingresado no existe");
		}
	}

    return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int controller_listarCompras(LinkedList*)
/// \brief Lista todas las compras cargadas en la lista
///
/// \param pArrayListCompras , LinkedList lista de compras
/// \return retorna 0 si imprime las compras -1 si se pasa mal algun parametro
int controller_listarCompras(LinkedList* pArrayListCompras)
{
	int retorno;
	int cantidadCargados;
	eCompras* unaCompra = NULL;

	retorno = -1;

	if(pArrayListCompras != NULL)
	{
		cantidadCargados = ll_len(pArrayListCompras);

		printf("+------+------------------------------+----------------+---------------+--------+------------+\n");
		printf("|%-*s| %-*s| %-*s|%-*s|%-*s|%-*s|\n",6,"Codigo",29,"Descripcion",15,"Origen",15,"Precio unitario",8,"Cantidad",12,"Total Compra");
		printf("+------+------------------------------+----------------+---------------+--------+------------+\n");

		for(int i=0;i<cantidadCargados;i++)
		{
			unaCompra = ll_get(pArrayListCompras, i);

			retorno = controller_listarUnaCompra(unaCompra);
		}
		printf("+------+------------------------------+----------------+---------------+--------+------------+\n");
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int controller_listarUnaCompra(eCompras*)
/// \brief Imprime los datos de la compra pasada por parametro
///
/// \param unaCompra , puntero eCompra la compra que se quiere listar
/// \return retorna 0 si se imprimen los datos -1 si se pasa mal algun parametro
int controller_listarUnaCompra(eCompras* unaCompra)
{
	int retorno;
	int bufferCodigo;
	char bufferDescripcion[TAMDESCRIPCION];
	int bufferOrigen;
	int bufferPrecio;
	int bufferCantidad;
	int bufferTotalCompra;
	char nombreOrigen[3][TAMDESCRIPCION] = {"Administracion","Taller","Ventas"};

	retorno = -1;

	if(unaCompra != NULL)
	{
		comp_getCodigo(unaCompra, &bufferCodigo);
		comp_getDescripcion(unaCompra, bufferDescripcion);
		comp_getOrigen(unaCompra, &bufferOrigen);
		comp_getPrecioUnitario(unaCompra, &bufferPrecio);
		comp_getCantidad(unaCompra, &bufferCantidad);
		comp_getTotalCompra(unaCompra, &bufferTotalCompra);

		printf("| %-*d| %-*s| %-*s| %-*d| %-*d| %-*d|\n",5,bufferCodigo,29,bufferDescripcion,15,*(nombreOrigen+bufferOrigen-1),14,bufferPrecio,7,bufferCantidad,11,bufferTotalCompra);

		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int controller_guardarComprasDedeTexto(char*, LinkedList*)
/// \brief Abre la ruta pasada por parametro en modo escritura y llama a una funcion para que guarde en el archivo los datos de la lista
///
/// \param path , puntero char donde se encuentra la ruta del archivo
/// \param pArrayListCompras , LinkedList lista la cual se quiere guardar en el archivo
/// \return retorna 0 si el archivo fue cargado 1 si el archivo no fue cargado y -1 si se paso mal algun parametro
int controller_guardarComprasDedeTexto(char* path,LinkedList* pArrayListCompras)
{
	FILE* pFile = NULL;
	int retorno;
	char continuar = 's';

	retorno = -1;

	if(path != NULL && pArrayListCompras != NULL)
	{
		if(strcmp(path,"data.csv") == 0)
		{
			pedirCharDosOpciones(&continuar, 's', 'n', "\nEl archivo ya existe, desea sobreescribirlo? (s/n): ", "\nERROR, Ingrese 's' para si o 'n' para no");
		}

		if(continuar == 's')
		{
			pFile=fopen(path,"w");

			if(pFile != NULL)
			{
				if(parser_CompraToText(pFile ,pArrayListCompras) == 0)
				{
					printf("\nCompras cargadas exitosamente");
					printf("\nSe genero el archivo '%s'",path);
					retorno = 0;
				}
				else
				{
					printf("\nERROR, Compras no cargadas");
					retorno = 1;
				}

				fclose(pFile);
			}
		}
		else
		{
			printf("\nSe cancelo el guardado, volviendo...");
		}
	}

    return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int controller_menuFiltros(int*)
/// \brief Imprime el menu de filtros y pide el criterio
///
/// \param opcion , puntero int por donde se pasa la respuesta
/// \return retoran 0 si todo sale bien -1 si se pasa mal algun parametro
int controller_menuFiltros(int* opcion)
{
	int retorno;
	int buffer;

	retorno = -1;

	if(opcion != NULL)
	{
		printf("\n\n+----------------------------+");
		printf("\n|\t %-*s|",20,"  Filtros");
		printf("\n+----------------------------+");
		printf("\n| %-*s|",27,"1. Administracion");
		printf("\n| %-*s|",27,"2. Taller");
		printf("\n| %-*s|",27,"3. Ventas");
		printf("\n| %-*s|",27,"4. Volver");
		printf("\n+----------------------------+");

		pedirEntero(&buffer, 1, 11, "\n---Ingrese una opcion: ", "\nERROR, Ingrese una opcion entre 1 y 7");

		*opcion = buffer;

		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int controller_opcionesDeFiltro(LinkedList*)
/// \brief llama a ll_filter para generar una nueva lista filtrada con el criterio deseado y luego guarda la lista en un archivo
///
/// \param pArrayListaCompras , LinkedList lista que se quiere filtrar
/// \return retorna 0 si todo sale bien -1 si se pasa mal algun parametro
int controller_opcionesDeFiltro(LinkedList* pArrayListaCompras)
{
	int retorno;
	int opcion;
	LinkedList* listaFiltrada = NULL;

	retorno = -1;

	if(pArrayListaCompras != NULL)
	{
		do
		{
			controller_menuFiltros(&opcion);

			switch(opcion)
			{
				case 1:

					listaFiltrada = ll_filter(pArrayListaCompras, comp_filtrarComprasPorAdministracion);
					controller_guardarComprasDedeTexto("comprasAdministracion.csv", listaFiltrada);
				break;

				case 2:

					listaFiltrada = ll_filter(pArrayListaCompras, comp_filtrarComprasPorTaller);
					controller_guardarComprasDedeTexto("comprasTaller.csv", listaFiltrada);
				break;

				case 3:

					listaFiltrada = ll_filter(pArrayListaCompras, comp_filtrarComprasPorVentas);
					controller_guardarComprasDedeTexto("comprasVentas.csv", listaFiltrada);
				break;

				default:

					printf("\nVolviendo...");
				break;
			}
		}while(opcion != 4);

		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------
