#include<stdio.h>
#include<stdlib.h>

#define IMPORTSTAFFINFOTEAM_A
#define IMPORTSTAFFINFOTEAM_B TEAMB

typedef struct{
    int ID  ;
    float salary;
}staffInfoTeam_A;

typedef struct{
    int ID;
    char name[50];
    float salary;
}staffInfoTeam_B;

void addStaffInfoTeamA(staffInfoTeam_A *staff, int staffTeamANum){
    for(int i = 0; i < staffTeamANum ; i++){
        printf("\n-- Enter Staff Infor %d--\n", i+1);
        do{
            printf("\nID = ");
            scanf("%d",&(staff+i)->ID);
        }
        while((staff+i)->ID >= 100);
        printf("Salary = ");
        scanf("%f", &(staff+i)->salary);
    }
}

void printStaffTeamA(staffInfoTeam_A *staff, int staffTeamANum){
    for(int i = 0; i < staffTeamANum; i++){
        printf("ID = %d\t\tSalary = %.2f\n", (staff+i)->ID, (staff+i)->salary);
    }
}

void addStaffInfoTeamB( staffInfoTeam_B *staff, int staffTeamBNum){
    for(int i = 0; i < staffTeamBNum ; i++){
        printf("\n-- Enter Staff Team A Infor %d--\n", i+1);
        do{
            printf("\nID = ");
            scanf("%d",&(staff+i)->ID);
        }
        while((staff+i)->ID >= 100);
        printf("\nName = ");
        fflush(stdin);
        scanf("%[^\n]s", (staff+i)->name);
        printf("Salary = ");
        scanf("%f", &(staff+i)->salary);
    }
}

void printStaffTeamB(staffInfoTeam_B *staff, int staffTeamBNum){
    for(int i = 0; i < staffTeamBNum; i++){
        printf("ID = %d\t\tName = %-20s\t\t\tSalary = %.2f\n", (staff+i)->ID, (staff+i)->name, (staff+i)->salary);
    }
}

void importStaffInfoTeamA(){
    int staffTeamANum;
    staffInfoTeam_A *staffA;

    do{
        printf("Enter StaffNum = ");
        scanf("%d", &staffTeamANum);
    }
    while(staffTeamANum <= 0);

    staffA = (staffInfoTeam_A*)malloc(staffTeamANum*sizeof(staffInfoTeam_A));

    if(staffA == NULL){
        printf("\nFailed!");
    }
    addStaffInfoTeamA(staffA, staffTeamANum);
    printf("\n--Staff Info Team A--\n");
    printStaffTeamA(staffA, staffTeamANum);
}

void importStaffInfoTeamB(){
    int staffTeamBNum;
    staffInfoTeam_B *staffB;

    do{
        printf("Enter StaffTeamBNum = ");
        scanf("%d", &staffTeamBNum);
    }
    while(staffTeamBNum <= 0);

    staffB = (staffInfoTeam_B*)malloc(staffTeamBNum*sizeof(staffInfoTeam_B));

    if(staffB == NULL){
        printf("\nFailed!");
    }
    addStaffInfoTeamB(staffB, staffTeamBNum);
    printf("\n--Staff Info Team B--\n");
    printStaffTeamB(staffB, staffTeamBNum);
}
int main(){
    #ifdef IMPORTSTAFFINFOTEAM_A
    importStaffInfoTeamA();
    #else
    importStaffInfoTeamB();
    #endif
    
    return 0;
}