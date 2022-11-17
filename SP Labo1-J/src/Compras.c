
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

/// \fn eCompras comp_new*()
/// \brief Pide espacio en memoria para una venta e inicializa sus variables en 0
///
/// \return Retorna NULL si no encuentra memoria o la direccion de memoria encontrada
eCompras* comp_new()
{
	return (eCompras*) calloc(1,sizeof(eCompras));
}

//-----------------------------------------------------------------------------------------------

/// \fn eCompras comp_newParametros*(char*, char*, char*, char*, char*, char*)
/// \brief Toma los datos pasados por parametro y los guarda dentro de los campos de una compra
///
/// \param codigo , puntero cadena por donde se pasa el campo 'codigo' de una compra
/// \param descripcion , puntero cadena por donde se pasa el campo 'descripcion' de una compra
/// \param origen , puntero cadena por donde se pasa el campo 'origen' de una compra
/// \param precio , puntero cadena por donde se pasa el campo 'precioUnitario' de una compra
/// \param cantidad , puntero cadena por donde se pasa el campo 'cantidad' de una compra
/// \param totalCompra , puntero cadena por donde se pasa el campo 'totalCompra' de una compra
/// \return Retorna NULL si no encuentra memoria o el puntero a la compra cargada
eCompras* comp_newParametros(char* codigo,char* descripcion,char* origen,char* precio,char* cantidad,char* totalCompra)
{
	eCompras* unaCompra = NULL;

	if(codigo != NULL && descripcion != NULL && origen != NULL && precio != NULL && cantidad != NULL && totalCompra != NULL)
	{
		unaCompra = comp_new();

		if(unaCompra != NULL)
		{
			if( comp_setCodigo(unaCompra, atoi(codigo)) != 0 || comp_setDescripcion(unaCompra, descripcion) != 0 ||
				comp_setOrigen(unaCompra, atoi(origen)) != 0 || comp_setPrecioUnitario(unaCompra, atoi(precio)) != 0 ||
				comp_setCantidad(unaCompra, atoi(cantidad)) != 0 || comp_setTotalCompra(unaCompra, atoi(totalCompra)) != 0)
			{
				comp_delete(unaCompra);
				unaCompra = NULL;
			}
		}
	}

	return unaCompra;
}

//-----------------------------------------------------------------------------------------------

/// \fn void comp_delete(eCompras*)
/// \brief Libera el espacio en memoria de una compra
///
/// \param this , eCompra puntero a la compra que se quiere borrar
void comp_delete(eCompras* this)
{
	if(this != NULL)
	{
		free(this);
	}
	else
	{
		printf("\nERROR, can't free NULL");
	}
}

//-----------------------------------------------------------------------------------------------

/// \fn int comp_setCodigo(eCompras*, int)
/// \brief Toma la compra y guarda dentro del campo 'codigo' el valor pasado por parametro
///
/// \param this , eCompra puntero a la compra
/// \param codigo , int el valor que se quiere guardar dentro del campo codigo
/// \return retorna 0 si todo salio bien o -1 si se paso mal algun parametro
int comp_setCodigo(eCompras* this,int codigo)
{
	int retorno;

	retorno = -1;

	if(this != NULL && codigo >= 0)
	{
		this->codigoCompra = codigo;
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int comp_getCodigo(eCompras*, int*)
/// \brief Toma la compra y pasa por puntero el valor encontrado en el campo 'codigo'
///
/// \param this , eCompra puntero a la compra
/// \param codigo , puntero int donde se va a guardar el valor encontrado
/// \return retorna 0 si todo salio bien o -1 si se paso mal algun parametro
int comp_getCodigo(eCompras* this,int* codigo)
{
	int retorno;

	retorno = -1;

	if(this != NULL && codigo != NULL)
	{
		*codigo = this->codigoCompra;
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int comp_setDescripcion(eCompras*, char*)
/// \brief Toma la compra y guarda dentro del campo 'descripcion' la cadena pasada por parametro
///
/// \param this , eCompra puntero a la compra
/// \param descripcion , puntero char la cadena que se quiere guardar dentro del campo descripcion
/// \return retorna 0 si todo salio bien o -1 si se paso mal algun parametro
int comp_setDescripcion(eCompras* this,char* descripcion)
{
	int retorno;

	retorno = -1;

	if(this != NULL && descripcion != NULL)
	{
		strcpy(this->descripcion,descripcion);
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int comp_getDescripcion(eCompras*, char*)
/// \brief Toma la compra y pasa por puntero la cadena encontrada en el campo 'descripcion'
///
/// \param this , eCompra puntero a la compra
/// \param descripcion , puntero char la cadena donde se va a guardar el campo 'descripcion'
/// \return retorna 0 si todo salio bien o -1 si se paso mal algun parametro
int comp_getDescripcion(eCompras* this,char* descripcion)
{
	int retorno;

	retorno = -1;

	if(this != NULL && descripcion != NULL)
	{
		strcpy(descripcion,this->descripcion);
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int comp_setOrigen(eCompras*, int)
/// \brief Toma la compra y guarda dentro del campo 'origen' el valor pasado por parametro
///
/// \param this , eCompra puntero a la compra
/// \param origen , int el valor que se quiere guardar dentro del campo origen
/// \return retorna 0 si todo salio bien o -1 si se paso mal algun parametro
int comp_setOrigen(eCompras* this,int origen)
{
	int retorno;

	retorno = -1;

	if(this != NULL && origen >= 0)
	{
		this->origen = origen;
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int comp_getOrigen(eCompras*, int*)
/// \brief Toma la compra y pasa por puntero el valor encontrado en el campo 'origen'
///
/// \param this , eCompra puntero a la compra
/// \param origen , puntero int donde se va a guardar el valor encontrado
/// \return retorna 0 si todo salio bien o -1 si se paso mal algun parametro
int comp_getOrigen(eCompras* this,int* origen)
{
	int retorno;

	retorno = -1;

	if(this != NULL && origen != NULL)
	{
		*origen = this->origen;
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int comp_setPrecioUnitario(eCompras*, int)
/// \brief Toma la compra y guarda dentro del campo 'precioUnitario' el valor pasado por parametro
///
/// \param this , eCompra puntero a la compra
/// \param precio , int el valor que se quiere guardar dentro del campo precio
/// \return retorna 0 si todo salio bien o -1 si se paso mal algun parametro
int comp_setPrecioUnitario(eCompras* this,int precio)
{
	int retorno;

	retorno = -1;

	if(this != NULL && precio >= 0)
	{
		this->precioUnitario = precio;
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int comp_getPrecioUnitario(eCompras*, int*)
/// \brief Toma la compra y pasa por puntero el valor encontrado en el campo 'precioUnitario'
///
/// \param this , eCompra puntero a la compra
/// \param precio , puntero int donde se va a guardar el valor encontrado
/// \return retorna 0 si todo salio bien o -1 si se paso mal algun parametro
int comp_getPrecioUnitario(eCompras* this,int* precio)
{
	int retorno;

	retorno = -1;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precioUnitario;
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int comp_setCantidad(eCompras*, int)
/// \brief Toma la compra y guarda dentro del campo 'cantidad' el valor pasado por parametro
///
/// \param this , eCompra puntero a la compra
/// \param cantidad , int el valor que se quiere guardar dentro del campo cantidad
/// \return retorna 0 si todo salio bien o -1 si se paso mal algun parametro
int comp_setCantidad(eCompras* this,int cantidad)
{
	int retorno;

	retorno = -1;

	if(this != NULL && cantidad >= 0)
	{
		this->cantidad = cantidad;
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int comp_getCantidad(eCompras*, int*)
/// \brief Toma la compra y pasa por puntero el valor encontrado en el campo 'cantidad'
///
/// \param this , eCompra puntero a la compra
/// \param cantidad , puntero int donde se va a guardar el valor encontrado
/// \return retorna 0 si todo salio bien o -1 si se paso mal algun parametro
int comp_getCantidad(eCompras* this,int* cantidad)
{
	int retorno;

	retorno = -1;

	if(this != NULL && cantidad != NULL)
	{
		*cantidad = this->cantidad;
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int comp_setTotalCompra(eCompras*, int)
/// \brief Toma la compra y guarda dentro del campo 'totalCompra' el valor pasado por parametro
///
/// \param this , eCompra puntero a la compra
/// \param totalCompra , int el valor que se quiere guardar dentro del campo totalCompra
/// \return retorna 0 si todo salio bien o -1 si se paso mal algun parametro
int comp_setTotalCompra(eCompras* this,int totalCompra)
{
	int retorno;

	retorno = -1;

	if(this != NULL && totalCompra >= 0)
	{
		this->totalCompra = totalCompra;
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int comp_getTotalCompra(eCompras*, int*)
/// \brief Toma la compra y pasa por puntero el valor encontrado en el campo 'totalCompra'
///
/// \param this , eCompra puntero a la compra
/// \param totalCompra , puntero int donde se va a guardar el valor encontrado
/// \return retorna 0 si todo salio bien o -1 si se paso mal algun parametro
int comp_getTotalCompra(eCompras* this,int* totalCompra)
{
	int retorno;

	retorno = -1;

	if(this != NULL && totalCompra != NULL)
	{
		*totalCompra = this->totalCompra;
		retorno = 0;
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn void comp_calacularTotalCompra*(void*)
/// \brief Calcula el totalCompra multiplicando la cantidad por el precio y guarda los datos en una nueva compra
///
/// \param unaCompra , puntero void donde se encuentra la compra
void* comp_calacularTotalCompra(void* unaCompra)
{
	int bufferCodigo;
	char bufferDescripcion[TAMDESCRIPCION];
	int bufferOrigen;
	int bufferPrecio;
	int bufferCantidad;
	int bufferTotalCompra;
	eCompras* retornoCompra = NULL;

	if(unaCompra != NULL)
	{
		retornoCompra = comp_new();

		comp_getCodigo(unaCompra, &bufferCodigo);
		comp_getDescripcion(unaCompra, bufferDescripcion);
		comp_getOrigen(unaCompra, &bufferOrigen);
		comp_getPrecioUnitario(unaCompra, &bufferPrecio);
		comp_getCantidad(unaCompra, &bufferCantidad);

		bufferTotalCompra = bufferCantidad * bufferPrecio;

		//comp_setTotalCompra(unaCompra, bufferTotalCompra); // Quitar comentario para setear el total en la lista original

		comp_setCodigo(retornoCompra, bufferCodigo);
		comp_setDescripcion(retornoCompra, bufferDescripcion);
		comp_setOrigen(retornoCompra, bufferOrigen);
		comp_setPrecioUnitario(retornoCompra, bufferPrecio);
		comp_setCantidad(retornoCompra, bufferCantidad);
		comp_setTotalCompra(retornoCompra, bufferTotalCompra);
	}

	return retornoCompra;
}

//-----------------------------------------------------------------------------------------------

/// \fn int comp_filtrarComprasPorAdministracion(void*)
/// \brief Compara el campo origen, cuando es igual a 1 (administracion)
///
/// \param unaCompra , puntero void donde se encuentra la compra
/// \return retorna 1 si la comparacion es igual, 0 si son distintos
int comp_filtrarComprasPorAdministracion(void* unaCompra)
{
	int bufferOrigen;
	int retorno;

	retorno = 0;

	if(unaCompra != NULL)
	{
		comp_getOrigen(unaCompra, &bufferOrigen);

		if(bufferOrigen == 1)
		{
			retorno = 1;
		}
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int comp_filtrarComprasPorTaller(void*)
/// \brief Compara el campo origen, cuando es igual a 2 (taller)
///
/// \param unaCompra , puntero void donde se encuentra la compra
/// \return retorna 1 si la comparacion es igual, 0 si son distintos
int comp_filtrarComprasPorTaller(void* unaCompra)
{
	int bufferOrigen;
	int retorno;

	retorno = 0;

	if(unaCompra != NULL)
	{
		comp_getOrigen(unaCompra, &bufferOrigen);

		if(bufferOrigen == 2)
		{
			retorno = 1;
		}
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int comp_filtrarComprasPorVentas(void*)
/// \brief Compara el campo origen, cuando es igual a 3 (ventas)
///
/// \param unaCompra , puntero void donde se encuentra la compra
/// \return retorna 1 si la comparacion es igual, 0 si son distintos
int comp_filtrarComprasPorVentas(void* unaCompra)
{
	int bufferOrigen;
	int retorno;

	retorno = 0;

	if(unaCompra != NULL)
	{
		comp_getOrigen(unaCompra, &bufferOrigen);

		if(bufferOrigen == 3)
		{
			retorno = 1;
		}
	}

	return retorno;
}

//-----------------------------------------------------------------------------------------------

/// \fn int comp_ordenarComprasPorCodigo(void*, void*)
/// \brief Criterio para ordenar la lista compras por codigo
///
/// \param primerCompra , puntero void donde se encuentra la primer compra
/// \param segundaCompra , puntero void donde se encuentra la segunda compra
/// \return retorna 1 si el primero es mayor al sgundo -1 si el primero es menor al segundo
int comp_ordenarComprasPorCodigo(void* primerCompra,void* segundaCompra)
{
	int primerCodigo;
	int segundoCodigo;

	if(primerCompra != NULL && segundaCompra != NULL)
	{
		comp_getCodigo(primerCompra, &primerCodigo);
		comp_getCodigo(segundaCompra, &segundoCodigo);

		if(primerCodigo > segundoCodigo)
		{
			return 1;
		}
		if(primerCodigo < segundoCodigo)
		{
			return -1;
		}
	}
	return 0;
}

//-----------------------------------------------------------------------------------------------

/// \fn int comp_ordenarComprasPorDescripcion(void*, void*)
/// \brief Criterio para ordenar la lista compras por descripcion
///
/// \param primerCompra , puntero void donde se encuentra la primer compra
/// \param segundaCompra , puntero void donde se encuentra la segunda compra
/// \return retorna 1 si el primero es mayor al sgundo -1 si el primero es menor al segundo
int comp_ordenarComprasPorDescripcion(void* primerCompra,void* segundaCompra)
{
	char primeraDescripcion[TAMDESCRIPCION];
	char segundaDescripcion[TAMDESCRIPCION];

	if(primerCompra != NULL && segundaCompra != NULL)
	{
		comp_getDescripcion(primerCompra, primeraDescripcion);
		comp_getDescripcion(segundaCompra, segundaDescripcion);

		if(strcmp(primeraDescripcion,segundaDescripcion) > 0)
		{
			return 1;
		}
		if(strcmp(primeraDescripcion,segundaDescripcion) < 0)
		{
			return -1;
		}
	}
	return 0;
}

//-----------------------------------------------------------------------------------------------

/// \fn int comp_ordenarComprasPorOrigen(void*, void*)
/// \brief Criterio para ordenar la lista compras por origen
///
/// \param primerCompra , puntero void donde se encuentra la primer compra
/// \param segundaCompra , puntero void donde se encuentra la segunda compra
/// \return retorna 1 si el primero es mayor al sgundo -1 si el primero es menor al segundo
int comp_ordenarComprasPorOrigen(void* primerCompra,void* segundaCompra)
{
	int primerOrigen;
	int segundoOrigen;

	if(primerCompra != NULL && segundaCompra != NULL)
	{
		comp_getOrigen(primerCompra, &primerOrigen);
		comp_getOrigen(segundaCompra, &segundoOrigen);

		if(primerOrigen > segundoOrigen)
		{
			return 1;
		}
		if(primerOrigen < segundoOrigen)
		{
			return -1;
		}
	}
	return 0;
}

//-----------------------------------------------------------------------------------------------
