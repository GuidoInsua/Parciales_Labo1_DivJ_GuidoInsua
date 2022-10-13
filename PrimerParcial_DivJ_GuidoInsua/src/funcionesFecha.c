#include <stdio.h>
#include <stdlib.h>
#include "funcionesFecha.h"
#include "funcionesDeIngreso.h"

int pedirFecha(eFecha* fecha, int anioMinimo, int anioMaximo)
{
	int bufferMes;
	int bufferDia;
	int bufferAnio;
	int retorno;

	retorno = -1;

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

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------
