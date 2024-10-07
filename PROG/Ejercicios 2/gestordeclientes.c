#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "definiciones.h"

int main(void){
    opcion_t opcion;
    cliente_t clientes[MAX_CLI];
    int cantidadClientes=0;
    int indice=0;

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
                //pedir codigo de cliente y devolver el indice
                indice=buscarCliente(clientes,&cantidadClientes);
                
                if(indice!=NOT_FOUND){
                    mostrarCliente(clientes,indice);
                }
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
    fflush(stdin);
    getchar();
}

opcion_t menu(void){
    int op;
    
    do{
        printf("\nMENU DE OPCIONES DE CLIENTES\n");
        printf("\tIngresar Datos <1>\n");
        printf("\tBuscar un cliente <2>\n");
        printf("\tListado de Cliente Ordenado por Codigo <3>\n");
        printf("\tListado de Clientes Ordenado Por Apellido <4>\n");
        printf("\tSalir <5>\n");
        printf("Ingrese Opcion [1-5]: ");
        scanf("%d", &op);
    } while (op < INGRESAR || op > SALIR);
    
    return op;
}

void cargarCliente(cliente_t *ptrtoclientes, int *ptrtocantidad){
    int finalizar=FALSE;
    int i=*ptrtocantidad;
    uint16_t codigo=0;
    fecha_t dob;
    char nombre[MAX_CHAR];
    char apellido[MAX_CHAR];


    printf("Datos de cliente nuevo (por favor ingrese unicamente datos validos)\n");

    do{
        printf("Puede ingresar hasta 3 digitos del 1 al 999 para el ID de Cliente\n");
        printf("ID: ");
        scanf("%d",&codigo);
        //el ampersand siempre para int y float (puntero)

        while (codigo>999 || codigo<1){
            printf("Debe ingresar un numero valido, intente nuevamente:\n");
            printf("ID: ");
            scanf("%d",&codigo);
        }
        ptrtoclientes[i].codigo=codigo;

        printf("Ingrese el Nombre: ");
        scanf("%49s",nombre);
        //no incluye el ampersand porque char nombre ya se comporta
        //como un puntero, que indica la primera letra del string
        strcpy(ptrtoclientes[i].nombre,nombre);

        printf("Ingrese el Apellido: ");
        scanf("%49s",apellido);
        //%49s - previene buffer overload.
        //no importa la cantidad de caracteres que
        //ingrese el usuario, va a parar de leerlos
        //en 49, dejando el espacio 50 para el \0
        strcpy(ptrtoclientes[i].apellido,apellido);
        //strcpy es una funcion que copia strings

        printf("Ingrese la Fecha de Nacimiento:\n");
        printf("Dia: ");
        scanf("%d",&dob.dia);
        ptrtoclientes[i].fechaNacimiento.dia=dob.dia;
        printf("Mes: ");
        scanf("%d",&dob.mes);
        ptrtoclientes[i].fechaNacimiento.mes=dob.mes;
        printf("Anio: ");
        scanf("%d",&dob.anio);
        ptrtoclientes[i].fechaNacimiento.anio=dob.anio;

        printf("Datos Ingresados:\n");
        printf("Codigo: %d\n",ptrtoclientes[i].codigo);
        printf("Nombre Completo: %s %s\n",ptrtoclientes[i].nombre,ptrtoclientes[i].apellido);
        printf("Fecha de Nacimiento: %d/%d/%d\n",ptrtoclientes[i].fechaNacimiento.dia,ptrtoclientes[i].fechaNacimiento.mes,ptrtoclientes[i].fechaNacimiento.anio);

        i++;

        printf("Finalizar la carga? (1 FIN - 0 CONTINUAR): ");
        scanf("%d",&finalizar);
    }while(finalizar!=TRUE);

    *ptrtocantidad=i;

    if(*ptrtocantidad<=1){
        printf("\nEl perfil de cliente se creo correctamente.\n");
    }else if(*ptrtocantidad>1){
        printf("\nSe crearon %d perfiles de cliente correctamente.\n",*ptrtocantidad);
    }else{
        printf("\nOcurrio un error.\n");
    }

    printf("\nTotal de clientes registrados: %d\n",*ptrtocantidad);
}

int buscarCliente(cliente_t clientes[], int *ptrtoCantidad){
    int codigo=0;
    int target=NOT_FOUND;
    int i=0;

    printf("\nIngrese el codigo del cliente: ");
    scanf("%d",&codigo);

    for(i=0;i<*ptrtoCantidad;i++){
        if(clientes[i].codigo==codigo){
            target=i;
        }
    }

    if(target==NOT_FOUND){
        printf("\nNo se encontro un cliente con ese codigo.");
    }

    return target;
}

void mostrarCliente(cliente_t *ptrclientes, int indice){
    printf("Datos del cliente:\n");
    printf("Codigo: %d\n",ptrclientes[indice].codigo);
    printf("Nombre Completo: %s %s\n",ptrclientes[indice].nombre,ptrclientes[indice].apellido);
    printf("Fecha de Nacimiento: %d/%d/%d\n",ptrclientes[indice].fechaNacimiento.dia,ptrclientes[indice].fechaNacimiento.mes,ptrclientes[indice].fechaNacimiento.anio);

    pausa();
}

void ordenarClientesPorCodigo(cliente_t clientes[], int codigo){
}

void ordenarClientesPorApellido(cliente_t clientes[], int clientesCargados){
}