
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcionesFecha.h"
#include "funcionesRubro.h"
#include "funcionesArticulo.h"
#include "funcionesVenta.h"
#include "funcionesDeIngreso.h"


#define TAMDESCRIPCION 31

int buscarRubro(eRubro* rubros,int tamRubros,int idUnRubro,char* descripcion)
{
	int retorno;

	if(rubros != NULL && tamRubros > 0 && descripcion != NULL)
	{
		for(int i=0;i<tamRubros;i++)
		{
			if((*(rubros+i)).idRubro == idUnRubro)
			{
				strcpy(descripcion,(*(rubros+i)).descripcion);
				retorno = 0;
				break;
			}
			else
			{
				retorno = 1;
			}
		}
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int mostrarRubros(eRubro* rubros,int tamRubros)
{
	int retorno;
	char descripcion[TAMDESCRIPCION];

	if(rubros != NULL && tamRubros > 0)
	{

		printf("\n+----+-------------------------------+");
		printf("\n|%-*s|%-*s|",4,"Id",31,"Rubro");
		printf("\n+----+-------------------------------+");
		for(int i=0;i<tamRubros;i++)
		{
			buscarRubro(rubros, tamRubros, (*(rubros+i)).idRubro, descripcion);
			printf("\n|%-*d|%-*s|",4,(*(rubros+i)).idRubro,31,descripcion);
		}
		printf("\n+----+-------------------------------+");

		retorno = 0;
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int pedirRubro(eRubro* rubros,int tamRubros,int* respuesta,char* mensaje,char* mensajeError)
{
	int retorno;
	int bufferRubro;

	if(rubros != NULL && tamRubros > 0 && respuesta != NULL && mensaje != NULL && mensajeError != NULL)
	{
		mostrarRubros(rubros, tamRubros);

		do
		{
			pedirEntero(&bufferRubro, 0, 9999, mensaje, mensajeError);

			for(int i=0;i<tamRubros;i++)
			{
				if(bufferRubro == (*(rubros+i)).idRubro)
				{
					retorno = 0;
					*respuesta = bufferRubro;
					break;
				}
				else
				{
					retorno = 1;
				}
			}

			if(retorno == 1)
			{
				printf("%s",mensajeError);
			}
		}while(retorno != 0);

	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------
