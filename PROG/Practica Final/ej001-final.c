#include <stdio.h>

void increase_one (int *);

int main(void){
    int varX = 0;
    int varY = 0;

    printf("varX: %d\n",varX);
    printf("varY: %d\n",varY);

    increase_one(&varX);

    return 0;
}

void increase_one(int * varX){
   
    for(int i=0;i<10;i++){
        (*varX)++;
        printf("varX: %d\n",*varX);
    }

}