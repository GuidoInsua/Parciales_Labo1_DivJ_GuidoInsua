
#ifndef FUNCIONESDEINGRESO_H_
#define FUNCIONESDEINGRESO_H_

/**
 * \fn int pedirEntero(int*, int, int, char[], char[])
 * \brief Pide el ingreso de un numero entro, valida que sea un numero y que este en un rango
 *
 * \param direccion , int puntero donde se va a guardar el numero ingresado
 * \param minimo , int valor minimo que puede ser ingresado
 * \param maximo , int valor maximo que puede ser ingresado
 * \param mensaje , cadena el texto que se quiere imprimir para pedir el numero
 * \param mensajeError , cadena el texto que se quiere imprimir si hay algun error
 * \return Retorna 0 si todo fue exitoso, o -1 si se ingreso mal algun parametro
 */
int pedirEntero(int* direccion, int minimo, int maximo, char* mensaje, char* mensajeError);

/**
 * \fn int pedirShort(short*, int, int, char[], char[])
 * \brief Pide el ingreso de un numero short, valida que sea un numero y que este en un rango
 *
 * \param direccion , int puntero donde se va a guardar el numero ingresado
 * \param minimo , int valor minimo que puede ser ingresado
 * \param maximo , int valor maximo que puede ser ingresado
 * \param mensaje , cadena el texto que se quiere imprimir para pedir el numero
 * \param mensajeError , cadena el texto que se quiere imprimir si hay algun error
 * \return Retorna 0 si todo fue exitoso, o -1 si se ingreso mal algun parametro
 */
int pedirShort(short* direccion, int minimo, int maximo, char* mensaje, char* mensajeError);

/**
 * \fn int pedirFlotante(float*, float, float, char[], char[])
 * \brief Pide el ingreso de un numero flotante, valida que sea un numero y que este en un rango
 *
 * \param direccion , float puntero donde se va a guardar el numero ingresado
 * \param minimo , float valor minimo que puede ser ingresado
 * \param maximo , float valor maximo que puede ser ingresado
 * \param mensaje , cadena el texto que se quiere imprimir para pedir el numero
 * \param mensajeError , cadena el texto que se quiere imprimir si hay algun error
 * \return Retorna 0 si todo fue exitoso, o -1 si se ingreso mal algun parametro
 */
int pedirFlotante(float* direccion, float minimo, float maximo, char* mensaje, char* mensajeError);

/**
 * \fn int pedirStringAlfabetico(char[], int, char[], char[], char)
 * \brief Pide el ingreso de una cadena de texto y valida que sean solo letras
 *
 * \param cadena , array char donde se va a guardar la cadena ingresada
 * \param tam , tamaño de la cadena
 * \param mensaje , cadena de texto que se quiere imprimir para pedir el numero
 * \param mensajeError , cadena de texto que se quiere imprimir si hay algun error
 * \param extendido , 's' cuando permite usar caracteres especiales o 'n' cuando no
 * \return Retorna 0 si todo fue exitoso, o -1 si se ingreso mal algun parametro
 */
int pedirStringAlfabetico(char* cadena, int tam, char* mensaje, char* mensajeError,char extendido);

/**
 * \fn int pedirCaracter(char*, char, char, char*, char*)
 * \brief Pide el ingreso de un caracter y valida que este entre el minimo y maximo de la tabla ASCII
 *
 * \param direccion , char puntero donde se va a guardar el char ingresado
 * \param minimo , char minivo caracter posible
 * \param maximo , char maximo caracter posible
 * \param mensaje , cadena el texto que se quiere imprimir para pedir el numero
 * \param mensajeError , cadena el texto que se quiere imprimir si hay algun error
 * \return Retorna 0 si todo fue exitoso, o -1 si se ingreso mal algun parametro
 */
int pedirCaracter(char* direccion, char minimo, char maximo, char* mensaje, char* mensajeError);

/**
 * \fn int pedirCharDosOpciones(char*, char, char, char[], char[])
 * \brief Pide el ingreso de un caracter y valida que sea una de dos opciones dadas
 *
 * \param direccion , char puntero donde se va a guardar el char ingresado
 * \param opcionUno , char primera opcion que se puede ingresar
 * \param opcionDos , char segunda opcion que se puede ingresar
 * \param mensaje , cadena el texto que se quiere imprimir para pedir el numero
 * \param mensajeError , cadena el texto que se quiere imprimir si hay algun error
 * \return Retorna 0 si todo fue exitoso, o -1 si se ingreso mal algun parametro
 */
int pedirCharDosOpciones(char* direccion, char opcionUno, char opcionDos, char* mensaje, char* mensajeError);

/**
 * \fn int pedirNombreArchivoTexto(char*, int, char*, char*)
 * \brief Pide el ingreso de una cadena y valida que sea un nombre valido para un archivo, tambien agrega la extencion del archivo
 *
 * \param cadena , array char donde se va a guardar la cadena ingresada
 * \param tam , tamaño de la cadena
 * \param mensaje , cadena de texto que se quiere imprimir para pedir el numero
 * \param mensajeError , cadena de texto que se quiere imprimir si hay algun error
 * \return Retorna 0 si todo fue exitoso, o -1 si se ingreso mal algun parametro
 */
int pedirNombreArchivoTexto(char* cadena, int tam, char* mensaje, char* mensajeError);

/**
 * \fn int ConvertirUprLwrExtendido(char*, int)
 * \brief Toma una cadena de texto la pasa todo a minusculo y pone las primeras letras en mayuscula
 *
 * \param cadena , array char que se va a modificar y guardar el resultado
 * \param tam , tamaño de la cadena
 * \return Retorna 0 si todo fue exitoso, o -1 si se ingreso mal algun parametro
 */
int convertirUprLwrExtendido(char* cadena, int tam);

#endif /* FUNCIONESDEINGRESO_H_ */
