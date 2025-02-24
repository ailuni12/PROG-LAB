#include <stdio.h>
#include <math.h>
#include "herramientas.h"

int main(void){
    double num1=0;
    double num2=0;
    double result=0;

    printf("\nFirst number: ");
    scanf("%lf",&num1);
    printf("Second number: ");
    scanf("%lf",&num2);

    result=num1*num2;

    printf("\n( %lf * %lf )",num1,num2);
    printf("\n\nResult: %lf",result);

    result=ceil(result*100)/100;

    printf("\nRounded Result: %lf\n\n",result);

    return 0;
}