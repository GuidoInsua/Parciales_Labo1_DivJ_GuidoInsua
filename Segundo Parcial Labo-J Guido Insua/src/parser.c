
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

/// \fn int parser_CompraFromText(FILE*, LinkedList*)
/// \brief Lee el archivo y guarda sus valores dentro de una nueva lista
///
/// \param pFile , puntero FILE que se quiere leer
/// \param pArrayListCompras , LinkedList lista donde se van a guardar los datos
/// \return retorna 0 si se guardan los daton el la lista o -1 si se pasa mal algun parametro
int parser_CompraFromText(FILE* pFile,LinkedList* pArrayListCompras)
{
	int retorno;
	int cantidad;
	char buffer[6][200];
	eCompras* unaCompra = NULL;

	retorno = -1;

	if(pFile != NULL && pArrayListCompras != NULL)
	{
		fscanf(pFile,"%[^\n]\n",*(buffer+0)); //Falsa lectura

		while(!feof(pFile))
		{
			cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",*(buffer+0),*(buffer+1),*(buffer+2),*(buffer+3),*(buffer+4),*(buffer+5));

			if(cantidad == 6)
			{
				unaCompra = comp_newParametros(*(buffer+0),*(buffer+1),*(buffer+2),*(buffer+3),*(buffer+4),*(buffer+5));

				if(unaCompra != NULL)
				{
					ll_add(pArrayListCompras,(eCompras*)unaCompra);
					retorno = 0;
				}
				else
				{
					printf("\nERROR");
					retorno = 1;
				}
			}
			else
			{
				comp_delete(unaCompra);
				unaCompra = NULL;
				break;
			}
		}
	}

    return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int parser_CompraToText(FILE*, LinkedList*)
/// \brief recorre la lista de compras y guarda las variables de los campos en un archivo
///
/// \param pFile , puntero FILE donde se quieren guardar los datos
/// \param pArrayListCompras , LinkedList lista de la cual se van a copiar los datos
/// \return retorna 0 si logra copiar los datos y cargar el archivo o -1 si se paso mal algun parametro
int parser_CompraToText(FILE* pFile , LinkedList* pArrayListCompras)
{
	int retorno;
	char bufferChar[6][200];
	int bufferInt[5];
	eCompras* unaCompra = NULL;

	retorno = -1;

	if(pFile != NULL && pArrayListCompras != NULL)
	{
		fprintf(pFile,"codigoCompra,descripcion,origen,precioUnitario,cantidad,totalCompra\n");

		for(int i=0;i<ll_len(pArrayListCompras);i++)
		{
			unaCompra = ll_get(pArrayListCompras, i);

			comp_getCodigo(unaCompra, (bufferInt+0));
			comp_getDescripcion(unaCompra, *(bufferChar+1));
			comp_getOrigen(unaCompra, (bufferInt+1));
			comp_getPrecioUnitario(unaCompra, (bufferInt+2));
			comp_getCantidad(unaCompra, (bufferInt+3));
			comp_getTotalCompra(unaCompra, (bufferInt+4));

			itoa(*(bufferInt+0),*(bufferChar+0),10);
			itoa(*(bufferInt+1),*(bufferChar+2),10);
			itoa(*(bufferInt+2),*(bufferChar+3),10);
			itoa(*(bufferInt+3),*(bufferChar+4),10);
			itoa(*(bufferInt+4),*(bufferChar+5),10);

			fprintf(pFile,"%s,%s,%s,%s,%s,%s\n",*(bufferChar+0),*(bufferChar+1),*(bufferChar+2),*(bufferChar+3),*(bufferChar+4),*(bufferChar+5));
		}

		retorno = 0;
	}

    return retorno;
}

//-----------------------------------------------------------------------------------------------
