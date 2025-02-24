#include <stdio.h>
#include <string.h>

typedef struct{
    char string[30];
}string_t;

int main(void){
    string_t array[2];

    printf("\nWrite a sentence: ");
    fflush(stdin);
    fgets(array[0].string,sizeof(array[0].string),stdin);
    array[0].string[strcspn(array[0].string,"\n")]='\0';

    printf("\nString: %s",array[0].string);
    printf("\nSize of: %d",sizeof(array[0].string));

    return 0;
}