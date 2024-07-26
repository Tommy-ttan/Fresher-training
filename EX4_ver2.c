#include <stdio.h>
#include <stdlib.h>

// #define BUBBLESORT 0
#define SELECTIONSORT 1
// #define INSERTIONSORT 2

void printArray(int a[], int Num);

void bubbleSort(int a[], int Num){
    for(int i = 0; i < Num; i++){
        for(int j = 0; j < Num - i - 1; j++){
            if(a[j] > a[j + 1]){
                int temp = a[j];
                a[j] = a[j + 1];
                a[j +1] = temp;
            }
        }
    }

    printf ("\nAfter sort:");
    printArray(a, Num);
}

void selectionSort(int a[], int Num){
    for(int i = 0; i < Num ; i++){
        int minIndex = i;
        for(int j = i+1; j < Num; j++){
            if (a[j] < a[minIndex]){
                minIndex = j; 
                }
            }
            int temp = a[minIndex];
            a[minIndex] = a[i];
            a[i] = temp;
        }

    printf ("\nAfter sort:");
    printArray(a,Num);
}

void insertionSort(int a[], int Num){
    for(int i = 1; i < Num; i++){
        int key = a[i];
        int j = i-1;
        while(j >= 0 && key < a[j]){
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j+1] = key;
    }

    printf("\nAfter sort:");
    printArray(a, Num);
}

void inputArray(int a[], int Num){
    for(int i = 0; i < Num; i++){
        printf("a[%d] = ", i+1);
        scanf("%d", (a+i));
    }
}

void printArray(int a[], int Num){
    for(int i = 0; i < Num; i++){
        printf("%d\t", a[i]);
    }
}

int binarySearch(int a[], int low, int high, int inputNum){
    while(low < high){
        int mid = low + (high - low) /2;
        if( a[mid] == inputNum){
            return mid;
        }

        if(a[mid] < inputNum){
            low = mid +1;
        }
        else{
            high = mid - 1;
        }
        }
        return -1;
    }


int main(){
    int *a;
    int Num;
    int index;
    int inputNum;

    a = (int*) malloc (Num*(sizeof(int)));

    do{
        printf("Enter Num = ");
        scanf("%d", &Num);
    }
    while(Num <= 0); 

    inputArray(a, Num);
    
    #ifdef BUBBLESORT
    bubbleSort(a, Num);
    #elif SELECTIONSORT
    selectionSort(a,Num);
    #else 
    insertionSort(a, Num);
    #endif
    
    printf("\nEnter inputNum = ");
    scanf("%d", &inputNum);

    index = binarySearch(a, 0, Num - 1, inputNum);
    if(index == -1){
        printf("Not Found");
    }
    else{
        printf("Index = %d", index);
    }
    free(a);
    return 0;
}

