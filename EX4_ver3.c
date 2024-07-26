#include <stdio.h>
#include <stdlib.h>

// #define BUBBLESORT 
// #define SELECTIONSORT 
#define INSERTIONSORT 

void printArray(int a[], int Num);

void bubbleSort(int a[], int Num){
    printf ("\nbubbleSort");
    for(int i = 0; i < Num; i++){
        for(int j = 0; j < Num - i - 1; j++){
            if(a[j] > a[j + 1]){
                a[j]   = a[j] ^ a[j+1];
                a[j+1] = a[j] ^ a[j+1];
                a[j]   = a[j] ^ a[j+1];
            }
        }
    }

    printf ("\nAfter sort:");
    printArray(a, Num);
    return;
}

void selectionSort(int a[], int Num){
    printf ("\nselectionSort");
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
    return;
}

void insertionSort(int a[], int Num){
    printf ("\ninsertionSort");
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
    return;
}

void inputArray(int* a, int Num){
    for(int i = 0; i < Num; i++){
        printf("a[%d] = ", i+1);
        scanf("%d", (a+i));
    }
    return;
}

void printArray(int a[], int Num){
    for(int i = 0; i < Num; i++){
        printf("%d\t", a[i]);
    }
    return;
}

int binarySearch(int a[], int low, int high, int inputNum){
    while(low <= high){
        int mid = low + (high - low) /2;

        if( a[mid] == inputNum){
            return mid;
        }

        if(a[mid] < inputNum){
            low = mid +1;
        }
        else{
            high = mid;
        }
        }
        return -1;
    }


int main(){
    int *a;
    int Num;
    int index;
    int inputNum;

    do{
        printf("Enter Num = ");
        scanf("%d", &Num);
    }
    while(Num <= 0); 

    a = (int*) malloc (Num*(sizeof(int))); 

    inputArray(a, Num);
    
    #ifdef BUBBLESORT
    bubbleSort(a, Num);
    #else
    #ifdef SELECTIONSORT
    selectionSort(a,Num);
    #else 
    insertionSort(a, Num);
    #endif
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

