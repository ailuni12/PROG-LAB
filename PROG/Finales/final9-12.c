#include <stdio.h>
#include <string.h>

#define MAX_CHAR 50
// Constantes simbólicas para el tamaño de la matriz
#define NUM_ESTANTERIAS 3  // Número de estanterías
#define NUM_UBICACIONES 4  // Número de ubicaciones por estantería

// Estructura que representa un producto
typedef struct {
    int codigo;
    char nombre[MAX_CHAR];
    int cantidad;
    float precio;
}Producto_t;

// Declaración de funciones
void inicializarMatriz(Producto_t matriz[NUM_ESTANTERIAS][NUM_UBICACIONES]);
void cargarInformacion(Producto_t matriz[NUM_ESTANTERIAS][NUM_UBICACIONES]);
void procesarInformacion(Producto_t matriz[NUM_ESTANTERIAS][NUM_UBICACIONES]);
void visualizarInformacion(Producto_t matriz[NUM_ESTANTERIAS][NUM_UBICACIONES]);
void mostrarMenu();
void mostrarSubMenuVisualizar();

int main() {
    Producto_t inventario[NUM_ESTANTERIAS][NUM_UBICACIONES];
    MenuOpciones_t opcion;
    inicializarMatriz(inventario);
    do {
        mostrarMenu();
        printf("\nSeleccione una opcion: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case MENU_CARGAR:
                break;
            case MENU_PROCESAR:
                break;
            case MENU_VISUALIZAR:
                visualizarInformacion(inventario);
                break;
            case MENU_SALIR:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción invalida, intente nuevamente.\n");
        }
    } while (opcion != MENU_SALIR);
    return 0;
}

// Inicializar la matriz con valores por defecto
void inicializarMatriz(Producto_t matriz[NUM_ESTANTERIAS][NUM_UBICACIONES]) {
    
}

// Función para cargar información en la matriz
void cargarInformacion(Producto_t matriz[NUM_ESTANTERIAS][NUM_UBICACIONES]) {
    int estanteria, ubicacion;
    printf("\nIngrese la estanteria (0-%d): ", NUM_ESTANTERIAS - 1);
    scanf("%d", &estanteria);
    printf("Ingrese la ubicacion (0-%d): ", NUM_UBICACIONES - 1);
    scanf("%d", &ubicacion);

    if () {
        
    } else {
        printf("Ubicacion fuera de rango.\n");
    }
}

// Función para procesar la información
void procesarInformacion(Producto_t matriz[NUM_ESTANTERIAS][NUM_UBICACIONES]) {
    float valorTotalEstanteria[NUM_ESTANTERIAS] = {0};
    float mayorValor =valorTotalEstanteria[0];
    int estanteriaMayorValor = 0;

    printf("\nValor total por estanteria:\n");
    for (int i = 0; i < NUM_ESTANTERIAS; i++) {
        printf("Estantería %d: $%.2f\n", i, valorTotalEstanteria[i]);
    }

    printf("\nLa estanteria con mayor valor es la %d con un total de $%.2f.\n",
    estanteriaMayorValor, mayorValor);
}

// Función para visualizar información
void visualizarInformacion(Producto_t matriz[NUM_ESTANTERIAS][NUM_UBICACIONES]) {
    int opcion;

    mostrarSubMenuVisualizar();
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    if (opcion == VISUALIZAR_ESTANTERIA) {
        int estanteria;
        printf("Ingrese la estanteria (0-%d): ", NUM_ESTANTERIAS - 1);
        scanf("%d", &estanteria);

        if (estanteria >= 0 && estanteria < NUM_ESTANTERIAS) {
            printf("\nProductos en la estanteria %d:\n", estanteria);
            for (int j = 0; j < NUM_UBICACIONES; j++) {
                printf("Ubicacion %d: [Codigo: %d, Nombre: %s, Cantidad: %d, Precio: %.2f]\n",
                        j, matriz[estanteria][j].codigo, matriz[estanteria][j].nombre,
                        matriz[estanteria][j].cantidad, matriz[estanteria][j].precio);
            }
        } else {
            printf("Estanteria fuera de rango.\n");
        }
    } else if (opcion == VISUALIZAR_COMPLETO) {
        printf("\nInventario completo:\n");
        for (int i = 0; i < NUM_ESTANTERIAS; i++) {
            for (int j = 0; j < NUM_UBICACIONES; j++) {
                printf("[Estanteria %d, Ubicacion %d]: [Codigo: %d, Nombre: %s, Cantidad: %d, Precio: %.2f]\n",
                        i, j, matriz[i][j].codigo, matriz[i][j].nombre,
                        matriz[i][j].cantidad, matriz[i][j].precio);
            }
        }
    } else {
        printf("Opcion invalida.\n");
    }
}

// Función para mostrar el menú principal
void mostrarMenu() {
    printf("\n===== Menu Principal =====\n");
    printf("%d. Cargar informacion\n", MENU_CARGAR);
    printf("%d. Procesar informacion\n", MENU_PROCESAR);
    printf("%d. Visualizar informacion\n", MENU_VISUALIZAR);
    printf("%d. Salir\n", MENU_SALIR);
}

// Función para mostrar el submenú de visualización
void mostrarSubMenuVisualizar() {
    printf("\n===== Submenu Visualizacion =====\n");
    printf("%d. Ver productos de una estanteria especifica\n", VISUALIZAR_ESTANTERIA);
    printf("%d. Ver inventario completo\n", VISUALIZAR_COMPLETO);
}
