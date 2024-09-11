/* Este codigo ha sido generado por el modulo psexport 20180802-w32 de PSeInt.
Es posible que el codigo generado no sea completamente correcto. Si encuentra
errores por favor reportelos en el foro (http://pseint.sourceforge.net). */

#include<stdio.h>

/* En C no hay variables para guardar cadenas de texto, sino que debe construirse
   un arreglo de caracteres (tipo char). El tama�o del arreglo determina la longitud
   m�xima que puede tener la cadena que guarda (tama�o-1, por el caracter de terminaci�n).
   La constante MAX_STRLEN define el tama�o m�ximo que se utiliza en este programa para
   cualquier cadena. */
#define MAX_STRLEN 256

/* Para las variables que no se pudo determinar el tipo se utiliza la constante
   SIN_TIPO. El usuario debe reemplazar sus ocurrencias por el tipo adecuado
   (usualmente int,float,bool, o char[]). */
#define SIN_TIPO float

// Declaraciones adelantadas de las funciones
void cargardatosiniciales(char *aeropuerto[], char *empleado[]);
void cargadeusuario(int codaeropuerto, int codempleado, float totalventasaep[], float totalventasempleado[], float nrodepasajerosaep[], float nrodepasajerosempleado[]);
void mostrardatos(SIN_TIPO aeropuerto[], SIN_TIPO empleado[], SIN_TIPO totalventasaep[], SIN_TIPO totalventasempleado[], SIN_TIPO nrodepasajerosaep[], SIN_TIPO nrodepasajerosempleado[]);
void rankingventasaep(SIN_TIPO totalventasaep[]);

/* Una l�nea a�rea, American Airlines, vende pasajes en 3 aeropuertos: "Uruguay", "Per�" y */
/* "Brasil". En cada uno de ellos, hay 3 empleados que efect�an las ventas. Cada vez que un */
/* cliente compra pasajes, se requiere la siguiente informaci�n: */
/* ? N�mero de Aeropuerto */
/* ? N�mero de Empleado */
/* ? Valor del pasaje */
/* ? Cantidad de pasajeros */
/* Se pide calcular: */
/* a) La cantidad de pasajes vendidos por cada empleado. */
/* b) La recaudaci�n por cada aeropuerto. */
/* c) El n�mero de empleado que haya vendido la mayor cantidad de pasajes. */
/* d) La cantidad de pasajes vendidos por aeropuerto. */
/* e) El porcentaje de ventas en pesos de cada empleado. */
/* f) El porcentaje de ventas por aeropuerto. */
/* g) Ranking de ventas por Aeropuerto de Ordenado de mayor a Menor. */
/* La carga de datos finalizar� cuando se ingrese un n�mero de aeropuerto igual a cero. */
int main() {
	char aeropuerto[MAX_STRLEN][3];
	int codaeropuerto;
	int codempleado;
	char empleado[MAX_STRLEN][9];
	int nrodepasajerosaep[3];
	int nrodepasajerosempleado[9];
	float totalventasaep[3];
	float totalventasempleado[9];
	float valorpasaje;
	cargardatosiniciales(aeropuerto,empleado);
	cargadeusuario(codaeropuerto,codempleado,totalventasaep,totalventasempleado,nrodepasajerosaep,nrodepasajerosempleado);
	mostrardatos(aeropuerto,empleado,totalventasaep,totalventasempleado,nrodepasajerosaep,nrodepasajerosempleado);
	rankingventasaep(totalventasaep);
	return 0;
}

void cargardatosiniciales(char *aeropuerto[], char *empleado[]) {
	aeropuerto[0] = "Uruguay";
	aeropuerto[1] = "Peru";
	aeropuerto[2] = "Brasil";
	/* ----------------------- */
	empleado[0] = "Lopez";
	empleado[1] = "Perez";
	empleado[2] = "Aguilar";
	empleado[3] = "Gonzalez";
	empleado[4] = "Gomez";
	empleado[5] = "Rodriguez";
	empleado[6] = "Fernandez";
	empleado[7] = "Diaz";
	empleado[8] = "Martinez";
}

void cargadeusuario(int codaeropuerto, int codempleado, float totalventasaep[], float totalventasempleado[], float nrodepasajerosaep[], float nrodepasajerosempleado[]) {
	int pasajeros;
	float valorpasaje;
	codaeropuerto = 1;
	codempleado = 1;
	printf("Ingrese el Codigo de Aeropuerto (1, 2 o 3). Ingrese 0 para finalizar la carga\n");
	do {
		printf("Ingrese el codigo de Aeropuerto\n");
		scanf("%f",&codaeropuerto);
		while (codaeropuerto!=1 && codaeropuerto!=2 && codaeropuerto!=3 && codaeropuerto!=0) {
			printf("El codigo de Aeropuerto es invalido, ingrese 1, 2 o 3\n");
			printf("Ingrese el codigo de Aeropuerto\n");
			scanf("%f",&codaeropuerto);
		}
		if (codaeropuerto!=0) {
			printf("Ingrese el codigo de Empleado\n");
			scanf("%f",&codempleado);
			if (codempleado<1 || codempleado>9) {
				printf("El codigo de Empleado es invalido, ingrese un codigo entre 1 y 9\n");
				printf("Ingrese el codigo de Empleado\n");
				scanf("%f",&codempleado);
			}
			if (codempleado>=1 && codempleado<=9) {
				printf("Ingrese el valor total de los pasajes\n");
				scanf("%f",&valorpasaje);
				totalventasaep[codaeropuerto-1] = totalventasaep[codaeropuerto-1]+valorpasaje;
				totalventasempleado[codempleado-1] = totalventasempleado[codempleado-1]+valorpasaje;
				printf("Ingrese la cantidad de pasajeros\n");
				scanf("%i",&pasajeros);
				nrodepasajerosaep[codaeropuerto-1] = nrodepasajerosaep[codaeropuerto-1]+pasajeros;
				nrodepasajerosempleado[codempleado-1] = nrodepasajerosempleado[codempleado-1]+pasajeros;
			}
		}
	} while (codaeropuerto!=0);
}

void mostrardatos(SIN_TIPO aeropuerto[], SIN_TIPO empleado[], SIN_TIPO totalventasaep[], SIN_TIPO totalventasempleado[], SIN_TIPO nrodepasajerosaep[], SIN_TIPO nrodepasajerosempleado[]) {
	int i;
	printf(" \n");
	for (i=0;i<=3-1;i+=1) {
		printf("Aeropuerto: %s\n",aeropuerto[i]);
		printf("Total de Ventas: %s\n",totalventasaep[i]);
		printf("Pasajes vendidos: %s\n",nrodepasajerosaep[i]);
	}
	printf(" \n");
	for (i=0;i<=9-1;i+=1) {
		printf("Empleado:%s\n",empleado[i]);
		printf("Total de Ventas: %s\n",totalventasempleado[i]);
		printf("Pasajes vendidos: %s\n",nrodepasajerosempleado[i]);
	}
}

void rankingventasaep(SIN_TIPO totalventasaep[]) {
	float aux;
	int i;
	int j;
	float rankingmayoresventas[3];
	for (i=0;i<=3-1;i+=1) {
		rankingmayoresventas[i] = totalventasaep[i];
	}
	for (i=0;i<=3-1;i+=1) {
		for (j=0;j<=i-1;j+=1) {
			if (rankingmayoresventas[j]<rankingmayoresventas[j+1]) {
				aux = rankingmayoresventas[j];
				rankingmayoresventas[j] = rankingmayoresventas[j+1];
				rankingmayoresventas[j+1] = aux;
			}
		}
	}
	printf(" \n");
	printf("Ranking de Ventas por Aeropuerto:\n");
	for (i=0;i<=3-1;i+=1) {
		printf("Aerpuerto %f: %f\n",i+1,rankingmayoresventas[i]);
	}
}

