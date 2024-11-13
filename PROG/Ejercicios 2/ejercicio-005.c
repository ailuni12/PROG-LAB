#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_USERS 3
#define EXIT 0

typedef struct{
    int userCode;
    char name[30];
}user_t;

typedef enum{
    create=1,
    sort,
    endprogram
}options_t;

void menu(user_t users[MAX_USERS],int *);
void createUser(user_t[MAX_USERS], int *);
void sort_users(user_t[MAX_USERS],int);

int main (void){
    int registered_users=0;
    user_t users[MAX_USERS];

    menu(users,&registered_users);
    
    return 0;
}

void menu(user_t users[],int *registered_users){
    int option=0;

    do{
        printf("\nUSER MANAGEMENT MENU:\n");
        printf("\t1-Create user.\n");
        printf("\t2-Sort users by code.\n");
        printf("\t3-End program.\n");
        scanf("%d",&option);

        switch (option){
        case create:
            createUser(users,registered_users);
            break;
        case sort:
            sort_users(users,*registered_users);
            break;
        case endprogram:
            printf("\nThanks for using this application. Press Enter to finish.\n");
            fflush(stdin);
            getchar();
            break;
        default:
            printf("Please enter a valid number.");
        }
    } while (option!=endprogram);
    
}

void createUser(user_t users[], int *registeredUsers){
    int user_input=-1;
    int userCode=0;

    if(*registeredUsers>=MAX_USERS){
        printf("Max number of users reached.\n");
    }else{
        printf("Register a new user? 1 - YES, 0 - NO: ");
        scanf("%d",&user_input);

        while(user_input!=EXIT && *registeredUsers<MAX_USERS){
            printf("Username: ");
            scanf("%29s",users[*registeredUsers].name);

            do{
                printf("User Code: ");
                scanf("%d",&userCode);

                if(userCode<=0){
                    while(userCode<=0){
                        printf("Please input a valid number.\n");
                        printf("User Code: ");
                        scanf("%d",&userCode);
                    }
                }else{
                    users[*registeredUsers].userCode=userCode;
                }
            }while(userCode<=0);

            printf("Created user successfully.\n");
            printf("USERNAME: %s\n",users[*registeredUsers].name);
            printf("CODE: %d\n",users[*registeredUsers].userCode);

            (*registeredUsers)++;

           if(*registeredUsers>=MAX_USERS){
            printf("Reached max users.\n");
            }else{
                printf("Register another user? 1 - YES, 0 - NO: \n");
                scanf("%d",&user_input);
            }
        }
    }
}

void sort_users(user_t users[],int registeredusers){
    user_t aux;

    printf("\nUSER LIST BEFORE SORTING:\n");
    for(int i=0;i<registeredusers;i++){
        printf("USERNAME: %s ",users[i].name);
        printf("// CODE: %d\n",users[i].userCode);
    }


    printf("\nSORTING LIST......\n");
    for(int i=0;i<MAX_USERS-1;i++){
        for(int j=0;j<MAX_USERS-i-1;j++){
            if(users[j].userCode<users[j+1].userCode){
                aux.userCode=users[j].userCode;
                strcpy(users[j].name,aux.name);

                users[j].userCode=users[j+1].userCode;
                strcpy(users[j].name,users[j+1].name);

                users[j+1].userCode=aux.userCode;
                strcpy(users[j+1].name,aux.name);
            }
        }
    }

    printf("\nUSER LIST AFTER SORTING:\n");
    for(int i=0;i<registeredusers;i++){
        printf("USERNAME: %s ",users[i].name);
        printf("// CODE: %d\n",users[i].userCode);
    }

}