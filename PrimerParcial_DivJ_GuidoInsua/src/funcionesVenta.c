
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcionesArticulo.h"
#include "funcionesVenta.h"
#include "funcionesDeIngreso.h"

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

int buscarVentaVacia(eVenta* ventas,int tamVentas,int* indice)
{
	int retorno;

	if(ventas != NULL && tamVentas > 0 && indice != NULL)
	{
		retorno = 1;

		for(int i=0;i<tamVentas;i++)
		{
			if((*(ventas+i)).isEmpty == 0)
			{
				*indice = i;
				retorno = 0;
				break;
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

int pedirFecha(eFecha* fecha, int anioMinimo, int anioMaximo)
{
	int bufferMes;
	int bufferDia;
	int bufferAnio;
	int retorno;

	if(fecha != NULL && anioMinimo <= anioMaximo)
	{
		retorno = 1;

		pedirEntero(&bufferMes, 1, 12, "\nIngrese el mes:", "\nERROR, Ingrese un numero entre 1 y 12");

		switch(bufferMes)
		{
			case 2:
				pedirEntero(&bufferDia, 1, 28, "\nIngrese el dia: ", "\nERROR, El mes ingresado solo tiene 28 dias");
			break;

			case 4:
			case 7:
			case 9:
			case 11:
				pedirEntero(&bufferDia, 1, 30, "\nIngrese el dia: ", "\nERROR, El mes ingresado solo tiene 30 dias");
			break;

			default:
				pedirEntero(&bufferDia, 1, 31, "\nIngrese el dia: ", "\nERROR, El mes ingresado solo tiene 31 dias");
			break;
		}

		pedirEntero(&bufferAnio, anioMinimo, anioMaximo, "\nIngrese el anio: ", "\nERROR, Ingrese un anio entre 1990 y 2022");

		if(bufferMes > 0 && bufferDia > 0 && bufferAnio > 0)
		{
			(*fecha).mes = bufferMes;
			(*fecha).dia = bufferDia;
			(*fecha).anio = bufferAnio;
			retorno = 0;
		}
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int pedirArticulo(eArticulo* articulos,int tamArticulos,eRubro* rubros,int tamRubros,int* idArticulo,int* indice)
{
	int retorno;
	int id;
	int bufferIndice;

	if(articulos != NULL && tamArticulos > 0 && rubros != NULL && tamRubros > 0 && idArticulo != NULL)
	{
		listarArticulos(articulos, tamArticulos, rubros, tamRubros);

		pedirEntero(&id, 1000, 9999, "\n---Ingrese el id del articulo: ", "\nERROR, Ingrese un numero entre 1000 y 9999");

		if(buscarArticulo(articulos, tamArticulos, id, &bufferIndice) == 0)
		{
			printf("\n-Seleccion = ");
			listarUnArticulo(*(articulos+bufferIndice), rubros, tamRubros);

			*idArticulo = id;
			*indice = bufferIndice;

			retorno = 0;
		}
		else
		{
			printf("\nEse articulo no existe");
			retorno = 1;
		}
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int altaVenta(eVenta* ventas,int tamVentas,int* idVenta,int idArticulo)
{
	int bufferCantidad;
	float bufferPrecioTotal;
	eFecha bufferFecha;
	int indice;
	int retorno;
	char continuar;

	if(ventas != NULL && tamVentas > 0 && idVenta != NULL)
	{
		if(buscarVentaVacia(ventas, tamVentas, &indice) == 0)
		{
			pedirEntero(&bufferCantidad, 1, 9999999, "\nIngrese la cantidad vendida: ", "\nERROR, Ingrese un numero entre 1 y 9.999.999");
			pedirFlotante(&bufferPrecioTotal, 1, 999999999, "\nIngrese el precio total: ", "\nERROR, Ingrese un numero entre 1 y 999.999.999");
			pedirFecha(&bufferFecha, 1990, 2022);

			pedirCharDosOpciones(&continuar, 'n', 's', "\nEsta seguro que desea cargar esta venta? (s/n): ", "\nERROR, Ingrese 's' para si o 'n' para no");

			if(continuar == 's')
			{
				(*(ventas+indice)).articuloId = idArticulo;
				(*(ventas+indice)).cantidad = bufferCantidad;
				(*(ventas+indice)).precioTotal = bufferPrecioTotal;
				(*(ventas+indice)).fecha = bufferFecha;
				(*(ventas+indice)).idVenta = *idVenta;
				(*(ventas+indice)).isEmpty = 1;

				(*idVenta)++;

				retorno = 0;
				printf("\nVenta cargada con exito");
			}
			else
			{
				retorno = 1;
				printf("\nNo se cargo la venta");
			}
		}
		else
		{
			printf("\nNo hay mas espacio para cargar ventas");
			retorno = -2;
		}
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int buscarDescripcionArticulo(eArticulo* articulos,int tamArticulos,int idArticulo,char* descripcion)
{
	int retorno;

	if(articulos != NULL && tamArticulos > 0 && descripcion != NULL)
	{
		retorno = 1;

		for(int i=0;i<tamArticulos;i++)
		{
			if((*(articulos+i)).idArticulo == idArticulo)
			{
				strcpy(descripcion,(*(articulos+i)).descripcion);
				retorno = 0;
				break;
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
		retorno = 1;

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

					retorno = 0;
				}
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

int listarUnaVenta(eVenta unaVenta,eArticulo* articulos,int tamArticulos)
{
	int retorno;
	char descripcion[TAMDESCRIPCION];

	if(articulos != NULL && tamArticulos > 0)
	{
		retorno = 1;

		if(unaVenta.isEmpty == 1)
		{
			buscarDescripcionArticulo(articulos, tamArticulos, unaVenta.articuloId, descripcion);
			printf("|%-*d|%-*s|%-*d|%-*.2f|%*d/%*d/%-*d|\n",5,unaVenta.idVenta,31,descripcion,10,unaVenta.cantidad,12,unaVenta.precioTotal,2,unaVenta.fecha.dia,2,unaVenta.fecha.mes,6,unaVenta.fecha.anio);
			retorno = 0;
		}
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
		printf("\n|%-*s|%-*s|%-*s|%-*s|%-*s|",5,"ID",31,"Articulo",10,"Cantidad",12,"PrecioTotal",12,"Mes/Dia/Anio");
		printf("\n+-----+-------------------------------+----------+------------+------------+\n");

		for(int i=0;i<tamVentas;i++)
		{
			listarUnaVenta(*(ventas+i), articulos, tamArticulos);
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
