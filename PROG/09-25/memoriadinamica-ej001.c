#include <stdio.h>
#include <stdlib.h>

int main (void){

    /*scanf("%d",cantidad);*/
    int *p1=NULL;
    p1=(int *) malloc(sizeof(int));
    int *p2=(int *) malloc(sizeof(int));
    int *r=(int *) malloc(sizeof(int));
    printf("Ingrese el primer valor\n");
    scanf("%d",p1);
    printf("Ingrese el segundo valor\n");
    scanf("%d",p2);
    *r=*p1+*p2;
    printf("El resultado es: %d\n",*r);
    return 0;
}