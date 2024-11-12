#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void increase_one (int *);
void print_value (int);
void increase_two (int *);


int main (void){
    int number=0;
    printf("variable address: %d\n",&number);
    
    increase_one(&number);
    print_value(number);
    printf("variable address (within main): %d\n",&number);

    return 0;
}

void increase_one (int * number){
    printf("running increase_one function:\n");
    (*number)++;
    printf("increased by 1\n");
    
    print_value(*number);

    increase_two(number);
    printf("-------------1\n");

}

void print_value (int number){
    printf("running print_values function:\n");
    printf("number: %d\n",number);
    printf("variable address (within function): %d\n",&number);
    printf("-------------2\n");
}

void increase_two (int * number){
    printf("running increase_two function:\n");
    (*number)++;
    printf("increased by 1\n");
    printf("-------------3\n");
}