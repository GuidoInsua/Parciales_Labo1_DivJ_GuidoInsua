
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

int buscarVentaVacia(eVenta* ventas,int tamVentas,int* indice)
{
	int retorno;

	if(ventas != NULL && tamVentas > 0)
	{
		for(int i=0;i<tamVentas;i++)
		{
			if((*(ventas+i)).isEmpty == 0)
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

int pedirArticulo(eArticulo* articulos,int tamArticulos,int* respuesta,char* mensaje,char* mensajeError)
{
	int retorno;
	int bufferArticulo;

	if(articulos != NULL && tamArticulos > 0 && respuesta != NULL && mensaje != NULL && mensajeError != NULL)
	{
		do
		{
			pedirEntero(&bufferArticulo, 1000, 9999, mensaje, mensajeError);

			for(int i=0;i<tamArticulos;i++)
			{
				if(bufferArticulo == (*(articulos+i)).idArticulo && (*(articulos+i)).isEmpty == 1)
				{
					retorno = 0;
					*respuesta = bufferArticulo;
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

int altaVenta(eVenta* ventas,int tamVentas,eArticulo* articulos,int tamArticulos,eRubro* rubros,int tamRubros,int* idVenta)
{
	int bufferIdArticulo;
	int bufferCantidad;
	float bufferPrecioTotal;
	eFecha bufferFecha;
	int indice;
	int retorno;

	if(ventas != NULL && tamVentas > 0 && articulos != NULL && tamArticulos > 0 && rubros != NULL && tamRubros > 0 && idVenta != NULL)
	{
		if(buscarVentaVacia(ventas, tamVentas, &indice) == 0)
		{
			listarArticulos(articulos, tamArticulos, rubros, tamRubros);
			pedirArticulo(articulos, tamArticulos, &bufferIdArticulo, "\nIngrese el id del articulo: ", "\nERROR, El id ingresado no existe");
			pedirEntero(&bufferCantidad, 1, 9999999, "\nIngrese la cantidad vendida: ", "\nERROR, Ingrese un numero entre 1 y 9.999.999");
			pedirFlotante(&bufferPrecioTotal, 1, 999999999, "\nIngrese el precio total: ", "\nERROR, Ingrese un numero entre 1 y 999.999.999");
			pedirFecha(&bufferFecha, 1990, 2022);

			(*(ventas+indice)).articuloId = bufferIdArticulo;
			(*(ventas+indice)).cantidad = bufferCantidad;
			(*(ventas+indice)).precioTotal = bufferPrecioTotal;
			(*(ventas+indice)).fecha = bufferFecha;
			(*(ventas+indice)).idVenta = *idVenta;
			(*(ventas+indice)).isEmpty = 1;

			(*idVenta)++;

			retorno = 0;
			printf("\nVenta cargada con exito");
		}
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int buscarDescripcionArticulo(eArticulo* articulos,int tamArticulos,int idUnArticulo,char* descripcion)
{
	int retorno;

	if(articulos != NULL && tamArticulos > 0 && descripcion != NULL)
	{
		for(int i=0;i<tamArticulos;i++)
		{
			if((*(articulos+i)).idArticulo == idUnArticulo)
			{
				strcpy(descripcion,(*(articulos+i)).descripcion);
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

int ordenarVentasPorFecha(eVenta* ventas, int tamVentas)
{
	int retorno;
	eVenta ventaAuxiliar;

	if(ventas != NULL && tamVentas > 0)
	{
		for(int i=0;i<tamVentas-1;i++)
		{
			for(int j=i+1;j<tamVentas;j++)
			{
				if( (*(ventas+i)).fecha.anio < (*(ventas+j)).fecha.anio ||
				   ((*(ventas+i)).fecha.anio == (*(ventas+j)).fecha.anio && (*(ventas+i)).fecha.mes < (*(ventas+j)).fecha.mes) ||
				   ((*(ventas+i)).fecha.anio == (*(ventas+j)).fecha.anio && (*(ventas+i)).fecha.mes == (*(ventas+j)).fecha.mes && (*(ventas+i)).fecha.mes < (*(ventas+j)).fecha.mes))
				{
					ventaAuxiliar = *(ventas+j);
					*(ventas+j) = *(ventas+i);
					*(ventas+i) = ventaAuxiliar;
				}
			}
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

int listarUnaVenta(eVenta unaVenta,eArticulo* articulos,int tamArticulos)
{
	int retorno;
	char descripcion[TAMDESCRIPCION];

	if(articulos != NULL && tamArticulos > 0)
	{
		if(unaVenta.isEmpty == 1)
		{
			buscarDescripcionArticulo(articulos, tamArticulos, unaVenta.articuloId, descripcion);
			printf("|%-*d|%-*s|%-*d|%-*.2f|%*d/%*d/%-*d|\n",5,unaVenta.idVenta,31,descripcion,10,unaVenta.cantidad,12,unaVenta.precioTotal,2,unaVenta.fecha.dia,2,unaVenta.fecha.mes,6,unaVenta.fecha.anio);
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

int listarVentas(eVenta* ventas,int tamVentas,eArticulo* articulos,int tamArticulos)
{
	int retorno;

	if(ventas != NULL && tamVentas > 0 && articulos != NULL && tamArticulos > 0)
	{
		ordenarVentasPorFecha(ventas, tamVentas);

		printf("\n+-----+-------------------------------+----------+------------+------------+");
		printf("\n|%-*s|%-*s|%-*s|%-*s|%-*s|",5,"ID",31,"Articulo",10,"Cantidad",12,"PrecioTotal",12,"Dia/mes/anio");
		printf("\n+-----+-------------------------------+----------+------------+------------+\n");

		for(int i=0;i<tamVentas;i++)
		{
			listarUnaVenta(*(ventas+i),articulos,tamArticulos);
		}
		printf("+-----+-------------------------------+----------+------------+------------+\n");

		retorno = 0;
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}
