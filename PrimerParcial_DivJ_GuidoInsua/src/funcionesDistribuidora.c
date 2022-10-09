
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcionesDistribuidora.h"
#include "funcionesDeIngreso.h"

#define TAMDESCRIPCION 31

int mostrarMenu(char* opcion)
{
	int retorno;
	char buffer;

	if(opcion != NULL)
	{
		printf("\n\n+-----------------------+");
		printf("\n|\t%-*s|",16,"MENU");
		printf("\n+-----------------------+");
		printf("\n| %-*s|",22,"A.Alta Articulo");
		printf("\n| %-*s|",22,"B.Modificar Articulo");
		printf("\n| %-*s|",22,"C.Baja Articulo");
		printf("\n| %-*s|",22,"D.Listar Articulos");
		printf("\n| %-*s|",22,"E.Listar Rubros");
		printf("\n| %-*s|",22,"F.Alta Venta");
		printf("\n| %-*s|",22,"G.Listar Ventas");
		printf("\n| %-*s|",22,"H.Informes");
		printf("\n| %-*s|",22,"I.Salir");
		printf("\n+-----------------------+");

		pedirCaracter(&buffer, 'A', 'I', "\n---Ingrese una opcion: ", "ERROR, Ingrese una opcion entre A e I");

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

int buscarArticuloVacio(eArticulo* articulos,int tamArticulos,int* indice)
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
		if(buscarArticuloVacio(articulos, tamArticulos, &indice) == 0)
		{
			pedirStringAlfabetico(bufferDescripcion, TAMDESCRIPCION, "\nIngrese la descripcion del articulo: ", "\nERROR, Ingrese solo letras y no mas de 30", 's');
			pedirFlotante(&bufferMedida, 1, 9999999, "\nIngrese la medida del articulo: ", "ERROR, Ingrese solo numeros y maximo 9.999.999");
			pedirFlotante(&bufferPrecio, 1, 9999999, "\nIngrese el precio del articulo: ", "ERROR, Ingrese solo numeros y maximo 9.999.999");
			pedirRubro(rubros, tamRubros, &bufferRubroId, "\nIngrese el id del rubro en el que se encuentra el articulo: ", "\nERROR, El id ingresado no existe");

			strncpy((*(articulos+indice)).descripcion,bufferDescripcion,TAMDESCRIPCION);
			(*(articulos+indice)).medida = bufferMedida;
			(*(articulos+indice)).precio = bufferPrecio;
			(*(articulos+indice)).rubroId = bufferRubroId;
			(*(articulos+indice)).isEmpty = 1;
			(*(articulos+indice)).idArticulo = *idArticulo;

			(*idArticulo)++;

			retorno = 0;
			printf("\nArticulo cargado con exito");
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
			printf("|%-*d|%-*s|%-*.2f|%-*.2f|%-*s|\n",4,unArticulo.idArticulo,31,unArticulo.descripcion,10,unArticulo.medida,10,unArticulo.precio,15,descripcion);
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
		ordenarArticulosPorRubroDescripcion(articulos, tamArticulos, rubros, tamRubros);

		printf("\n+----+-------------------------------+----------+----------+---------------+");
		printf("\n|%-*s|%-*s|%-*s|%-*s|%-*s|",4,"ID",31,"Descripcion",10,"Medida",10,"Precio",15,"Rubro");
		printf("\n+----+-------------------------------+----------+----------+---------------+\n");

		for(int i=0;i<tamArticulos;i++)
		{
			listarUnArticulo(*(articulos+i),rubros,tamRubros);
		}
		printf("+----+-------------------------------+----------+----------+---------------+\n");

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

int pedirRubro(eRubro* rubros,int tamRubros,int* respuesta,char mensaje[],char mensajeError[])
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

int ordenarArticulosPorRubroDescripcion(eArticulo* articulos, int tamArticulos,eRubro* rubros,int tamRubros)
{
	int retorno;
	eArticulo articuloAuxiliar;
	char primerRubro[TAMDESCRIPCION];
	char segundoRubro[TAMDESCRIPCION];

	if(articulos != NULL && tamArticulos > 0 && rubros != NULL && tamRubros)
	{
		for(int i=0;i<tamArticulos-1;i++)
		{
			for(int j=i+1;j<tamArticulos;j++)
			{
				buscarRubro(rubros, tamRubros, (*(articulos+i)).rubroId, primerRubro);
				buscarRubro(rubros, tamRubros, (*(articulos+j)).rubroId, segundoRubro);

				if( strcmp(primerRubro,segundoRubro) > 0 ||
				   (strcmp(primerRubro,segundoRubro) == 0 && strcmp((*(articulos+i)).descripcion,(*(articulos+j)).descripcion) > 0))
				{
					articuloAuxiliar = *(articulos+j);
					*(articulos+j) = *(articulos+i);
					*(articulos+i) = articuloAuxiliar;
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

int buscarArticulo(eArticulo* articulos,int tamArticulos,int id,int* indice)
{
	int retorno;

	if(articulos != NULL && tamArticulos > 0 && indice != NULL)
	{
		for(int i=0;i<tamArticulos;i++)
		{
			if((*(articulos+i)).idArticulo == id && (*(articulos+i)).isEmpty == 1)
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

int darDeBajaArticulo(eArticulo* articulos,int tamArticulos,eRubro* rubros,int tamRubros)
{
	int retorno;
	char continuar;
	int id;
	int indice;

	if(articulos != NULL && tamArticulos > 0 && rubros != NULL && tamRubros > 0)
	{
		listarArticulos(articulos, tamArticulos, rubros, tamRubros);

		pedirEntero(&id, 1000, 9999, "\n---Ingrese el id del articulo que desea dar de baja: ", "\nERROR, Ingrese un numero entre 1000 y 9999");

		if(buscarArticulo(articulos, tamArticulos, id, &indice) == 0)
		{
			printf("\n-Seleccion = ");
			listarUnArticulo(*(articulos+indice), rubros, tamRubros);
			pedirCharDosOpciones(&continuar, 's', 'n', "\nEsta seguro que quiere dar de baja este articulo? (s/n): ","\nERROR, Ingrese 's' o 'n'");

			if(continuar == 's')
			{
				(*(articulos+indice)).isEmpty = 0;
				printf("\nArticulo dado de baja con exito");
			}
			else
			{
				printf("\nBaja de articulo cancelada con exito");
			}

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

int mostrarMenuModificacion(char* opcion)
{
	int retorno;
	char buffer;

	if(opcion != NULL)
	{
		printf("\n\n+------------------------+");
		printf("\n|    %-*s|",20,"MENU Modificacion");
		printf("\n+------------------------+");
		printf("\n| %-*s|",23,"A.Modificar medida");
		printf("\n| %-*s|",23,"B.Modificar precio");
		printf("\n| %-*s|",23,"C.Volver");
		printf("\n+------------------------+");

		pedirCaracter(&buffer, 'A', 'C', "\n---Ingrese que desea modificar: ", "\nERROR, Ingrese la letra de la opcion que desea modificar");

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

int modificarArticulo(eArticulo* articulos,int tamArticulos,eRubro* rubros,int tamRubros)
{
	int retorno;
	int id;
	int indice;

	if(articulos != NULL && tamArticulos > 0 && rubros != NULL && tamRubros > 0)
	{
		listarArticulos(articulos, tamArticulos, rubros, tamRubros);

		pedirEntero(&id, 1000, 9999, "\n---Ingrese el id del empleado que desea modificar: ", "\nERROR, Ingrese un numero entre 1000 y 9999");

		if(buscarArticulo(articulos, tamArticulos, id, &indice) == 0)
		{
			printf("\n-Seleccion = ");
			listarUnArticulo(*(articulos+indice), rubros, tamRubros);
			opcionesModificacionArticulo(&(*(articulos+indice)));
		}
		else
		{
			printf("\nEse empleado no existe");
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

int opcionesModificacionArticulo(eArticulo* unArticulo)
{
	int retorno;
	float bufferMedida;
	float bufferPrecio;
	char opcion;
	char confirmar;

	if(unArticulo != NULL)
	{
		do
		{
			mostrarMenuModificacion(&opcion);

			switch(opcion)
			{
				case 'A': //Medida

					pedirFlotante(&bufferMedida, 1, 9999999, "\nIngrese la nueva medida: ", "\nERROR, Ingrese un numero entre 1 y 9.999.999");

					pedirCharDosOpciones(&confirmar, 's', 'n', "\nEsta seguro que quiere modificar la medida? (s/n): ", "\nERROR, Ingrese 's' o 'n'");
					if(confirmar == 's')
					{
						(*unArticulo).medida = bufferMedida;
					}
					else
					{
						printf("\nModificacion cancelada");
					}
				break;

				case 'B': //Precio

					pedirFlotante(&bufferPrecio, 1, 9999999, "\nIngrese el nuevo precio: ", "\nERROR, Ingrese un numero entre 1 y 9.999.999");

					pedirCharDosOpciones(&confirmar, 's', 'n', "\nEsta seguro que quiere modificar el precio? (s/n): ", "\nERROR, Ingrese 's' o 'n'");
					if(confirmar == 's')
					{
						(*unArticulo).precio = bufferPrecio;
					}
					else
					{
						printf("\nModificacion cancelada");
					}
				break;

				default:

					printf("\nVolviendo...");
				break;
			}
		}while(opcion != 'C');

		retorno = 0;
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}


