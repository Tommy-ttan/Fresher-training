#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{
    Weak,
    Normal, 
    Strong
}passwordLevel;

passwordLevel checkPasswordLevel( char *password){
    int upperCaseAlphabet = 0, lowerCaseAlphabet = 0, digits = 0, specialCharacter = 0;
    int length = strlen(password);
    if(length < 8){
        return Weak;
    }
    for(int i = 0; i < length; i++){
        if(password[i] >= 65 && password[i] <= 90){
            upperCaseAlphabet = 1;
        }
        else if(password[i] >= 97 && password[i] < 122){
            lowerCaseAlphabet  = 1;
        }
        else if(password[i] >= 48 && password[i] <=57){
            digits = 1;
        }
        else if((password[i] >= 32 && password[i] <= 47) || 
                (password[i] >= 58 && password[i] <= 64) || 
                (password[i] >= 91 && password[i] <= 96) ||
                (password[i] >= 123 && password[i] <= 127)){
            specialCharacter = 1;
        }
    }
    int level = upperCaseAlphabet + lowerCaseAlphabet + digits + specialCharacter;
    if(level == 4){
        return Strong;
    }
    else if(level >= 3){
        return Normal;
    }
    else{
        return Weak;
    }
}

void inputAccount(char *username, char *password){
    printf("\nUsername = ");
    scanf("%s", username);

    passwordLevel level;
    int count = 0;

    while(count < 5){
        printf("Password = ");
        scanf("%s", password);

        level = checkPasswordLevel(password);

        if(level == Weak){
            printf("---WEAK PASSWORD---Enter the pw:\n");
        }
        else if(level == Strong || level == Normal){
            break;
        }
        count++;
    }

    if(level == Weak){
        printf("\nWeak Password. Init Failed!");
    }
}
void printInforAccount(char *username, char *password){
    printf("\n-----Infor Account-----");
    printf("\nUsername = %s", username);
    printf("\nPassword = %s", password);
}

void login(char *username, char *password){
    int count = 0;
    char inputUsername[50], inputPassword[50];
    while(count < 3){
        printf("Re-enter the username = ");
        scanf("%s", inputUsername);
        printf("Re-enter the password = ");
        scanf("%s", inputPassword);

        int result1 = strcmp(inputUsername, username);
        int result2 = strcmp(inputPassword, password);

        if((result1 == 0) && (result2 == 0)){
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
    //printInforAccount(username,password);
    return 0;
}