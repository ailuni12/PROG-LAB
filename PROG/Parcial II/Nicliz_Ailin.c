#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_ARTICULOS 6           // maxima cantidad de Articulos
#define MAX_CLIENTES 5           // maxima cantidad de clientes
#define MAX_FACTURAS 3 // maxima cantidad de lugares para poder facturar
#define SALIDA 0
#define MIN_CODIGO 1
#define MIN_STOCK 1

// Estructura para clientes
typedef struct
{
    int cod;      // Código del cliente
    char nom[30]; // Nombre del Cliente
    float fac;    // Total facturado por cliente
} regcli_t;

// Estructura para artículos
typedef struct
{
    int cod;      // Código del artículo
    char nom[30]; // Denominación del artículo
    float pre;    // Precio por litro del artículo
    int sto;      // Stock disponible del artículo
    int vendidos; // Cantidad total de litros vendidos
} articulo_t;

// Estructura para facturas
typedef struct
{
    int numFactura; // Número de factura
    int codCliente; // Código del cliente
    float total;    // Total facturado en esa factura
} factura_t;

void inicializacion(regcli_t[MAX_CLIENTES], articulo_t[MAX_ARTICULOS]);    //  Inicializa los datos de los clientes y los artículos
void facturar(regcli_t[MAX_CLIENTES], articulo_t[MAX_ARTICULOS], factura_t facturas[], int *); //  función para facturar( paso clientes, articulo_t,  facturas, &contador de facturas)
void mostrarClientes(regcli_t[MAX_CLIENTES]);                                // aqui paso  la estructura de clientes
void mostrarArticulos(articulo_t[MAX_ARTICULOS]);                             // aqui paso  la estructura de articulos
void mostrarFacturas(factura_t facturas[], int);                    // aqui paso la  estructura de facturas y el contador de facturas
void tecla(void);                                                 // Función para leer una tecla y esperar
void linea(int);                                                  // Función para dibujar una línea de asteriscos
void menu(regcli_t[MAX_CLIENTES], articulo_t[MAX_ARTICULOS], factura_t facturas[], int *); // aqui paso la estructura de clientes, articulos, facturas y el contador de facturas
bool validar_codigo(factura_t facturas[],int,int);

int main()
{
    regcli_t clientes[MAX_CLIENTES];
    articulo_t articulos[MAX_ARTICULOS];
    factura_t facturas[MAX_FACTURAS];
    int contfact = 0; // contador  de facturas
    inicializacion(clientes, articulos);
    menu(clientes, articulos, facturas, &contfact);
    return 0;
}

void menu(regcli_t clientes[], articulo_t articulos[], factura_t facturas[], int *contfact)
{
    int opcion;
    do
    {
        printf("\n*** MENU DE FACTURACION ***\n");
        printf("< 1 >. Facturar productos\n");
        printf("< 2 >. Mostrar clientes\n");
        printf("< 3 >. Mostrar articulos\n");
        printf("< 4 >. Mostrar facturas\n");
        printf("< 0 >. Salir\n");
        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            facturar(clientes,articulos,facturas,contfact);
            break;
        case 2:
            mostrarClientes(clientes);
            break;
        case 3:
            mostrarArticulos(articulos);
            break;
        case 4:
            mostrarFacturas(facturas, *contfact);
            break;
        case 0:
            printf("\n...Saliendo...\n");
            break;
        default:
            printf("Opcion invalida.\n");
        }
        tecla();
    } while (opcion != SALIDA);
}

void inicializacion(regcli_t clientes[], articulo_t articulos[])
{
    regcli_t clientes_init[MAX_CLIENTES] = {
        {1, "Julian LOPEZ", 0},
        {2, "Marcelo RIOS", 0},
        {3, "Alvaro CARPIO", 0},
        {4, "Facundo PAREDES", 0},
        {5, "Roberto MALDONADO", 0}};

    articulo_t articulos_init[MAX_ARTICULOS] = {
        {1, "COCA COLA", 1500, 73, 0},
        {2, "FANTA POMELO", 1000, 120, 0},
        {3, "FANTA NARANJA", 1100, 76, 0},
        {4, "SPRITE", 1200, 34, 0},
        {5, "AGUA VILLA DEL SUR", 1100, 77, 0},
        {6, "MANAOS", 1100, 98, 0}};

    for (int i = 0; i < MAX_CLIENTES; i++)
    {
        clientes[i] = clientes_init[i];
    }
    for (int i = 0; i < MAX_ARTICULOS; i++)
    {
        articulos[i] = articulos_init[i];
    }
}

void facturar(regcli_t clientes[MAX_CLIENTES], articulo_t articulos[MAX_ARTICULOS], factura_t facturas[], int *contfact)
{
    int litros, cod_cliente, cod_articulo, cod_factura;
    int input_usuario;

    printf("cantfact valor: %d\n",*contfact);
    printf("direccion del puntero: %d\n",&contfact);
    printf("direccion de cantfact: %d\n",contfact);

    if(*contfact>MAX_FACTURAS){
        printf("Error: Se alcanzo el limite de facturas.\n");
    }else{
        printf("\nDesea crear una nueva factura? 1 SI, 0 NO:\n",contfact);
        scanf("%d",&input_usuario);

        do{
            do{
                printf("\nIngrese el codigo del cliente (1 a 5):\n");
                scanf("%d",&cod_cliente);

                if(cod_cliente>MAX_CLIENTES || cod_cliente<MIN_CODIGO){
                printf("\nError. Ingrese un codigo valido.\n");
                }
            }while(cod_cliente>MAX_CLIENTES || cod_cliente<MIN_CODIGO);

            facturas[*contfact].codCliente=cod_cliente;

            do{
                printf("\nIngrese un codigo nuevo para la Factura.\n");
                scanf("%d",&cod_factura);

                if(validar_codigo(facturas,cod_factura,*contfact)==true){
                    printf("\nEl codigo ya existe, debe ingresar uno nuevo.\n");
                }

            }while(validar_codigo(facturas,cod_factura,*contfact)==true);

            facturas[*contfact].numFactura=cod_factura;

            do{
                do{
                    printf("\nIngrese el codigo del articulo (1 a 6).\n");
                    scanf("%d",&cod_articulo);

                    if(cod_articulo>MAX_ARTICULOS || cod_articulo<MIN_CODIGO){
                    printf("\nError. Ingrese un codigo valido.\n");
                    }
                }while(cod_articulo>MAX_ARTICULOS || cod_articulo<MIN_CODIGO);


                do{
                    printf("\nIngrese los cantidad de litros a facturar.\n");
                    scanf("%d",&litros);

                    if(litros>articulos[cod_articulo-1].sto){
                        printf("\nNo hay stock suficiente de ese articulo para esa cantidad de litros.\n");
                    }else if(litros<MIN_STOCK){
                        printf("\nIngreso un dato invalido, intente nuevamente.\n");
                    }

                }while(litros>articulos[cod_articulo-1].sto || litros<MIN_STOCK);

                clientes[cod_cliente-1].fac+=(litros*articulos[cod_articulo-1].pre);
                facturas[*contfact].total+=(litros*articulos[cod_articulo-1].pre);
                articulos[cod_articulo-1].vendidos+=litros;
                articulos[cod_articulo-1].sto-=litros;

                printf("\nDesea agregar otro articulo? 1 SI, 0 NO:\n",contfact);
                scanf("%d",&input_usuario);

            }while(input_usuario!=SALIDA);

            printf("\nTotal de facturas registradas: %d \n",*contfact);
            printf("\nFACTURA NRO %d \n",facturas[*contfact].numFactura);
            printf("NOMBRE DEL CLIENTE: %s\n",clientes[cod_cliente-1].nom);
            printf("CODIGO DEL CLIENTE: %d\n",clientes[cod_cliente-1].cod);
            printf("TOTAL FACTURADO: $%.2f\n",clientes[cod_cliente-1].fac);

            (*contfact)++;

            printf("\nDesea crear una nueva factura? 1 SI, 0 NO:\n",contfact);
            scanf("%d",&input_usuario);

        }while(input_usuario!=SALIDA);
    }
}

void mostrarClientes(regcli_t clientes[])
{
    printf("\n*** INFORME DE CLIENTES ***\n");
    printf("COD. CLIENTE | NOMBRE DEL CLIENTE            | TOTAL FACTURADO\n");
    linea(50);
    for (int i = 0; i < MAX_CLIENTES; i++)
    {
        printf("%12d | %-30s | %14.2f\n",
               clientes[i].cod, clientes[i].nom, clientes[i].fac);
    }
}

void mostrarArticulos(articulo_t articulos[])
{
    printf("\n*** INFORME DE ARTICULOS ***\n");
    printf("COD. ARTICULO | DENOMINACION         | STOCK | LITROS VENDIDOS\n");
    linea(50);
    for (int i = 0; i < MAX_ARTICULOS; i++)
    {
        printf("%13d | %-20s | %5d | %14d\n",
               articulos[i].cod, articulos[i].nom, articulos[i].sto, articulos[i].vendidos);
    }
}

void mostrarFacturas(factura_t facturas[], int cantfac)
{
    if (cantfac == 0)
    {
        printf("\nNo se han realizado facturas.\n");
        return;
    }

    printf("\n*** INFORME DE FACTURAS ***\n");
    printf("NUM. FACTURA | COD. CLIENTE | TOTAL FACTURADO\n");
    linea(50);
    for (int i = 0; i < cantfac; i++)
    {
        printf("%12d | %12d | %14.2f\n",
               facturas[i].numFactura, facturas[i].codCliente, facturas[i].total);
    }
}
// esta funcion solo  imprime una linea de asteriscos de longitud n
void linea(int x)
{
    for (int i = 0; i < x; i++)
    {
        printf("*");
    }
    printf("\n");
}
// este funcion espera  a que el usuario ingrese un caracter

void tecla(void)
{
    printf("\n\n...PRESIONE CUALQUIER TECLA PARA CONTINUAR...\n");
    getch();
}

bool validar_codigo(factura_t facturas[],int codigo,int contfact)
{
    for(int i=0;i<contfact;i++){
        if(facturas[i].numFactura==codigo){
            return true;
        }
    }
    return false;
}