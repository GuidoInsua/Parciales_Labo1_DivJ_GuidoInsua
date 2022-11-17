
#ifndef COMPRAS_H_
#define COMPRAS_H_

#define TAMDESCRIPCION 100

typedef struct
{
	int codigoCompra;
	char descripcion[TAMDESCRIPCION];
	int origen;
	int precioUnitario;
	int cantidad;
	int totalCompra;
}eCompras;

eCompras* comp_new();
eCompras* comp_newParametros(char* codigo,char* descripcion,char* origen,char* precio,char* cantidad,char* totalCompra);

void comp_delete(eCompras* this);

int comp_setCodigo(eCompras* this,int codigo);
int comp_getCodigo(eCompras* this,int* codigo);
int comp_setDescripcion(eCompras* this,char* descripcion);
int comp_getDescripcion(eCompras* this,char* descripcion);
int comp_setOrigen(eCompras* this,int origen);
int comp_getOrigen(eCompras* this,int* origen);
int comp_setPrecioUnitario(eCompras* this,int precio);
int comp_getPrecioUnitario(eCompras* this,int* precio);
int comp_setCantidad(eCompras* this,int cantidad);
int comp_getCantidad(eCompras* this,int* cantidad);
int comp_setTotalCompra(eCompras* this,int totalCompra);
int comp_getTotalCompra(eCompras* this,int* totalCompra);
void* comp_calacularTotalCompra(void* unaCompra);
int comp_filtrarComprasPorAdministracion(void* unaCompra);
int comp_filtrarComprasPorTaller(void* unaCompra);
int comp_filtrarComprasPorVentas(void* unaCompra);
int comp_ordenarComprasPorCodigo(void* primerCompra,void* segundaCompra);
int comp_ordenarComprasPorDescripcion(void* primerCompra,void* segundaCompra);
int comp_ordenarComprasPorOrigen(void* primerCompra,void* segundaCompra);

#endif /* COMPRAS_H_ */
