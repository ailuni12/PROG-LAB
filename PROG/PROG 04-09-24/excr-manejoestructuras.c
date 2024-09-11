#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "definiciones.h"

int main(void){
    opcion_t opcion;
    cliente_t clientes[MAX_CLI];
    int cantidadClientes=0;
    int codigo=0;

    printf("\n-------------------------\nBASE DE DATOS DE CLIENTES\n-------------------------\n");
    printf("Con este gestor puede crear un perfil de cliente, buscar clientes por su codigo, o tambien visualizar la lista completa ordenada por codigo o apellidos.\n");
    pausa();

    do{
        opcion=menu();
        switch (opcion){
            case INGRESAR:
                cargarCliente(clientes,&cantidadClientes);
                break;
            case BUSCAR:
                //pedir codigo de cliente ()
                buscarCliente(clientes,codigo);
                mostrarClientePorCodigo(clientes,codigo);
                break;
            case LIST_CODIGOS:
                ordenarClientesPorCodigo(clientes,cantidadClientes);
                break;
            case LIST_APELLIDOS:
                ordenarClientesPorApellido(clientes,cantidadClientes);
                break;
            case SALIR:
                printf("Gracias por utilizar esta herramienta. Presione Enter para finalizar:\n");
                fflush(stdin);
                getchar();
                break;
            default: printf("Error, por favor ingrese un numero valido [1 a 5].\n");
        }
    }while(opcion!=SALIR);

    return 0;
}

void pausa(void){
    printf("Presione Enter para continuar: ");
    fflush(stdin); // aqui si va porque puede quedar el /n
    getchar();
}

opcion_t menu(void){
    int op;
    
    do{
        printf("\nMENU DE OPCIONES DE CLIENTES\n");
        printf("\n\tIngresar Datos <1>\n");
        printf("\n\tBuscar un cliente <2>\n");
        printf("\n\tListado de Cliente Ordenado por Codigo <3>\n");
        printf("\n\tListado de Clientes Ordenado Por Apellido <4>\n");
        printf("\n\tSalir <5>\n");
        printf("\nIngrese Opcion [1-5]: ");
        scanf("%d", &op);
    } while (op < INGRESAR || op > SALIR);
    
    return op;
}

void cargarCliente(cliente_t clientes[], int * indice){
    uint16_t codigo;
    char nombre[50];
    char apellido[50];

    printf("Datos de cliente nuevo (por favor ingrese unicamente datos validos)\nIngrese 0 para finalizar la carga\n");

    do
    {
        printf("Ingrese 3 digitos [xxx] distintos de 0 para el codigo\n");
        printf("Codigo: ");
        scanf("%d",codigo);
    }while(codigo!=0);

    printf("El perfil de cliente se creo correctamente.");
}

void mostrarCliente(cliente_t clientes[], int indice){

}

void ordenarClientesPorCodigo(cliente_t clientes[], int codigo){

}

void ordenarClientesPorApellido(cliente_t clientes[], int clientesCargados){

}

void mostrarClientePorCodigo(cliente_t clientes[], int codigo){

}

int buscarCliente(cliente_t clientes[], int codigo){

}
