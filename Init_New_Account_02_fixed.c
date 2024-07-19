#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum{
    Weak,
    Normal, 
    Strong
}passwordLevel;

bool upperCaseAlphabet(char *password){
    for(int i = 0; i < strlen(password); i++){
        if(password[i] >= 65 && password[i] <= 90){
            return 1;
        }
    }
    return 0;
}

bool lowerCaseAlphabet(char *password){
    for(int i = 0; i < strlen(password); i++){
        if(password[i] >= 97 && password[i] < 122){
            return 1;
        }
    }
    return 0;
}

bool digits(char *password){
    for (int i = 0; i < strlen(password); i++){
        if(password[i] >= 48 && password[i] <= 57){
            return 1;
        }
    }
    return 0;
}

bool specialCharacter(char *password){
    for(int i = 0; i < strlen(password); i++){
        if((password[i] >= 32  && password[i] <= 47) ||
           (password[i] >= 58  && password[i] <= 64) ||
           (password[i] >= 91  && password[i] <= 96) ||
           (password[i] >= 123 && password[i] <= 127)){
            return 1;
           }
    }
    return 0;
}

passwordLevel checkPasswordLevel(char *password){
    int level;

    if((strlen(password)) < 8){
        return Weak;
    }
    
    level = upperCaseAlphabet(password) + lowerCaseAlphabet(password) + digits(password) + specialCharacter(password);

    switch(level){
        case 4:
            return Strong;
            break;
        case 3:
            return Normal;
            break;
        case 2:
            return Normal;
            break;
        default:
            return Weak;
    }
}

void inputAccount(char *username, char *password){
    passwordLevel level ;
    int attempts = 0;

    printf("\nUsername = ");
    scanf("%s", username);

    while(attempts < 5){
        printf("Password = ");
        scanf("%s", password);
        level = checkPasswordLevel(password);

        if(level == Weak){
            printf("---Weak Password---Enter the password---\n");
        }
        else if(level == Strong || level == Normal){
            break;
        }
        attempts++;
    }

    if(level == Weak){
        printf("\nWeak Password. Init Failed\n!");
    }
}

void printInforAccount(char *username, char *password){
    printf("\n-----Infor Account-----");
    printf("\nUsername = %s", username);
    printf("\nPassword = %s", password);
}
bool compareUsername(char *username, char *inputUsername){
    if(strcmp(username, inputUsername) == 0){
        return 1;
    }
    return 0;
}

bool comparePassword(char *password, char *inputPassword){
    if(strcmp(password, inputPassword) == 0){
        return 1;
    }
    return 0;
}

void login(char *username, char *password){
    int count = 0;
    char inputUsername[50];
    char inputPassword[50];

    while(count < 3){
        printf("Re-enter the username = ");
        scanf("%s", inputUsername);
        printf("Re-enter the password = ");
        scanf("%s", inputPassword);

        if(((compareUsername(inputUsername, username)) == 1) && ((comparePassword(password, inputPassword)) == 1)){ 
            printf("\n--Login successful--\n");
            break;
        }
        else{
            count++;
        }
        if(count == 3){
            printf("\n--Login Failed--\n");
            printInforAccount(username, password);
        }
    }
}


int main(){
    char username[50], password[50];
    inputAccount(username, password);
    login(username, password);
    printf("\n----------------------------");
    return 0;
}