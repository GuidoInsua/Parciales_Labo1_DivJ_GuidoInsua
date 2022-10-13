
#ifndef FUNCIONESARTICULO_H_
#define FUNCIONESARTICULO_H_

typedef struct
{
	int idArticulo; //PK
	char descripcion[31];
	float medida;
	float precio;
	int rubroId; //FK
	int isEmpty;
}eArticulo;

typedef int(*tFuncionModificacion) (eArticulo* unArticulo); //Puntero a funcion para modificacion o baja

int mostrarMenu(char* opcion);
int buscarArticuloVacio(eArticulo* articulos,int tamArticulos,int* indice);
int existeArticulo(eArticulo* articulos,int tamArticulos);
int altaArticulo(eArticulo* articulos,int tamArticulos,eRubro* rubros,int tamRubros,int* idArticulo);
int listarUnArticulo(eArticulo unArticulo,eRubro* rubros,int tamRubros);
int listarArticulos(eArticulo* articulos,int tamArticulos,eRubro* rubros,int tamRubros);
int ordenarArticulosPorRubroDescripcion(eArticulo* articulos, int tamArticulos,eRubro* rubros,int tamRubros);
int buscarArticulo(eArticulo* articulos,int tamArticulos,int id,int* indice);
int opcionDarBaja(eArticulo* articulos);
int mostrarMenuModificacion(char* opcion);
int modificarArticulo(eArticulo* articulos,int tamArticulos,eRubro* rubros,int tamRubros,tFuncionModificacion pFuncionOpcion);
int opcionModificar(eArticulo* unArticulo);

#endif /* FUNCIONESARTICULO_H_ */
