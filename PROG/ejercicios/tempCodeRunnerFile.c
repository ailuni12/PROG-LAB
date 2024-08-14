#include <stdio.h>

int PedirJugador(void);
void CompararPiezas(int,int,int);

int main()
{
    int Pescador;
    int Cantpiezas1,Cantpiezas2,Cantpiezas3;//cantidadpiezas
    float MedidaPieza1,MedidaPieza2,MedidaPieza3;//medidas
    float SumaPieza1=0,SumaPieza2=0,SumaPieza3=0; //acumador para sacar luego el promedio
    float Maxpieza1,Maxpieza2,Maxpieza3;//ACA PUEDO USAR DEFINE?
    int TotalPiezas;
    float Promediototal;

    printf("Bienvenidos a el concurso de pesca de Pejerrey\n");
    printf("Que gane el mejor!\n");

    Pescador=PedirJugador();


        while(Pescador>=1 && Pescador<=3){

        if (Pescador==1){
            Cantpiezas1++;
            do{
            printf("Ingrese la medida de la pieza\n");
            scanf("%f",&MedidaPieza1);
            } while(MedidaPieza1<=0);
            SumaPieza1=SumaPieza1+MedidaPieza1;
            Maxpieza1=MedidaPieza1;
            if (Maxpieza1>MedidaPieza1) Maxpieza1=MedidaPieza1;
         }

        if (Pescador==2){
            Cantpiezas2++;
            do{
            printf("Ingrese la medida de la pieza\n");
            scanf("%f",&MedidaPieza2);
            } while(MedidaPieza2<=0);
            SumaPieza2=SumaPieza2+MedidaPieza2;
            Maxpieza2=MedidaPieza2;
            if (Maxpieza2>MedidaPieza2) Maxpieza2=MedidaPieza2;
         }

        if (Pescador==3){
            Cantpiezas3++;
            do{
            printf("Ingrese la medida de la pieza\n");
            scanf("%f",&MedidaPieza3);
            } while(MedidaPieza3<=0);
            SumaPieza3=SumaPieza3+MedidaPieza3;
            Maxpieza3=MedidaPieza3;
            if (Maxpieza3>MedidaPieza3) Maxpieza3=MedidaPieza3;
         }
    printf("Porfavor otro pescador 0 para finalizar la carga\n");
    scanf("%d",&Pescador);
    }
   //pescador con mas piezas
   /*/if (Cantpiezas1>Cantpiezas2 && Cantpiezas1>Cantpiezas3){
       printf("El jugador numero UNO tiene mayor piezas con un total de %d\n",Cantpiezas1);
   } else
        if (Cantpiezas2>Cantpiezas3 && Cantpiezas2>Cantpiezas1){
            printf("El jugador DOS tiene mayor piezas con un total de %d\n",Cantpiezas2);
        }
        else {
            printf("El jugador TRES tiene mayor piezas con un total de %d\n",Cantpiezas3);
        }/*/

    CompararPiezas(Cantpiezas1,Cantpiezas2,Cantpiezas3);
   //pescador con la pieza mas grande

   if (Maxpieza1>Maxpieza2 && Maxpieza1>Maxpieza3){
       printf("El jugador UNO tiene la pieza mas grande con %2.f cm\n",Maxpieza1);
      }
      else
      if(Maxpieza2>Maxpieza1 && Maxpieza2>Maxpieza3){
          printf("El jugador DOS tiene la pieza mas grande con %f cm\n",Maxpieza2);
      }
        else {
            printf("El jugador TRES tiene la pieza mas grande con %f cm\n",Maxpieza3);
        }

   TotalPiezas=Cantpiezas1+Cantpiezas2+Cantpiezas3;
   Promediototal=(SumaPieza1+SumaPieza2+SumaPieza3)/TotalPiezas;

   printf("El total de piezas ingresadas es %d\n",TotalPiezas);
   printf("El promedio de las piezas son %.2f\n",Promediototal);
}
//funcion para ingresar pescador
int PedirJugador(void){
    int Pescador;
    do{
        printf("Porfavor ingrese el numero del pescador\n");
        scanf("%d",&Pescador);
    }
    while(Pescador<=1 && Pescador>=3 );

    return Pescador;
}

//funcion para comprar piezas

void CompararPiezas(int piezas1,int piezas2,int piezas3){
    int piezamayor;
    if (piezas1>piezas2 && piezas1>piezas3){
       printf("El jugador numero UNO tiene mayor piezas con un total de %d\n",piezas1);
       //piezamayor=piezas1;

    }else{
        if (piezas2>piezas3 && piezas2>piezas1){
            printf("El jugador DOS tiene mayor piezas con un total de %d\n",piezas2);
           // piezamayor=piezas2;
        }
        else {
            printf("El jugador TRES tiene mayor piezas con un total de %d\n",piezas3);
            //piezamayor=piezas3;
        }
   }


    return 0;

}