#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char ID[10];
    float mathScore,literatureScore,englishScore;
    float average;
}Student;

int excellentNum = 0, goodNum = 0, normalNum = 0;
int totalStudent;

Student inputStudent(Student x){
    printf("\nEnter  ID = ");
    scanf("%s", &x.ID);
    do{
        printf("\nEnter Math-Literature-English score:  ");
        scanf("%f %f %f", &x.mathScore, &x.literatureScore, &x.englishScore);}
    while(((x.mathScore) > 10) || ((x.literatureScore) > 10) || ((x.englishScore) > 10));
    return x;
}
void inputListStudent(Student a[], int n){
    for(int i = 0; i < n; i++){
        printf("\n-----------");
        printf("\nStudent number %d", i+1);
        a[i] = inputStudent(a[i]);
        printf("\n--------------");
    }
}
void printStudent(Student x){
    printf("\nID = %s\t\tMath = %.2f\t\tLiterature = %.2f\t\tEnglish = %.2f\t\tAvarage =%.2f\t\tArchivement = ", x.ID, x.mathScore, x.literatureScore, x.englishScore, x.average);
    
}
void printListStudent(Student a[], int n){
    for(int i = 0; i < n; i++){
        printStudent(a[i]);
        if((a[i].average) > 8 && (a[i].mathScore) >= 7 && (a[i].literatureScore) >= 7 && (a[i].englishScore) >= 7){
            printf("Excellent");
        }
        else if((7 <= (a[i].average) <= 8) && (a[i].mathScore) >= 5 && (a[i].literatureScore) >= 5 && (a[i].englishScore) >= 5){
            printf("Good");
        }
        else{
            printf("Normal");
        }
    }
}
void calculateAverage(Student a[], int n){
    for(int i = 0; i < n; i++){
        a[i].average = (a[i].mathScore + a[i].literatureScore + a[i].englishScore) / 3;
    }
}
 void classifyStudent(Student a[], int n){
   for(int i = 0; i < totalStudent; i++){
        if((a[i].average) > 8 && (a[i].mathScore) >= 7 && (a[i].literatureScore) >= 7 && (a[i].englishScore) >= 7){
            excellentNum++;
        }
        else if((7 <= (a[i].average) <= 8) && (a[i].mathScore) >= 5 && (a[i].literatureScore) >= 5 && (a[i].englishScore) >= 5){
            goodNum++;
        }
        else{
            normalNum++;
        }
    }
}

 

int main(){
    Student a[100];
    do{
        printf("\nEnter total students: ");
        scanf("%d", &totalStudent);}
    while(totalStudent <= 0);
    inputListStudent(a,totalStudent);
    calculateAverage(a,totalStudent);
    classifyStudent(a, totalStudent);
    printf("\nExcellent Students: %d", excellentNum);
    printf("\nGood Students: %d", goodNum);
    printf("\nNormal Students: %d", normalNum);
    printf("\n---------------");
    printf("\nList students:");
    printListStudent(a,totalStudent);
    return 0;

}