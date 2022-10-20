
#ifndef FUNCIONESVENTA_H_
#define FUNCIONESVENTA_H_

typedef struct
{
	int mes;
	int dia;
	int anio;
}eFecha;

typedef struct
{
	int idVenta; //PK
	int articuloId; //FK
	int cantidad;
	float precioTotal;
	eFecha fecha; //Anidada
	int isEmpty;
}eVenta;

/// \fn int iniciarIsEmpty(eArticulo*, int, eVenta*, int)
/// \brief Pone el campo isEmpty del array articulos y ventas en 0
///
/// \param articulos , puntero a array de tipo eArticulo, donde van a estar los articulos cargados
/// \param tamArticulos , int tamanio del array 'articulos' de tipo eArticulo
/// \param ventas , puntero a array de tipo eVentas, donde van a estar las ventas cargadas
/// \param tamVentas , int tamanio del array 'ventas' de tipo eVentas
/// \return , retorna 0 si todo sale correcto, y -1 si se pasa mal algun parametro
int iniciarIsEmpty(eArticulo* articulos,int tamArticulos,eVenta* ventas,int tamVentas);

/// \fn int buscarVentaVacia(eVenta*, int, int*)
/// \brief Recorre el array de ventas, buscando el primer isEmpty en 0, y lo pasa por puntero
///
/// \param ventas , puntero a array de tipo eVentas, donde van a estar las ventas cargadas
/// \param tamVentas , int tamanio del array 'ventas' de tipo eVentas
/// \param indice , int puntero por donde se pasa la posicion de la venta vacia
/// \return , retorna 0 si encuentra una venta vacia y se pasa por puntero, 1 si no se encuentra una venta vacia, y -1 si se pasa mal algun parametro
int buscarVentaVacia(eVenta* ventas,int tamVentas,int* indice);

/// \fn int pedirFecha(eFecha*, int, int)
/// \brief Pide un mes, dia y anio, los valida y los pasa por puntero
///
/// \param fecha , eFecha variable puntero con los campos mes dia y anio, por los que se pasa la fecha ingresada
/// \param anioMinimo , int el menor anio que se permite ingersar
/// \param anioMaximo , int el mayor anio que se permite ingresar
/// \return , retorna 0 si se pasa por puntero la fecha validada, 1 si no se pasa la fecha, y -1 si se pasa mal algun parametro
int pedirFecha(eFecha* fecha, int anioMinimo, int anioMaximo);

/// \fn int pedirArticulo(eArticulo*, int, eRubro*, int, int*, int*)
/// \brief Muestra las articulos ingresados y pide el id, si existe pasa por puntero el id y su indice en el array
///
/// \param articulos , puntero a array de tipo eArticulo, donde van a estar los articulos cargados
/// \param tamArticulos , int tamanio del array 'articulos' de tipo eArticulo
/// \param rubros , puntero a array de tipo eRubro, donde van a estar los distintos rubros
/// \param tamRubros , int tamanio del array 'rubros' de tipo eRubro
/// \param idArticulo , int puntero por donde se pasa el id del articulo
/// \param indice , int puntero por donde se pasa la posicion del articulo en el array
/// \return
int pedirArticulo(eArticulo* articulos,int tamArticulos,eRubro* rubros,int tamRubros,int* idArticulo,int* indice);

/// \fn int altaVenta(eVenta*, int, int*, int)
/// \brief Pide los datos de una venta y los carga en el primer indice del array ventas que este vacio
///
/// \param ventas , puntero a array de tipo eVentas, donde van a estar las ventas cargadas
/// \param tamVentas , int tamanio del array 'ventas' de tipo eVentas
/// \param idVenta , int el id auto incremental de las ventas
/// \param idArticulo , el id del articulo que se esta vendiendo
/// \return , retorna 0 si se carga la venta y se pasan los datos por puntero, 1 si no se carga la venta, -2 si no hay mas espacio en el array ventas, y -1 si se pasa mal algun parametro
int altaVenta(eVenta* ventas,int tamVentas,int* idVenta,int idArticulo);

/// \fn int buscarDescripcionArticulo(eArticulo*, int, int, char*)
/// \brief Recorre el array de articulos comparando con el id pasado por parametro, si lo encuentra pas por puntero la descripcion
///
/// \param articulos , puntero a array de tipo eArticulo, donde van a estar los articulos cargados
/// \param tamArticulos , int tamanio del array 'articulos' de tipo eArticulo
/// \param idUnArticulo , int el id del articulo del cual se quiere la descripcion
/// \param descripcion , char cadena puntero por la cual se pasa la descripcion
/// \return , retorna 0 si se encuentra el atriculo y se pasa la descripcion, 1 si no se encuentra el articulo, y -1 si se pasa mal algun parametro
int buscarDescripcionArticulo(eArticulo* articulos,int tamArticulos,int idUnArticulo,char* descripcion);

/// \fn int ordenarVentasPorFecha(eVenta*, int)
/// \brief Recorre el array de ventas y los ordena por sus fechas, de mayor a menor, anio mes y dia
///
/// \param ventas , puntero a array de tipo eVentas, donde van a estar las ventas cargadas
/// \param tamVentas , int tamanio del array 'ventas' de tipo eVentas
/// \return , retorna 0 si ordena el array, 1 si no hace falta ordenarlo, y -1 si se pasa mal algun parametro
int ordenarVentasPorFecha(eVenta* ventas, int tamVentas);

/// \fn int listarUnaVenta(eVenta, eArticulo*, int)
/// \brief Si existe, imprime la venta pasada por parametro
///
/// \param unaVenta , eVenta la venta que se quiere imprimir
/// \param articulos , puntero a array de tipo eArticulo, donde van a estar los articulos cargados
/// \param tamArticulos , int tamanio del array 'articulos' de tipo eArticulo
/// \return , retorna 0 si la venta existe y la imprime, 1 si la venta no existe, y -1 si se pasa mal algun parametro
int listarUnaVenta(eVenta unaVenta,eArticulo* articulos,int tamArticulos);

/// \fn int listarVentas(eVenta*, int, eArticulo*, int)
/// \brief Imprime todas las ventas cargadas
///
/// \param ventas , puntero a array de tipo eVentas, donde van a estar las ventas cargadas
/// \param tamVentas , int tamanio del array 'ventas' de tipo eVentas
/// \param articulos , puntero a array de tipo eArticulo, donde van a estar los articulos cargados
/// \param tamArticulos , int tamanio del array 'articulos' de tipo eArticulo
/// \return , retorna 0 si sale todo correcto, y -1 si se pasa mal algun parametro
int listarVentas(eVenta* ventas,int tamVentas,eArticulo* articulos,int tamArticulos);

#endif /* FUNCIONESVENTA_H_ */
