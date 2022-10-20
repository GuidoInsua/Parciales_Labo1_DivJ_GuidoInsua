
#ifndef FUNCIONESARTICULO_H_
#define FUNCIONESARTICULO_H_

#define TAMDESCRIPCION 31

typedef struct
{
	int idRubro; //PK
	char descripcion[TAMDESCRIPCION]; //(1000-ELECTRÓNICA, 1001-BLANCO, 1002-AUDIO, 1003-VIDEO)
}eRubro;

typedef struct
{
	int idArticulo; //PK
	char descripcion[TAMDESCRIPCION];
	float medida;
	float precio;
	int rubroId; //FK
	int isEmpty;
}eArticulo;

typedef int(*tFuncionModificacion) (eArticulo* unArticulo); //Puntero a funcion para modificacion o baja

/// \fn int mostrarMenu(char*)
/// \brief Imprime un menu con las opciones para ABM, y manda por puntero la eleccion
///
/// \param opcion, char puntero donde se guarda la eleccion
/// \return , retorna 0 si sale todo correcto o -1 se se pasa mal algun parametro
int mostrarMenu(char* opcion);

/// \fn int buscarArticuloVacio(eArticulo*, int, int*)
/// \brief Recorre el array de articulos y pasa por parametro el indice del primer articulo con isEmpty en 0
///
/// \param articulos , puntero a array de tipo eArticulo, donde van a estar los articulos cargados
/// \param tamArticulos , int tamanio del array 'articulos' de tipo eArticulo
/// \param indice , int puntero por el cual se pasa la posicion del articulo vacio
/// \return , retorna 0 si se encuentra un articulo vacio, 1 si no se encuentra un articulo vacio y -1 se se pasa mal algun parametro
int buscarArticuloVacio(eArticulo* articulos,int tamArticulos,int* indice);

/// \fn int existeArticulo(eArticulo*, int)
/// \brief Recorre el array de articulos buscando un articulo con isEmpty en 1
///
/// \param articulos , puntero a array de tipo eArticulo, donde van a estar los articulos cargados
/// \param tamArticulos , int tamanio del array 'articulos' de tipo eArticulo
/// \return , retorna 0 si se encuentra un articulo cargado, 1 si no se encuentra un articulo cargado y -1 se se pasa mal algun parametro
int existeArticulo(eArticulo* articulos,int tamArticulos);

/// \fn int buscarDescripcionRubro(eRubro*, int, int, char*)
/// \brief Recorre el array de rubros y compara el id pasado por parametro con los id del array, luego pasa por puntero la descripcion del rubro encontrado
///
/// \param rubros , puntero a array de tipo eRubro, donde van a estar los distintos rubros
/// \param tamRubros , int tamanio del array 'rubros' de tipo eRubro
/// \param idUnRubro , int el id del rubro del cual se desea la descripcion
/// \param descripcion , cadena puntero por donde se pasa la descripcion del rubro
/// \return , retorna 0 si se encuentra un rubro y se pasa la descripcion, 1 si no se encuentra el rubro y -1 se se pasa mal algun parametro
int buscarDescripcionRubro(eRubro* rubros,int tamRubros,int idUnRubro,char* descripcion);

/// \fn int mostrarRubros(eRubro*, int)
/// \brief Imprime todos los rubros
///
/// \param rubros , puntero a array de tipo eRubro, donde van a estar los distintos rubros
/// \param tamRubros , int tamanio del array 'rubros' de tipo eRubro
/// \return , retorna 0 si sale todo correcto y -1 se se pasa mal algun parametro
int mostrarRubros(eRubro* rubros,int tamRubros);

/// \fn int pedirRubro(eRubro*, int, int*, char*, char*)
/// \brief Pide el id de un rubro, y si coincide con un rubro pasa por puntero el id ingresado
///
/// \param rubros , puntero a array de tipo eRubro, donde van a estar los distintos rubros
/// \param tamRubros , int tamanio del array 'rubros' de tipo eRubro
/// \param respuesta , int puntero por donde se pasa el id ingresado
/// \param mensaje , cadena el texto que se quiere imprimir para pedir el id
/// \param mensajeError , cadena el texto que se quiere imprimir si hay algun error
/// \return , retorna 0 si se encuentra un rubro con el mismo id y se pasa la respuesta y -1 si se pasa mal algun parametro
int pedirRubro(eRubro* rubros,int tamRubros,int* respuesta,char* mensaje,char* mensajeError);

/// \fn int altaArticulo(eArticulo*, int, eRubro*, int, int*)
/// \brief Pide los datos de un articulo y los carga en el primer indice del array articulos que este vacio
///
/// \param articulos , puntero a array de tipo eArticulo, donde van a estar los articulos cargados
/// \param tamArticulos , int tamanio del array 'articulos' de tipo eArticulo
/// \param rubros , puntero a array de tipo eRubro, donde van a estar los distintos rubros
/// \param tamRubros , int tamanio del array 'rubros' de tipo eRubro
/// \param idArticulo , int el id auto incremental de los articulos
/// \return retorna 0 si el articulo se carga con exito, 1 si el articulo no se carga, -2 si no hay mas espacio en el array y -1 si se pasa mal algun parametro
int altaArticulo(eArticulo* articulos,int tamArticulos,eRubro* rubros,int tamRubros,int* idArticulo);

/// \fn int listarUnArticulo(eArticulo, eRubro*, int)
/// \brief Si existe, imprime el articulo pasado por parametro
///
/// \param unArticulo , eArticulo el articulo que se quiere imprimir
/// \param rubros , puntero a array de tipo eRubro, donde van a estar los distintos rubros
/// \param tamRubros , int tamanio del array 'rubros' de tipo eRubro
/// \return , retorna 0 si existe y se muestra el articulo, 1 si no existe el articulo y -1 si se pasa mal algun parametro
int listarUnArticulo(eArticulo unArticulo,eRubro* rubros,int tamRubros);

/// \fn int listarArticulos(eArticulo*, int, eRubro*, int)
/// \brief Imprime todos los articulos cargados
///
/// \param articulos , puntero a array de tipo eArticulo, donde van a estar los articulos cargados
/// \param tamArticulos , int tamanio del array 'articulos' de tipo eArticulo
/// \param rubros , puntero a array de tipo eRubro, donde van a estar los distintos rubros
/// \param tamRubros , int tamanio del array 'rubros' de tipo eRubro
/// \return , retorna 0 si sale todo correcto y -1 se se pasa mal algun parametro
int listarArticulos(eArticulo* articulos,int tamArticulos,eRubro* rubros,int tamRubros);

/// \fn int ordenarArticulosPorRubroDescripcion(eArticulo*, int, eRubro*, int)
/// \brief Recorre el array de articulos y los ordena por rubro, a los del mismo rubro los ordena por descripcion
///
/// \param articulos , puntero a array de tipo eArticulo, donde van a estar los articulos cargados
/// \param tamArticulos , int tamanio del array 'articulos' de tipo eArticulo
/// \param rubros , puntero a array de tipo eRubro, donde van a estar los distintos rubros
/// \param tamRubros , int tamanio del array 'rubros' de tipo eRubro
/// \return , retorna 0 si ordena el array correctamente, 1 si no hace falta ordenar nada, y -1 si se pasa mal algun parametro
int ordenarArticulosPorRubroDescripcion(eArticulo* articulos, int tamArticulos,eRubro* rubros,int tamRubros);

/// \fn int buscarArticulo(eArticulo*, int, int, int*)
/// \brief Recorre el array de articulos comparando el id pasado por parametro, si se encuentra el articulo pasa por puntero el indice donde se encuentra
///
/// \param articulos , puntero a array de tipo eArticulo, donde van a estar los articulos cargados
/// \param tamArticulos , int tamanio del array 'articulos' de tipo eArticulo
/// \param id , int id del articulo que se esta buscando
/// \param indice , int puntero por donde se pasa la posicion del array en la que se encuentra el articulo
/// \return , retorna 0 si se encuentra el articulo y se pasa por puntero, 1 si no se encuentra el articulo y -1 si se pasa mal algun parametro
int buscarArticulo(eArticulo* articulos,int tamArticulos,int id,int* indice);

/// \fn int opcionDarBaja(eArticulo*)
/// \brief Pregunta si se quiere dar de baja el articulo pasado por puntero, y pone isEmpty en 0 si se ingresa 's' o sino no se modifica el isEmpty
///
/// \param unArticulo , eArticulo el articulo que se quiere dar de baja
/// \return , retorna 0 si el articulo se da de baja, 1 si el articulo no se da de baja, y -1 si se pasa mal algun parametro
int opcionDarBaja(eArticulo* unArticulo);

/// \fn int mostrarMenuModificacion(char*)
/// \brief Imprime un menu con las opciones para modificar un articulo, y manda por puntero la eleccion
///
/// \param opcion, char puntero donde se guarda la eleccion
/// \return , retorna 0 si sale todo correcto o -1 se se pasa mal algun parametro
int mostrarMenuModificacion(char* opcion);

/// \fn int modificarArticulo(eArticulo*, int, eRubro*, int, tFuncionModificacion)
/// \brief Pide un articulo y llama a la funcion pasado por puntero, para modificar un articulo o darlo de baja
///
/// \param articulos , puntero a array de tipo eArticulo, donde van a estar los articulos cargados
/// \param tamArticulos , int tamanio del array 'articulos' de tipo eArticulo
/// \param rubros , puntero a array de tipo eRubro, donde van a estar los distintos rubros
/// \param tamRubros , int tamanio del array 'rubros' de tipo eRubro
/// \param pFuncionOpcion , puntero a funcion del tipo tFuncionModificacion, la cual se va a llamar pasandole un articulo
/// \return , retorna 0 si se llama a la funcion exitosamente, 1 si hay un error al pedir el articulo, y -1 si se pasa mal algun parametro
int modificarArticulo(eArticulo* articulos,int tamArticulos,eRubro* rubros,int tamRubros,tFuncionModificacion pFuncionOpcion);

/// \fn int opcionModificar(eArticulo*)
/// \brief Dependiendo de que se desa modificar llama a la respectiva funcion para modificar el articulo pasado por puntero
///
/// \param unArticulo , eArticulo el articulo que se quiere modificar
/// \return , retorna 0 si todo salio exitosamente, y -1 si se paso mal algun parametro
int opcionModificar(eArticulo* unArticulo);

#endif /* FUNCIONESARTICULO_H_ */
