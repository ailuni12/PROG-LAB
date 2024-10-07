#include <stdio.h>
#include <stdlib.h>
#define MAX_CHAR 50
#define OK 0
#define ERROR 1

typedef enum{
    AGREGAR=1,
    ELIMINAR,
    VERTODOS,
    SALIR
}opciones_t;

typedef struct{
    char nombre[MAX_CHAR];
    char apellido[MAX_CHAR];
    int edad;
    float promedio;
}alumno_t;

opciones_t menu(void);

void agregar_alumno(int *,alumno_t **);
void eliminar_alumno(void);
void ver_todos(int ,alumno_t*);

int main (void){
    opciones_t ingreso;
    int cant_alumnos=0;
    alumno_t  * alumnos=NULL;
    do{
        ingreso=menu();
        switch (ingreso){
            case AGREGAR:
                agregar_alumno(&cant_alumnos,&alumnos);
                break;
            case ELIMINAR:
                eliminar_alumno();
                break;
            case VERTODOS:
                ver_todos(cant_alumnos,alumnos);
                break;                
        }
    }while(ingreso!=SALIR);
    free (alumnos);
    return OK;
}

opciones_t menu(void){
    opciones_t ingreso;
    printf("Menu\n\n");
    printf("1_Para agregar un alumno\n");
    printf("2_Para eliminar un alumno\n");
    printf("3_Para ver todos los alumnos\n");
    printf("4_Salir\n");
    scanf("%d",&ingreso);
    return ingreso;
}

void agregar_alumno(int * cantidad,alumno_t ** alumnos){
    if(cantidad==0){
        alumnos=(alumno_t *) malloc(sizeof(alumno_t));
        if(alumnos==NULL){
            printf("Me quedé sin memoria");
        }
    }else{
        alumnos=(alumno_t *) realloc(alumnos,((*cantidad)+1)*sizeof(alumno_t));
        if(alumnos==NULL){
            printf("Me quedé sin memoria");
        }
    }
    printf("Ingrese el nombre del alumno\n");
    scanf("%s",(alumnos+*cantidad)->nombre);
    printf("Ingrese el apellido del alumno\n");
    scanf("%s",(alumnos+*cantidad)->apellido);
    printf("Ingrese la edad\n");
    scanf("%d",&((alumnos+*cantidad)->edad));
    printf("Ingrese el promedio\n");
    scanf("%f",&((alumnos+*cantidad)->promedio));
    (*cantidad)++;
}
void eliminar_alumno(void){

}

void ver_todos(int cantidad,alumno_t * alumnos){
    for(int i=0;i<cantidad;i++){
        printf("Alumno %s %s\n",(alumnos+i)->nombre,(alumnos+i)->apellido);
        printf("Edad %d \n",(alumnos+i)->edad);
        printf("Promedio %f \n",(alumnos+i)->promedio);
    }
}