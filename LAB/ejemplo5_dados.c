#include<stdio.h>
#include<stdlib.h>

#define MAX_RAND 6
#define MIN_RAND 1

int main() {
	int cantidadtiradas, contd12, contd2, contd7, dado1, dado2, tope;

	//inicializamos las variables en 0
	cantidadtiradas = 0;
	contd7 = 0;
	contd2 = 0;
	contd12 = 0;

	printf("HELLOOOOOO. Vamos a tirar dados.\n");

	//do while loop para que el programa siga corriendo hasta que ingrese 0
	do{
	printf("Cuantas veces queres tirar los dados? Ingrese un numero (Maximo: 1000). Ingrese 0 para finalizar el programa:\n");
	scanf("%d",&tope);

	//if statement para que ingrese solo valores aceptados
	if(0<tope && tope<1001){
	//while loop para hacer la cantidad de tiradas que se pidio
	while(cantidadtiradas<tope){
		dado1 = (rand()%MAX_RAND-MIN_RAND+1)+1;
		dado2 = (rand()%MAX_RAND-MIN_RAND+1)+1;
		cantidadtiradas++;
		
		//contadores
		switch (dado1+dado2) {
		case 7:
			contd7++;
			break;
		case 2:
			contd2++;
			break;
		case 12:
			contd12++;
			break;
		}

		//if statement para que solo imprima hasta cierto numero de tiradas (para no llenar la pantalla de texto)
		if (0<tope && tope<50){
			printf("%d %d / total:%d\n",dado1,dado2,dado1+dado2);
		}
	}

	//muestra los resultados de los contadores
	printf("\n");
	printf("Total de Tiradas: %d\n",tope);
	printf("Resultado 2: %d\n",contd2);
	printf("Resultado 7: %d\n",contd7);
	printf("Resultado 12: %d\n",contd12);
	printf("\n");

	}else if(tope==0){
		//se despide y finaliza el programa
		printf("baibai.");
		fflush(stdin);
		getchar();
	}else{
		//vuelve al principio si ingresa un numero invalido
		printf("El valor ingresado es incorrecto, ingreselo nuevamente.\n");
	}

	//resetea los contadores para la proxima tirada
	cantidadtiradas=0;
	contd2=0;
	contd7=0;
	contd12=0;

	}while(tope!=0);
	
	return 0;
}

