
#ifndef FUNCIONESFECHA_H_
#define FUNCIONESFECHA_H_

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

int pedirFecha(eFecha* fecha, int anioMinimo, int anioMaximo);

#endif /* FUNCIONESFECHA_H_ */
