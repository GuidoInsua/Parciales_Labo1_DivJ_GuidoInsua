
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcionesArticulo.h"
#include "funcionesVenta.h"
#include "funcionesDeIngreso.h"
#include "funcionesInforme.h"

//-------------------------------------------------------------------------------------------------------------------------

int mostrarMenuInformes(char* opcion)
{
	int retorno;
	char buffer;

	if(opcion != NULL)
	{
		printf("\n\n+------------------------------------------------+");
		printf("\n|\t\t%-*s|",33,"  MENU Informes");
		printf("\n+------------------------------------------------+");
		printf("\n| %-*s|",47,"A. Articulos de un rubro");
		printf("\n| %-*s|",47,"B. Ventas en una fecha");
		printf("\n| %-*s|",47,"C. Importe de ventas de un articulo");
		printf("\n| %-*s|",47,"D. Importe de ventas de un rubro en una fecha");
		printf("\n| %-*s|",47,"E. Volver");
		printf("\n+------------------------------------------------+");

		pedirCaracter(&buffer, 'A', 'E', "\n---Ingrese que desea informar: ", "\nERROR, Ingrese la letra de la opcion que desea modificar");

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

int listarInformes(eArticulo* articulos,int tamArticulos,eRubro* rubros,int tamRubros,eVenta* ventas,int tamVentas,int idVentas)
{
	int retorno;
	char opcion;
	int unId;
	int unIndice;

	if(articulos != NULL && tamArticulos > 0 && rubros != NULL && tamRubros > 0 && ventas != NULL && tamVentas > 0)
	{
		do
		{
			mostrarMenuInformes(&opcion);

			switch(opcion)
			{
				case 'A': // Articulos de un rubro

					listarArticulosDeUnRubro(articulos, tamArticulos, rubros, tamRubros);
				break;

				case 'B': // Ventas en una fecha
					if(idVentas > 20000)
					{
						listarVentasDeUnaFecha(ventas, tamVentas, articulos, tamArticulos);
					}
					else
					{
						printf("\nPrimero tiene que dar de alta alguna venta");
					}
				break;

				case 'C': // Importe de ventas de un articulo

					if(idVentas > 20000)
					{
						if(pedirArticulo(articulos, tamArticulos, rubros, tamRubros, &unId, &unIndice) == 0)
						{
							mostrarImporteVentasUnArticulo(ventas, tamVentas, unId);
						}
					}
					else
					{
						printf("\nPrimero tiene que dar de alta alguna venta");
					}
				break;

				case 'D': // Importe de ventas de un rubro en una fecha

					if(idVentas > 20000)
					{
						mostrarImporteVentasUnRubroFecha(ventas, tamVentas, articulos, tamArticulos, rubros, tamRubros);
					}
					else
					{
						printf("\nPrimero tiene que dar de alta alguna venta");
					}
				break;

				default:

					printf("\nVolviendo...");
				break;
			}
		}while(opcion != 'E');

		retorno = 0;
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int listarArticulosDeUnRubro(eArticulo* articulos,int tamArticulos,eRubro* rubros,int tamRubros)
{
	int retorno;
	char descripcion[TAMDESCRIPCION];
	int idRubro;

	if(articulos != NULL && tamArticulos > 0 && rubros != NULL && tamRubros > 0)
	{
		retorno = 1;

		pedirRubro(rubros, tamRubros, &idRubro, "\nIngrese el id del rubro: ", "\nERROR, El id ingresado no existe, Ingrese un numero entre 1000 y 1003");

		buscarDescripcionRubro(rubros, tamRubros, idRubro, descripcion);

		ordenarArticulosPorRubroDescripcion(articulos, tamArticulos, rubros, tamRubros);

		printf("\n+----+-------------------------------+----------+----------+---------------+");
		printf("\n|%-*s|%-*s|%-*s|%-*s|%-*s|",4,"ID",31,"Descripcion",10,"Medida",10,"Precio",15,"Rubro");
		printf("\n+----+-------------------------------+----------+----------+---------------+\n");

		for(int i=0;i<tamArticulos;i++)
		{
			if((*(articulos+i)).isEmpty == 1 && (*(articulos+i)).rubroId == idRubro)
			{
				printf("|%-*d|%-*s|%-*.2f|%-*.2f|%-*s|\n",4,(*(articulos+i)).idArticulo,31,(*(articulos+i)).descripcion,10,(*(articulos+i)).medida,10,(*(articulos+i)).precio,15,descripcion);
				retorno = 0;
			}
		}
		printf("+----+-------------------------------+----------+----------+---------------+\n");

		if(retorno == 1)
		{
			printf("\nNo se cargaro ningun articulo con el rubro '%s'",descripcion);
		}
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int listarFechasCargadas(eVenta* ventas,int tamVentas)
{
	int retorno;

	if(ventas != NULL && tamVentas > 0)
	{
		retorno = 1;

		ordenarVentasPorFecha(ventas, tamVentas);

		printf("\n---Fechas cargadas:");
		printf("\n+------------+");
		printf("\n|%-*s|",12,"Mes/Dia/Anio");
		printf("\n+------------+\n");

		for(int i=0;i<tamVentas;i++)
		{
			if((*(ventas+i)).isEmpty == 1)
			{
				printf("| %*d/%*d/%-*d|\n",2,(*(ventas+i)).fecha.mes,2,(*(ventas+i)).fecha.dia,5,(*(ventas+i)).fecha.anio);
				retorno = 0;
			}
		}

		printf("+------------+\n");

		if(retorno == 1)
		{
			printf("\nNo existe ninguna fecha cargada");
		}
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int listarVentasDeUnaFecha(eVenta* ventas,int tamVentas,eArticulo* articulos,int tamArticulos)
{
	int retorno;
	eFecha bufferFecha;
	char descripcion[TAMDESCRIPCION];

	if(ventas != NULL && tamVentas > 0 && articulos != NULL && tamArticulos > 0)
	{
		retorno = -2;

		if(listarFechasCargadas(ventas, tamVentas) == 0)
		{
			retorno = 1;

			pedirFecha(&bufferFecha, 1990, 2022);

			printf("\n+-----+-------------------------------+----------+------------+------------+");
			printf("\n|%-*s|%-*s|%-*s|%-*s|%-*s|",5,"ID",31,"Articulo",10,"Cantidad",12,"PrecioTotal",12,"Mes/Dia/Anio");
			printf("\n+-----+-------------------------------+----------+------------+------------+\n");

			for(int i=0;i<tamVentas;i++)
			{
				if((*(ventas+i)).isEmpty == 1 && (*(ventas+i)).fecha.anio == bufferFecha.anio && (*(ventas+i)).fecha.mes == bufferFecha.mes
						&& (*(ventas+i)).fecha.dia == bufferFecha.dia)
				{
					buscarDescripcionArticulo(articulos, tamArticulos, (*(ventas+i)).articuloId, descripcion);
					printf("|%-*d|%-*s|%-*d|%-*.2f|%*d/%*d/%-*d|\n",5,(*(ventas+i)).idVenta,31,descripcion,10,(*(ventas+i)).cantidad,12,(*(ventas+i)).precioTotal,
							2,(*(ventas+i)).fecha.mes,2,(*(ventas+i)).fecha.dia,6,(*(ventas+i)).fecha.anio);
					retorno = 0;
				}
			}
			printf("+-----+-------------------------------+----------+------------+------------+\n");

			if(retorno == 1)
			{
				printf("\nNo se ingresaron ventas en esa fecha");
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

int mostrarImporteVentasUnArticulo(eVenta* ventas,int tamVentas,int idArticulo)
{
	int retorno;
	float importeTotal;
	int contador;

	importeTotal = 0;
	contador = 0;

	if(ventas != NULL && tamVentas > 0)
	{
		retorno = 1;

		for(int i=0;i<tamVentas;i++)
		{
			if((*(ventas+i)).isEmpty == 1 && (*(ventas+i)).articuloId == idArticulo)
			{
				importeTotal = importeTotal + (*(ventas+i)).precioTotal;
				contador++;
				retorno = 0;
			}
		}

		if(retorno == 0)
		{
			printf("\nSe cargaron %d ventas del articulo seleccionado\n-El importe total es: $%.2f",contador,importeTotal);
		}
		else
		{
			printf("\nNo se cargaron ventas del articulo seleccionado");
		}

	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int mostrarImporteVentasUnRubroFecha(eVenta* ventas,int tamVentas,eArticulo* articulos,int tamArticulos,eRubro* rubros,int tamRubros)
{
	int retorno;
	float importeTotal;
	int idRubro;
	eFecha fecha;
	int contador;
	char descripcion[TAMDESCRIPCION];

	importeTotal = 0;
	contador = 0;

	if(ventas != NULL && tamVentas > 0 && articulos != NULL && tamArticulos > 0 && rubros != NULL && tamRubros > 0)
	{
		retorno = 1;

		listarFechasCargadas(ventas, tamVentas);
		pedirFecha(&fecha, 1990, 2022);

		pedirRubro(rubros, tamRubros, &idRubro, "\nIngrese el id del rubro: ", "\nERROR, El id ingresado no existe, Ingrese un numero entre 1000 y 1003");
		buscarDescripcionRubro(rubros, tamRubros, idRubro, descripcion);

		for(int i=0;i<tamArticulos;i++)
		{
			for(int j=0;j<tamVentas;j++)
			{
				if((*(articulos+i)).isEmpty == 1 && (*(articulos+i)).rubroId == idRubro &&
						(*(ventas+j)).isEmpty == 1 && (*(ventas+j)).articuloId == (*(articulos+i)).idArticulo && (*(ventas+j)).fecha.anio == fecha.anio &&
						(*(ventas+j)).fecha.mes == fecha.mes && (*(ventas+j)).fecha.dia == fecha.dia)
				{
					importeTotal = importeTotal + (*(ventas+j)).precioTotal;
					retorno = 0;
					contador++;
				}
			}
		}

		if(retorno == 0)
		{
			printf("\nSe cargaron %d ventas del rubro '%s' el dia %d/%d/%d \n-El importe total es: $%.2f",contador,descripcion,fecha.mes,fecha.dia,fecha.anio,importeTotal);
		}
		else
		{
			printf("\nNo se cargaron ventas del rubro '%s' el dia %d/%d/%d",descripcion,fecha.mes,fecha.dia,fecha.anio);
		}
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}
