
#ifndef FUNCIONESINFORME_H_
#define FUNCIONESINFORME_H_

/// \fn int mostrarMenuInformes(char*)
/// \brief Imprime un menu con las opciones para informar, y manda por puntero la eleccion
///
/// \param opcion, char puntero donde se guarda la eleccion
/// \return , retorna 0 si sale todo correcto o -1 se se pasa mal algun parametro
int mostrarMenuInformes(char* opcion);

/// \fn int listarInformes(eArticulo*, int, eRubro*, int, eVenta*, int, int)
/// \brief Llama a las distintas funciones de informe dependiendo la opcion con un switch
///
/// \param articulos , puntero a array de tipo eArticulo, donde van a estar los articulos cargados
/// \param tamArticulos , int tamanio del array 'articulos' de tipo eArticulo
/// \param rubros , puntero a array de tipo eRubro, donde van a estar los distintos rubros
/// \param tamRubros , int tamanio del array 'rubros' de tipo eRubro
/// \param ventas , puntero a array de tipo eVentas, donde van a estar las ventas cargadas
/// \param tamVentas , int tamanio del array 'ventas' de tipo eVentas
/// \param idVentas , int el id auto incremental de las ventas, para sabir si se cargo una venta
/// \return , retorna 0 si sale todo correcto o -1 se se pasa mal algun parametro
int listarInformes(eArticulo* articulos,int tamArticulos,eRubro* rubros,int tamRubros,eVenta* ventas,int tamVentas,int idVentas);

/// \fn int listarArticulosDeUnRubro(eArticulo*, int, eRubro*, int)
/// \brief Pide un rubro e imprime todos los articulos cargados con ese rubro
///
/// \param articulos , puntero a array de tipo eArticulo, donde van a estar los articulos cargados
/// \param tamArticulos , int tamanio del array 'articulos' de tipo eArticulo
/// \param rubros , puntero a array de tipo eRubro, donde van a estar los distintos rubros
/// \param tamRubros , int tamanio del array 'rubros' de tipo eRubro
/// \return , retorna 0 si encuentra e imprime un articulo, 1 si sale todo correcto pero no se encuentra ningun articulo, y -1 se se pasa mal algun parametro
int listarArticulosDeUnRubro(eArticulo* articulos,int tamArticulos,eRubro* rubros,int tamRubros);

/// \fn int listarFechasCargadas(eVenta*, int)
/// \brief Imprime todas las fechas de las ventas cargadas
///
/// \param ventas , puntero a array de tipo eVentas, donde van a estar las ventas cargadas
/// \param tamVentas , int tamanio del array 'ventas' de tipo eVentas
/// \return , retorna 0 si encuentra e imprime una fecha, 1 si sale todo correcto pero no se encuentra ninguna fecha, y -1 se se pasa mal algun parametro
int listarFechasCargadas(eVenta* ventas,int tamVentas);

/// \fn int listarVentasDeUnaFecha(eVenta*, int, eArticulo*, int)
/// \brief Pide una fecha e imprime todas las ventas cargadas con esa fecha
///
/// \param ventas , puntero a array de tipo eVentas, donde van a estar las ventas cargadas
/// \param tamVentas , int tamanio del array 'ventas' de tipo eVentas
/// \param articulos , puntero a array de tipo eArticulo, donde van a estar los articulos cargados
/// \param tamArticulos , int tamanio del array 'articulos' de tipo eArticulo
/// \return , retorna 0 si encuentra e imprime una venta con la fecha ingresada, 1 si sale todo correcto pero no se encuentra ninguna venta, -2 si no existen ventas, y -1 se se pasa mal algun parametro
int listarVentasDeUnaFecha(eVenta* ventas,int tamVentas,eArticulo* articulos,int tamArticulos);

/// \fn int mostrarImporteVentasUnArticulo(eVenta*, int, int)
/// \brief Busca las ventas cargadas con el id del articulo pasado por parametro, suma los importes totales e imprime el resultado
///
/// \param ventas , puntero a array de tipo eVentas, donde van a estar las ventas cargadas
/// \param tamVentas , int tamanio del array 'ventas' de tipo eVentas
/// \param idArticulo , int el id del articulo el cual se quiere buscar las ventas
/// \return , retorna 0 si encuentra una venta con el articulo y se imprime el resultado, 1 si sale todo correcto pero no se encuentra ninguna venta, y -1 se se pasa mal algun parametro
int mostrarImporteVentasUnArticulo(eVenta* ventas,int tamVentas,int idArticulo);

/// \fn int mostrarImporteVentasUnRubroFecha(eVenta*, int, eArticulo*, int, eRubro*, int)
/// \brief Pide una fecha y un rubro, busca las ventas cargadas con esos datos, suma los importes totales e imprime el resultado
///
/// \param ventas , puntero a array de tipo eVentas, donde van a estar las ventas cargadas
/// \param tamVentas , int tamanio del array 'ventas' de tipo eVentas
/// \param articulos , puntero a array de tipo eArticulo, donde van a estar los articulos cargados
/// \param tamArticulos , int tamanio del array 'articulos' de tipo eArticulo
/// \param rubros , puntero a array de tipo eRubro, donde van a estar los distintos rubros
/// \param tamRubros , int tamanio del array 'rubros' de tipo eRubro
/// \return , retorna 0 si encuentra una venta con los misimos datos y se imprime el resultado, 1 si sale todo correcto pero no se encuentra ninguna venta, y -1 se se pasa mal algun parametro
int mostrarImporteVentasUnRubroFecha(eVenta* ventas,int tamVentas,eArticulo* articulos,int tamArticulos,eRubro* rubros,int tamRubros);

#endif /* FUNCIONESINFORME_H_ */
