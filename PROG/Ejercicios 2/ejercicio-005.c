#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_USERS 3

typedef struct{
    int age;
    char name[30];
}user_t;

void createUser(user_t[MAX_USERS], int *);

int main (void){
    int registered_users=0;
    user_t users[MAX_USERS];

    createUser(users,&registered_users);
    
    return 0;
}

void createUser(user_t users[], int *registeredUsers){
    int user_input=-1;
    int age=0;

    if(*registeredUsers>=MAX_USERS){
        printf("Max number of users reached.\n");
    }else{
        printf("Register a new user? 1 - YES, 0 - NO: ");
        scanf("%d",&user_input);

        while(user_input!=0){
            printf("Username:\n");
            scanf("%29s",users[*registeredUsers].name);

            printf("Age:\n");
            scanf("%d",&age);

            if(age<=0){
                while(age<=0){
                    printf("Please introduce a valid number.\n");
                    printf("Age:\n");
                    scanf("%d",&age);
                }
            }else{
                users[*registeredUsers].age=age;
            }

            printf("USERNAME: %s\n",users[*registeredUsers].name);
            printf("AGE: %d",users[*registeredUsers].age);

            printf("Register another user? 1 - YES, 0 - NO: \n");
            scanf("%d",user_input);
        }
        (*registeredUsers)++;
    }
}