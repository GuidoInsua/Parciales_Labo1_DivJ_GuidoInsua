
#ifndef FUNCIONESDISTRIBUIDORA_H_
#define FUNCIONESDISTRIBUIDORA_H_

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int idRubro; //PK
	char descripcion[31]; //(1000-ELECTRÓNICA, 1001-BLANCO, 1002-AUDIO, 1003-VIDEO)
}eRubro;

typedef struct
{
	int idArticulo; //PK
	char descripcion[31];
	float medida;
	float precio;
	int rubroId; //FK
	int isEmpty;
}eArticulo;

typedef struct
{
	int idVenta; //PK
	int articuloId; //FK
	int cantidad;
	float precioTotal;
	eFecha fecha; //Anidada
	int isEmpty;
}eVenta;

int mostrarMenu(char* opcion);
int iniciarIsEmpty(eArticulo* articulos,int tamArticulos,eVenta* ventas,int tamVentas);
int buscarArticuloVacio(eArticulo* articulos,int tamArticulos,int* indice);
int existeArticulo(eArticulo* articulos,int tamArticulos);
int altaArticulo(eArticulo* articulos,int tamArticulos,eRubro* rubros,int tamRubros,int* idArticulo);
int listarUnArticulo(eArticulo unArticulo,eRubro* rubros,int tamRubros);
int listarArticulos(eArticulo* articulos,int tamArticulos,eRubro* rubros,int tamRubros);
int buscarRubro(eRubro* rubros,int tamRubros,int idUnRubro,char* descripcion);
int mostrarRubros(eRubro* rubros,int tamRubros);
int pedirRubro(eRubro* rubros,int tamRubros,int* respuesta,char* mensaje,char* mensajeError);
int ordenarArticulosPorRubroDescripcion(eArticulo* articulos, int tamArticulos,eRubro* rubros,int tamRubros);
int buscarArticulo(eArticulo* articulos,int tamArticulos,int id,int* indice);
int darDeBajaArticulo(eArticulo* articulos,int tamArticulos,eRubro* rubros,int tamRubros);
int mostrarMenuModificacion(char* opcion);
int modificarArticulo(eArticulo* articulos,int tamArticulos,eRubro* rubros,int tamRubros);
int opcionesModificacionArticulo(eArticulo* unArticulo);
int buscarVentaVacia(eVenta* ventas,int tamVentas,int* indice);
int pedirFecha(eFecha* fecha, int anioMinimo, int anioMaximo);
int pedirArticulo(eArticulo* articulos,int tamArticulos,int* respuesta,char* mensaje,char* mensajeError);
int altaVenta(eVenta* ventas,int tamVentas,eArticulo* articulos,int tamArticulos,eRubro* rubros,int tamRubros,int* idVenta);
int buscarDescripcionArticulo(eArticulo* articulos,int tamArticulos,int idUnArticulo,char* descripcion);
int ordenarVentasPorFecha(eVenta* ventas, int tamVentas);
int listarUnaVenta(eVenta unaVenta,eArticulo* articulos,int tamArticulos);
int listarVentas(eVenta* ventas,int tamVentas,eArticulo* articulos,int tamArticulos);

#endif /* FUNCIONESDISTRIBUIDORA_H_ */
