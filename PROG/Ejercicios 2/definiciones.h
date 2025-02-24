#include <stdint.h>

#define MAX_CLI 5
#define MAX_CHAR 50

#define TRUE 1
#define FALSE 0
#define NOT_FOUND -1

typedef enum{
    INGRESAR=1,
    BUSCAR,
    LIST_CODIGOS,
    LIST_APELLIDOS,
    SALIR
}opcion_t;

typedef struct{
    uint16_t dia;
    uint16_t mes;
    uint16_t anio;
}fecha_t;

typedef struct{
    uint16_t codigo;
    char nombre[50];
    char apellido[50];
    fecha_t fechaNacimiento;
}cliente_t;

void pausa(void);
opcion_t menu(void);
void cargarCliente(cliente_t *,int *);
int buscarCliente(cliente_t[], int *);
void mostrarCliente(cliente_t *, int); 
void ordenarClientesPorCodigo(cliente_t[], int);
void ordenarClientesPorApellido(cliente_t[], int);