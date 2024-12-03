#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define HORA_TRABAJADA 6000
#define MAX_TEC 50
#define MIN_TEC 1
#define SALIDA 0

typedef enum{
    registro_visita=1,
    registro_tecnico,
    informe_tecnicos,
    finalizar
}opciones_t;

typedef struct{
    int cod_tec;
    char nombre_tec[30];
    int cant_visitas;
    int horas_trabajadas;
    float pago_acumulado;
}tecnico_t;

void menu(tecnico_t [],int *);
void registrar_visita(tecnico_t []);
void registrar_tecnico(tecnico_t [],int *);
bool validar_codigo(tecnico_t [],int, int);
void mostrar(tecnico_t [],int);

int main(void){
    int tecnicos_registrados=0;
    tecnico_t tecnicos[MAX_TEC];

    for(int i=0;i<MAX_TEC;i++){
        tecnicos[i].cant_visitas=0;
        tecnicos[i].cod_tec=0;
        tecnicos[i].horas_trabajadas=0;
        tecnicos[i].cant_visitas=0;
        tecnicos[i].pago_acumulado=0;
    }

    menu(tecnicos,&tecnicos_registrados);

    return 0;
}

void menu(tecnico_t tecnicos[MAX_TEC],int *tecnicos_registrados){
    int opcion=0;

    do{
        printf("\nGESTOR DE VISITAS TECNICAS\n");
        printf("\t\n1 - Registrar Visita");
        printf("\t\n2 - Registrar Tecnico");
        printf("\t\n3 - Informe de Tecnicos");
        printf("\t\n4 - Finalizar\n");
        scanf("%d",&opcion);

        switch (opcion){
        case registro_visita:
            registrar_visita(tecnicos);
            break;
        case registro_tecnico:
            registrar_tecnico(tecnicos,tecnicos_registrados);
            break;
        case informe_tecnicos:
            mostrar(tecnicos,*tecnicos_registrados);
            break;
        case finalizar:
            printf("Gracias por utilizar esta herramienta, presione Enter para finalizar.\n");
            fflush(stdin);
            getchar();
            break;
        default:
            printf("\nIngreso algun dato incorrecto, intente de nuevo.\n");
            break;
        }
    } while (opcion!=finalizar);
    
}

void registrar_visita(tecnico_t tecnicos[]){
    int input_usuario=-1, codigo=0, horas=0;

    printf("Desea registrar una nueva visita? 1-SI 0-NO.\n");
    scanf("%d",&input_usuario);

    do{
        printf("Ingrese el codigo del tecnico: ");
        scanf("%d",&codigo);

        printf("Ingrese las horas trabajadas: ");
        scanf("%d",&horas);
            
        tecnicos[codigo-1].horas_trabajadas+=horas;
        tecnicos[codigo-1].cant_visitas+=1;
        tecnicos[codigo-1].pago_acumulado+=(horas*HORA_TRABAJADA);

        printf("DATOS INGRESADOS:\n");
        printf("Codigo: %d\n",codigo);
        printf("Horas: %d\n",horas);
        printf("Total de visitas: %d\n",tecnicos[codigo-1].cant_visitas);
        printf("Pago Acumulado: %.2f\n",tecnicos[codigo-1].pago_acumulado);

        printf("\nDesea registrar otra visita? 1-SI 0-NO.\n");
        scanf("%d",&input_usuario);
    }while(input_usuario!=SALIDA); 
}

void registrar_tecnico(tecnico_t tecnicos[MAX_TEC],int *tecnicos_registrados){
    int input_usuario=-1, codigo=0;

    if(*tecnicos_registrados>=MAX_TEC){
        printf("\nMaximo de registros posibles alcanzado.\n");
    }else{
        printf("Desea registrar una nuevo Tecnico? 1-SI 0-NO.\n");
        scanf("%d",&input_usuario);

        do{
            printf("Ingrese el codigo del tecnico: ");
            scanf("%d",&codigo);

            while(codigo>MAX_TEC || codigo<MIN_TEC){
                printf("\nIngrese un numero valido.\n");
                scanf("%d",&codigo);
            }
            
            while(validar_codigo(tecnicos,codigo,*tecnicos_registrados)==true){
                printf("\nIngrese el codigo del tecnico: ");
                scanf("%d",&codigo);
            }

            tecnicos[codigo-1].cod_tec=codigo;

            printf("Ingrese el Nombre del tecnico: ");
            scanf("%29s",tecnicos[codigo-1].nombre_tec);

            printf("DATOS INGRESADOS:\n");
            printf("Codigo: %d\n",codigo);
            printf("Nombre: %s\n",tecnicos[codigo-1].nombre_tec);

            (*tecnicos_registrados)++;

            printf("\nDesea registrar otro tecnico? 1-SI 0-NO.\n");
            scanf("%d",&input_usuario);

        }while(input_usuario!=SALIDA);
    }

}

void mostrar(tecnico_t tecnicos[MAX_TEC],int i){
    printf("\n\t\tInforme de Tecnicos\n\n");
    printf("\n Cod \t Tecnicos\t\t Visitas Horas\tPago\n\n\n");
    int j=0;
    while(j<i){
        printf("\n %-10d%-20s %4d\t\t%4d\n\n",tecnicos[j].cod_tec,tecnicos[j].nombre_tec,tecnicos[j].cant_visitas,tecnicos[j].horas_trabajadas);
        j++;
    }
}

bool validar_codigo(tecnico_t tecnicos[],int codigo, int tecnicos_registrados){
    for(int i=0;i<tecnicos_registrados;i++){
        if(tecnicos[i].cod_tec==codigo){
            printf("\nEl codigo ya existe, ingrese otro.");
            return true;
        }else if(tecnicos[i].cod_tec==0){
            printf("\nNo existe ese codigo, debe crear un nuevo registro.");
            return true;
        }
    }
    return false;
}