/* Este codigo ha sido generado por el modulo psexport 20180802-w32 de PSeInt.
Es posible que el codigo generado no sea completamente correcto. Si encuentra
errores por favor reportelos en el foro (http://pseint.sourceforge.net). */

#include<stdio.h>
#include<string.h>

/* En C no se puede dimensionar un arreglo est�tico con una dimensi�n no constante.
   PSeInt sobredimensionar� el arreglo utilizando un valor simb�lico ARREGLO_MAX.
   Ser�a posible crear un arreglo din�micamente con los operadores new y delete, pero
   este mecanismo a�n no est� soportado en las traducciones autom�ticas de PSeInt. */
#define ARREGLO_MAX 100

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

/* Para leer variables de texto se utiliza scanf, que lee solo una palabra. 
   Para leer una linea completa (es decir, incluyendo los espacios en blanco)
   se debe utilzar ges (ej, reemplazar scanf("%s",x) por gets(x)) pero 
   obliga a agregar un getchar() antes del gets si antes del mismo se ley�
   otra variable con scanf. */

// Declaraciones adelantadas de las funciones
void ordenarlistas(int listaedades[], char *listanombres[], float longitudlista);
void mayoresdeedad(float listaedades[], SIN_TIPO listanombres[], int longitudlista);

/* 10. Queremos guardar los nombres y las edades de los alumnos de un curso. Realiza un */
/* programa que introduzca el nombre y la edad de cada alumno. El proceso de lectura de */
/* datos terminar� cuando se introduzca como nombre un asterisco (*) Al finalizar se mostrar� */
/* los siguientes datos: */
/* Los alumnos mayores de edad. */
/* Todos los alumnos de mayor a menor edad. */
int main() {
	int edadalumno;
	int listaedades[100];
	char listanombres[MAX_STRLEN][100];
	int longitudlista;
	int n;
	char nombrealumnos[MAX_STRLEN];
	longitudlista = 0;
	printf("Ingresar los nombres de los alumnos y sus respectivas edades (ingresar * para terminar):\n");
	printf("Nombre:\n");
	scanf("%s",nombrealumnos);
	while (strcmp(nombrealumnos,"*")!=0) {
		listanombres[longitudlista] = nombrealumnos;
		printf("Edad:\n");
		scanf("%i",&edadalumno);
		listaedades[longitudlista] = edadalumno;
		longitudlista = longitudlista+1;
		printf("Nombre:\n");
		scanf("%s",nombrealumnos);
	}
	ordenarlistas(listaedades,listanombres,longitudlista);
	mayoresdeedad(listaedades,listanombres,longitudlista);
	printf("Alumnos listados, ordenados de mayor a menor:\n");
	for (n=0;n<=longitudlista-1;n+=1) {
		printf("[%f]: %s Edad: %i\n",n+1,listanombres[n],listaedades[n]);
	}
	return 0;
}

void ordenarlistas(int listaedades[], char *listanombres[], float longitudlista) {
	int aux1;
	char aux2[MAX_STRLEN];
	int i;
	int j;
	for (i=0;i<=longitudlista-1;i+=1) {
		for (j=0;j<=longitudlista-i-2;j+=1) {
			if (listaedades[j]<listaedades[j+1]) {
				aux1 = listaedades[j];
				listaedades[j] = listaedades[j+1];
				listaedades[j+1] = aux1;
				aux2 = listanombres[j];
				listanombres[j] = listanombres[j+1];
				listanombres[j+1] = aux2;
			}
		}
	}
}

void mayoresdeedad(float listaedades[], SIN_TIPO listanombres[], int longitudlista) {
	int i;
	int listamayoresedades[ARREGLO_MAX];
	char listanombremayores[MAX_STRLEN][ARREGLO_MAX];
	int tope;
	tope = 0;
	for (i=0;i<=longitudlista-1;i+=1) {
		if (listaedades[i]>=18) {
			tope = tope+1;
		}
	}
	for (i=0;i<=longitudlista-1;i+=1) {
		if (listaedades[i]>=18) {
			listamayoresedades[i] = listaedades[i];
			listanombremayores[i] = listanombres[i];
		}
	}
	printf("Lista de alumnos mayores de edad:\n");
	for (i=0;i<=tope-1;i+=1) {
		printf("%s\n",listanombremayores[i]);
	}
}

