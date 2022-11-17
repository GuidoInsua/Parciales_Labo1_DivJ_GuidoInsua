
#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_mostrarMenu(int* opcion);
int controller_cargarComprasDedeTexto(char* path,LinkedList* pArrayListCompras);
int controller_listarCompras(LinkedList* pArrayListCompras);
int controller_listarUnaCompra(eCompras* unaCompra);
int controller_guardarComprasDedeTexto(char* path,LinkedList* pArrayListCompras);
int controller_menuFiltros(int* opcion);
int controller_opcionesDeFiltro(LinkedList* pArrayListaCompras);

#endif /* CONTROLLER_H_ */
