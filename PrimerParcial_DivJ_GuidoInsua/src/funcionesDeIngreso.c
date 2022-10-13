
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static int miFgets(char*,int);
static int miFgets(char* cadena, int tam)
{
	int retorno;
	char bufferCadena[4000];

	if(cadena != NULL && tam > 0)
	{
		fflush(stdin);
		if( fgets(bufferCadena,sizeof(bufferCadena),stdin) != NULL &&
		    strnlen(bufferCadena,sizeof(bufferCadena)) <= tam)
		{
			if(bufferCadena[strnlen(bufferCadena,sizeof(bufferCadena))-1] == '\n')
			{
				bufferCadena[strnlen(bufferCadena,sizeof(bufferCadena))-1] = '\0';
			}

			if(strnlen(bufferCadena,sizeof(bufferCadena)) <= tam)
			{
				strncpy(cadena,bufferCadena,tam);
				retorno = 0;
			}
		}
		else
		{
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

static int esInt(char*,int);
static int esInt(char* cadena, int tam)
{
	int retorno;

	if(cadena != NULL && tam > 0)
	{
		for(int i=0;cadena[i] != '\0';i++)
		{
			if((i==0 && (cadena[i] == '+' || cadena[i] == '-') && isdigit(cadena[i+1]) != 0) || isdigit(cadena[i]) != 0)
			{
				retorno = 0;
				continue;
			}
			else
			{
				retorno = 1;
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

static int esFloat(char*,int);
static int esFloat(char* cadena, int tam)
{
	int retorno;
	char seIngresoComa;

	seIngresoComa = 'n';

	if(cadena != NULL && tam > 0)
	{
		for(int i=0;cadena[i] != '\0';i++)
		{
			if((i==0 && (cadena[i] == '+' || cadena[i] == '-') && isdigit(cadena[i+1]) != 0) || isdigit(cadena[i]) != 0)
			{
				retorno = 0;
				continue;
			}
			else
			{
				if(i != 0 && isdigit(cadena[i-1]) != 0 && cadena[i] == '.' && seIngresoComa == 'n')
				{
					retorno = 0;
					seIngresoComa = 's';
					continue;
				}
				else
				{
					retorno = 1;
					break;
				}
			}
		}
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

static int esAlfabetico(char[],int,char);
static int esAlfabetico(char cadena[], int tam, char extendido)
{
	int retorno;

	if(cadena != NULL && tam > 0)
	{
		for(int i=0;cadena[i] != '\0';i++)
		{
			if(( extendido == 's' &&
			   (cadena[i] == 'ü' || cadena[i] == 'é' || cadena[i] == 'ä' ||
				cadena[i] == 'ë' || cadena[i] == 'ï' || cadena[i] == 'Ä' ||
				cadena[i] == 'É' || cadena[i] == 'ö' || cadena[i] == 'Ö' ||
				cadena[i] == 'Ü' || cadena[i] == 'á' || cadena[i] == 'í' ||
				cadena[i] == 'ó' || cadena[i] == 'ú' || cadena[i] == 'ñ' ||
				cadena[i] == 'Ñ' || cadena[i] == 'Á' || cadena[i] == 'Ë' ||
				cadena[i] == 'Í' || cadena[i] == 'Ï' || cadena[i] == 'Ó' ||
				cadena[i] == 'Ú')) || (i != 0 && cadena[i] == ' ') || (isalpha(cadena[i]) != 0))
			{
				retorno = 0;
				continue;
			}

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

static int obtenerCadenaInt(int*);
static int obtenerCadenaInt(int* bufferDireccion)
{
	int retorno;
	char bufferCadena[50];

	if( bufferDireccion != NULL &&
		miFgets(bufferCadena,sizeof(bufferCadena)) == 0 &&
		esInt(bufferCadena,sizeof(bufferCadena)) == 0)
	{
		retorno = 0;
		*bufferDireccion = atoi(bufferCadena);
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

static int obtenerCadenaFloat(float*);
static int obtenerCadenaFloat(float* bufferDireccion)
{
	int retorno;
	char bufferCadena[50];

	if( bufferDireccion != NULL &&
		miFgets(bufferCadena,sizeof(bufferCadena)) == 0 &&
		esFloat(bufferCadena,sizeof(bufferCadena)) == 0)
	{
		retorno = 0;
		*bufferDireccion = atof(bufferCadena);
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

static int obtenerCadenaAlfabetica(char[],int,char);
static int obtenerCadenaAlfabetica(char buffer[], int tam, char extendido)
{
	int retorno;
	char bufferCadena[tam];

	if( buffer != NULL &&
		miFgets(bufferCadena,sizeof(bufferCadena)) == 0 &&
		esAlfabetico(bufferCadena,sizeof(bufferCadena),extendido) == 0)
	{
		retorno = 0;
		strncpy(buffer,bufferCadena,tam);
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}

//-------------------------------------------------------------------------------------------------------------------------

int pedirEntero(int* direccion, int minimo, int maximo, char mensaje[], char mensajeError[])
{
	int retorno;
	int bufferEntero;

	if(direccion != NULL && minimo <= maximo && mensaje != NULL && mensajeError != NULL)
	{
		do
		{
			printf("%s",mensaje);
			if( obtenerCadenaInt(&bufferEntero) == 0 &&
				bufferEntero >= minimo &&
				bufferEntero <= maximo)
			{
				*direccion = bufferEntero;
				retorno = 0;
			}
			else
			{
				printf("%s",mensajeError);
				retorno = 1;
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

int pedirFlotante(float* direccion, float minimo, float maximo, char mensaje[], char mensajeError[])
{
	int retorno;
	float bufferFlotante;

	if(direccion != NULL && minimo <= maximo && mensaje != NULL && mensajeError != NULL)
	{
		do
		{
			printf("%s",mensaje);
			if( obtenerCadenaFloat(&bufferFlotante) == 0 &&
				bufferFlotante >= minimo &&
				bufferFlotante <= maximo)
			{
				*direccion = bufferFlotante;
				retorno = 0;
			}
			else
			{
				printf("%s",mensajeError);
				retorno = 1;
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

int pedirStringAlfabetico(char cadena[], int tam, char mensaje[], char mensajeError[],char extendido)
{
	int retorno;
	char buffer[tam];

	if(cadena != NULL && mensaje != NULL && mensajeError != NULL)
	{
		do
		{
			printf("%s",mensaje);
			if(obtenerCadenaAlfabetica(buffer,tam,extendido) == 0)
			{
				retorno = 0;
				strncpy(cadena,buffer,tam);
			}
			else
			{
				printf("%s",mensajeError);
				retorno = 1;
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

int pedirCaracter(char* direccion, char minimo, char maximo, char* mensaje, char* mensajeError)
{
	int retorno;
	char bufferChar;

	if(direccion != NULL && mensaje != NULL && mensajeError != NULL)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%c",&bufferChar);

			bufferChar = toupper(bufferChar);

			if(bufferChar >= minimo && bufferChar <= maximo)
			{
				*direccion = bufferChar;
				retorno = 0;
			}
			else
			{
				printf("%s",mensajeError);
				retorno = 1;
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

int pedirCharDosOpciones(char* direccion, char opcionUno, char opcionDos, char mensaje[], char mensajeError[])
{
	int retorno;
	char bufferChar;

	if(direccion != NULL && mensaje != NULL && mensajeError != NULL)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%c",&bufferChar);

			bufferChar = tolower(bufferChar);

			if(bufferChar == opcionUno || bufferChar == opcionDos)
			{
				*direccion = bufferChar;
				retorno = 0;
			}
			else
			{
				printf("%s",mensajeError);
				retorno = 1;
			}
		}while(retorno != 0);
	}
	else
	{
		retorno = -1;
	}

	return retorno;
}


