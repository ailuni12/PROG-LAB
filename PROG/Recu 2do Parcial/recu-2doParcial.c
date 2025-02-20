#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define HORA_TRABAJADA 6000
#define MAX_HORA 8
#define MIN_HORA 1
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
void registrar_visita(tecnico_t [], int *);
void registrar_tecnico(tecnico_t [],int *);
bool validar_codigo(tecnico_t [],int);
void mostrar(tecnico_t [],int);
int check_location(tecnico_t [],int);

int main(void){
    int tecnicos_registrados=0;
    tecnico_t tecnicos[MAX_TEC];

    for(int i=0;i<MAX_TEC;i++){
        tecnicos[i].cant_visitas=0;
        tecnicos[i].cod_tec=0;
        tecnicos[i].horas_trabajadas=0;
        tecnicos[i].cant_visitas=0;
        tecnicos[i].pago_acumulado=0;
        strcpy(tecnicos[i].nombre_tec,"N/A");
    }

    menu(tecnicos,&tecnicos_registrados);

    return 0;
}

void menu(tecnico_t tecnicos[MAX_TEC],int *tecnicos_registrados){
    int opcion=0;
    int input_usuario=-1;

    do{
        printf("\nGESTOR DE VISITAS TECNICAS\n");
        printf("\t\n1 - Registrar Visita");
        printf("\t\n2 - Registrar Tecnico");
        printf("\t\n3 - Informe de Tecnicos");
        printf("\t\n4 - Finalizar\n");
        printf("\t\nOpcion: ");
        scanf("%d",&opcion);

        switch (opcion){
        case registro_visita:
            do
            {
                registrar_visita(tecnicos,tecnicos_registrados);

                printf("\n\tDesea registrar otra visita? 1-SI 0-NO: ");
                scanf("%d",&input_usuario);
            }while(input_usuario!=SALIDA);
            break;
        case registro_tecnico:
            do{
                registrar_tecnico(tecnicos,tecnicos_registrados);

                printf("\n\tDesea registrar otro tecnico? 1-SI 0-NO: ");
                scanf("%d",&input_usuario);
            }while(input_usuario!=SALIDA);
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

void registrar_visita(tecnico_t tecnicos[],int *tecnicos_registrados){
    int codigo=0, horas=0, location=0;

    printf("\nNUEVA VISITA\n");

    printf("Ingrese el codigo del tecnico: ");
    scanf("%d",&codigo);

    while(codigo>MAX_TEC || codigo<MIN_TEC){
        printf("\nIngrese un numero valido.\n");
        scanf("%d",&codigo);
    }

    do{
        if(!validar_codigo(tecnicos,codigo)){
            printf("\nNo existe ese codigo, debe crear un nuevo registro.\n");
    
            registrar_tecnico(tecnicos,tecnicos_registrados);
                
            printf("\nIngrese el codigo del tecnico: ");
            scanf("%d",&codigo);
        }
    }while(!validar_codigo(tecnicos,codigo));

    location=check_location(tecnicos,codigo);
        
    printf("\nIngrese las horas trabajadas: ");
    scanf("%d",&horas);

    while(horas<MIN_HORA || horas>MAX_HORA){
        printf("\nNumero de horas invalido (Min 1, Max 8).\n");
        printf("\nIngrese las horas trabajadas: ");
        scanf("%d",&horas);
    }
            
    tecnicos[location].horas_trabajadas+=horas;
    tecnicos[location].cant_visitas+=1;
    tecnicos[location].pago_acumulado+=(horas*HORA_TRABAJADA);

    printf("\nDATOS INGRESADOS:\n");
    printf("Codigo: %d\n",codigo);
    printf("Nombre: %s\n",tecnicos[location].nombre_tec);
    printf("Horas: %d\n",horas);
    printf("Total de visitas: %d\n",tecnicos[location].cant_visitas);
    printf("Pago Acumulado: %.2f\n",tecnicos[location].pago_acumulado);
    printf("LA VISITA SE REGISTRO CON EXITO.\n");
 
}

void registrar_tecnico(tecnico_t tecnicos[MAX_TEC],int *tecnicos_registrados){
    int codigo=0;

    if(*tecnicos_registrados>=MAX_TEC){
        printf("\nMaximo de registros posibles alcanzado.\n");
    }else{
            printf("\nNUEVO REGISTRO");
            printf("\nIngrese el codigo del tecnico: ");
            scanf("%d",&codigo);

            while(codigo>MAX_TEC || codigo<MIN_TEC){
                printf("\nIngrese un numero valido.\n");
                scanf("%d",&codigo);
            }
            
            do{
                if(validar_codigo(tecnicos,codigo)){
                    printf("\nEl codigo ya existe, ingrese otro.");
                    printf("\nEl codigo no puede ser 0.");
                    printf("\nIngrese el codigo del tecnico: ");
                    scanf("%d",&codigo);
                }  
            }while(validar_codigo(tecnicos,codigo));

            tecnicos[*tecnicos_registrados].cod_tec=codigo;

            printf("Ingrese el Nombre del tecnico: ");
            scanf("%29s",tecnicos[*tecnicos_registrados].nombre_tec);

            printf("\nDATOS INGRESADOS:\n");
            printf("Codigo: %d\n",codigo);
            printf("Nombre: %s\n",tecnicos[*tecnicos_registrados].nombre_tec);
            printf("REGISTRO CREADO CON EXITO\n");

            (*tecnicos_registrados)++;
        
    }

}

void mostrar(tecnico_t tecnicos[MAX_TEC],int i){
    printf("\n\t***Informe de Tecnicos***\n");
    printf("\n| Cod | Nombre  | Visitas | Horas | Pago     |\n");
    int j=0;
    while(j<i){
        printf("|  %02d | %-8s|      %02d | %5d | %8.2f |\n",tecnicos[j].cod_tec,tecnicos[j].nombre_tec,tecnicos[j].cant_visitas,tecnicos[j].horas_trabajadas,tecnicos[j].pago_acumulado);
        j++;
    }
}

bool validar_codigo(tecnico_t tecnicos[],int codigo){
    for(int i=0;i<MAX_TEC;i++){
        if(tecnicos[i].cod_tec==codigo){
            return true;
        }
    }
    return false;
}

int check_location(tecnico_t tecnicos[],int codigo){
    int location=0;

    for(int i=0;i<MAX_TEC;i++){
        if(tecnicos[i].cod_tec==codigo){
            location=i;
        }
    }

    return location;
}