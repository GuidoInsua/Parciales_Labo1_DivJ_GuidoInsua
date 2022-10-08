
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
	char descripcion[31]; //(1-ELECTRÓNICA, 2-BLANCO, 3-AUDIO, 4-VIDEO)
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

int mostrarMenu(int* opcion);
int iniciarIsEmpty(eArticulo* articulos,int tamArticulos,eVenta* ventas,int tamVentas);
int buscarArticulo(eArticulo* articulos,int tamArticulos,int* indice);
int altaArticulo(eArticulo* articulos,int tamArticulos,eRubro* rubros,int tamRubros,int* idArticulo);
int listarUnArticulo(eArticulo unArticulo,eRubro* rubros,int tamRubros);
int listarArticulos(eArticulo* articulos,int tamArticulos,eRubro* rubros,int tamRubros);
int buscarRubro(eRubro* rubros,int tamRubros,int idUnRubro,char* descripcion);
int mostrarRubros(eRubro* rubros,int tamRubros);
int pedirRubro(eRubro* rubros,int tamRubros,int* respuesta,char mensaje[],char mensajeError[]);

#endif /* FUNCIONESDISTRIBUIDORA_H_ */
