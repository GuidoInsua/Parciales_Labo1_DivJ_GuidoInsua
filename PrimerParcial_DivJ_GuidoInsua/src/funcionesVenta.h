
#ifndef FUNCIONESVENTA_H_
#define FUNCIONESVENTA_H_

typedef struct
{
	int idVenta; //PK
	int articuloId; //FK
	int cantidad;
	float precioTotal;
	eFecha fecha; //Anidada
	int isEmpty;
}eVenta;

int iniciarIsEmpty(eArticulo* articulos,int tamArticulos,eVenta* ventas,int tamVentas);
int buscarVentaVacia(eVenta* ventas,int tamVentas,int* indice);
int pedirArticulo(eArticulo* articulos,int tamArticulos,int* respuesta,char* mensaje,char* mensajeError);
int altaVenta(eVenta* ventas,int tamVentas,eArticulo* articulos,int tamArticulos,eRubro* rubros,int tamRubros,int* idVenta);
int buscarDescripcionArticulo(eArticulo* articulos,int tamArticulos,int idUnArticulo,char* descripcion);
int ordenarVentasPorFecha(eVenta* ventas, int tamVentas);
int listarUnaVenta(eVenta unaVenta,eArticulo* articulos,int tamArticulos);
int listarVentas(eVenta* ventas,int tamVentas,eArticulo* articulos,int tamArticulos);

#endif /* FUNCIONESVENTA_H_ */
