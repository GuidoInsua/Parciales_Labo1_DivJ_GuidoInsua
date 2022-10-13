
#ifndef FUNCIONESRUBRO_H_
#define FUNCIONESRUBRO_H_

typedef struct
{
	int idRubro; //PK
	char descripcion[31]; //(1000-ELECTRÓNICA, 1001-BLANCO, 1002-AUDIO, 1003-VIDEO)
}eRubro;

int buscarRubro(eRubro* rubros,int tamRubros,int idUnRubro,char* descripcion);
int mostrarRubros(eRubro* rubros,int tamRubros);
int pedirRubro(eRubro* rubros,int tamRubros,int* respuesta,char* mensaje,char* mensajeError);

#endif /* FUNCIONESRUBRO_H_ */
