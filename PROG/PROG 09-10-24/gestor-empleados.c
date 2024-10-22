#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_CHAR 50
#define MAX_EMPLEADOS 6
#define TRUE 1
#define FALSE 0

#define MAX_CAT 4
#define MIN_CAT 1

#define MAX_HORAS 220
#define MIN_HORAS 50


typedef enum{
    CARGA=1,
    INFORME_SUELDOS,
    FILTRAR_HORAS,
    INFORME_CATEGORIAS,
    EMPLEADOS_CATEGORIA,
    SALIDA
}menu_t;

typedef struct{
    int codigo;
    char nombre[MAX_CHAR];
    int categoria;
    int horas;
    float sueldo;
}registro_t;

menu_t menu(void);
void cargar_empleados(registro_t[],int*);
bool validar_codigo(registro_t[],int,int);

int main (void){
    menu_t opcion;
    registro_t empleados[MAX_EMPLEADOS];
    int cantidadEmpleados=0;

    do{
        opcion=menu();

        switch (opcion){
            case CARGA:
                printf("CARGA\n");
                cargar_empleados(empleados, &cantidadEmpleados);
                break;
            case INFORME_SUELDOS:
                printf("INFORME SUELDOS\n");
                break;
            case FILTRAR_HORAS:
                printf("FILTRAR HORAS\n");
                break;
            case INFORME_CATEGORIAS:
                printf("INFORME CATEGORIAS\n");
                break;
            case EMPLEADOS_CATEGORIA:
                printf("EMPLEADOS POR CATEGORIA\n");
                break;
            case SALIDA:
                printf("Gracias por utilizar la herramienta, presione Enter para finalizar\n");
                fflush(stdin);
                getchar();
                break;
            default:
                printf("Debe ingresar una opcion entre 1 y 6\n");
                break;
            }
    }while(opcion!=SALIDA);

    return 0;
}

menu_t menu(void){
    int opcion=0;


    printf("\n\t-------------OPCIONES DE CARGA-------------\n");
    printf("\t[1] Cargar Empleado\n");
    printf("\t[2] Informe de Empleados Registrados\n");
    printf("\t[3] Filtrar Empleados segun horas trabajadas\n");
    printf("\t[4] Informe de Sueldos por Categoria\n");
    printf("\t[5] Cantidad de Empleados por Categoria\n");
    printf("\t[6] Finalizar Programa\n");

    printf("\nIngresar opcion: ");
    scanf("%d",&opcion);

    if(opcion < CARGA || opcion > SALIDA){
        printf("\nIngrese un numero valido.\n");
    }

    return opcion;
}

void cargar_empleados(registro_t empleados[], int *cantidadPointer){
    int codigo=TRUE;

    do{
        printf("Ingrese codigo del Empleado. Ingrese 0 para salir\n");
        scanf("%d",&codigo);

        if(codigo!=FALSE){

            if(validar_codigo(empleados,empleados[*cantidadPointer].codigo,*cantidadPointer==false)){

                printf("Ingrese el Nombre\n");
                scanf("%d",(empleados[*cantidadPointer].nombre));
                fflush(stdin);
                empleados[*cantidadPointer].categoria=(rand()%(MAX_CAT-MIN_CAT-1)+MIN_CAT);
                empleados[*cantidadPointer].horas=(rand()%(MAX_HORAS-MIN_HORAS-1)+MIN_HORAS);

                (*cantidadPointer)++;
            }
        }else{
            printf("El codigo ya existe\n");
        }
    }while((empleados[(*cantidadPointer)-1].codigo)!=FALSE);

    if(*cantidadPointer<=1)printf("\nEl perfil de cliente se creo correctamente.\n");
    else if(*cantidadPointer>1)printf("\nSe crearon %d perfiles de cliente correctamente.\n",*cantidadPointer);
    else printf("\nOcurrio un error.\n");
}

bool validar_codigo(registro_t empleados[],int codigo,int cantidad){
    int i=0;

    for(i=0;i<cantidad;i++){
        if(empleados[i].codigo==codigo) return true;
    }

    return false;
}