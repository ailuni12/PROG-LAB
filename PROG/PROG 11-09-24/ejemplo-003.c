#include <stdio.h>

int main(int argc, char *argv[],char* envp[]){
    printf("\n");
    printf("%d\n",argc);
    printf("%s\n",argv[0]);
    printf("%s\n",argv[1]);
    printf("%s\n",envp[0]);

    return 0;
}