
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcionesDistribuidora.h"
#include "funcionesDeIngreso.h"

#define TAMDESCRIPCION 31

int mostrarMenu(int* opcion)
{
	int retorno;
	int buffer;

	if(opcion != NULL)
	{
		printf("\n+-----------------------+");
		printf("\n|\t%-*s|",16,"MENU");
		printf("\n+-----------------------+");
		printf("\n| %-*s|",22,"1.Alta Articulo");
		printf("\n| %-*s|",22,"2.Modificar Articulo");
		printf("\n| %-*s|",22,"3.Baja Articulo");
		printf("\n| %-*s|",22,"4.Listar Articulos");
		printf("\n| %-*s|",22,"5.Listar Rubros");
		printf("\n| %-*s|",22,"6.Alta Venta");
		printf("\n| %-*s|",22,"7.Listar Ventas");
		printf("\n| %-*s|",22,"8.Informes");
		printf("\n| %-*s|",22,"9.Salir");
		printf("\n+-----------------------+");

		pedirEntero(&buffer, 1, 9, "\n---Ingrese una opcion: ", "ERROR, Ingrese un numero entre 1 y 6");

		*opcion = buffer;

		retorno = 0;
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}
//-------------------------------------------------------------------------------------------------------------------------

int iniciarIsEmpty(eArticulo* articulos,int tamArticulos,eVenta* ventas,int tamVentas)
{
	int retorno;

	if(articulos != NULL && tamArticulos > 0 && ventas != NULL && tamVentas > 0)
	{
		for(int i=0;i<tamArticulos;i++)
		{
			(*(articulos+i)).isEmpty = 0;
		}

		for(int i=0;i<tamVentas;i++)
		{
			(*(ventas+i)).isEmpty = 0;
		}

		retorno = 0;
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int buscarArticulo(eArticulo* articulos,int tamArticulos,int* indice)
{
	int retorno;

	if(articulos != NULL && tamArticulos > 0)
	{
		for(int i=0;i<tamArticulos;i++)
		{
			if((*(articulos+i)).isEmpty == 0)
			{
				*indice = i;
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

int altaArticulo(eArticulo* articulos,int tamArticulos,eRubro* rubros,int tamRubros,int* idArticulo)
{
	char bufferDescripcion[TAMDESCRIPCION];
	float bufferMedida;
	float bufferPrecio;
	int bufferRubroId;
	int indice;
	int retorno;

	if(articulos != NULL && tamArticulos > 0 && rubros != NULL && tamRubros > 0 && idArticulo != NULL)
	{
		if(buscarArticulo(articulos, tamArticulos, &indice) == 0)
		{
			pedirStringAlfabetico(bufferDescripcion, TAMDESCRIPCION, "\nIngrese descripcion: ", "\nERROR", 's');
			pedirFlotante(&bufferMedida, 1, 1000, "\nIngrese medida: ", "ERROR");
			pedirFlotante(&bufferPrecio, 1, 1000, "\nIngrese precio: ", "ERROR");
			pedirRubro(rubros, tamRubros, &bufferRubroId, "\nIngrese rubro: ", "\nERROR");

			strncpy((*(articulos+indice)).descripcion,bufferDescripcion,TAMDESCRIPCION);
			(*(articulos+indice)).medida = bufferMedida;
			(*(articulos+indice)).precio = bufferPrecio;
			(*(articulos+indice)).rubroId = bufferRubroId;
			(*(articulos+indice)).isEmpty = 1;
			(*(articulos+indice)).idArticulo = *idArticulo;

			(*idArticulo)++;
		}
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int listarUnArticulo(eArticulo unArticulo,eRubro* rubros,int tamRubros)
{
	int retorno;
	char descripcion[TAMDESCRIPCION];

	if(rubros != NULL && tamRubros > 0)
	{
		if(unArticulo.isEmpty == 1)
		{
			buscarRubro(rubros, tamRubros, unArticulo.rubroId, descripcion);
			printf("|%-*d|%-*s|%-*.2f|%-*.2f|%-*s|\n",4,unArticulo.idArticulo,31,unArticulo.descripcion,20,unArticulo.medida,10,unArticulo.precio,15,descripcion);
		}

		retorno = 0;
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int listarArticulos(eArticulo* articulos,int tamArticulos,eRubro* rubros,int tamRubros)
{
	int retorno;

	if(articulos != NULL && tamArticulos > 0 && rubros != NULL && tamRubros > 0)
	{
		printf("\n+----+-------------------------------+--------------------+----------+---------------+");
		printf("\n|%-*s|%-*s|%-*s|%-*s|%-*s|",4,"ID",31,"Descripcion",20,"Medida",10,"Precio",15,"Rubro");
		printf("\n+----+-------------------------------+--------------------+----------+---------------+\n");

		for(int i=0;i<tamArticulos;i++)
		{
			listarUnArticulo(*(articulos+i),rubros,tamRubros);
		}
		printf("+----+-------------------------------+--------------------+----------+---------------+\n");

		retorno = 0;
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

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
		printf("\n|%-*s|%-*s|",4,"Id",31,"Descripcion");
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

int pedirRubro(eRubro* rubros,int tamRubros,int* respuesta,char mensaje[],char mensajeError[])
{
	int retorno;
	int bufferRubro;

	if(rubros != NULL && tamRubros > 0 && respuesta != NULL && mensaje != NULL && mensajeError != NULL)
	{
		mostrarRubros(rubros, tamRubros);

		do
		{
			pedirEntero(&bufferRubro, 0, 1000, mensaje, mensajeError);

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
