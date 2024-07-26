#include <stdio.h>
#include <stdlib.h>

void inputArray2D(int **arr, int row, int cols){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < cols; j++){
            printf("\narr[%d][%d] = ", i, j);
            scanf("%d", &(arr[i][j]));
        }
    }
}

void printArray2D(int **arr, int row, int cols){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < cols; j++){
            printf("%5d\t", arr[i][j]);
        }
        printf("\n");
    }
}

void calcSum(int **arr, int row, int cols){
    int sum = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < cols; j++){
            if(i == j){
                sum += arr[i][j];
            }  
        }
    }
    printf("\nSum = %d", sum);
}

void printbyCol(int **arr, int row, int cols){
    for(int i = 0; i < row; i++){
        printf("%5d\n", arr[i][cols]);
    }
}

void printbyRow(int **arr, int row, int cols){
    for(int i = 0; i < cols; i++){
        printf("%5d\t", arr[row][i]);
    }
}

void callbackFunc(void (*callbackPtr)(int**, int,int), int **arr, int row, int cols){
    callbackPtr(arr,row,cols);
}

int main(){
    int **arr;
    int row;
    int col;
    int rowInput;
    int colsInput;
    int choice;
    void (*funcPtr)(int**, int, int);

    printf("\nEnter row =  ");
    scanf("%d", &row);
    printf("\nEnter cols = ");
    scanf("%d", &col);

    arr = (int**)malloc(row*sizeof(int*));
    for(int i = 0; i < row; i++){
        arr[i]  = (int*) malloc(col* sizeof(int));
    }

    inputArray2D(arr, row, col);
    printf("\nArray 2D:\n\n");
    printArray2D(arr, row, col);

    funcPtr = calcSum;
    funcPtr(arr, row, col);

    printf("\nPrint by Row or Col? Row = 0 || Col = 1.");
    printf("\nEnter choice = ");
    scanf("%d", &choice);

    if(choice == 0){
        void (*callbackPtr)(int**, int, int) = printbyCol;

        printf("\nEnter colInput = ");
        scanf("%d", &colsInput);
        
        printf("\nPrint Col:\n\n");
        callbackFunc(callbackPtr, arr, row, colsInput);
    }
    else if(choice == 1){
        void (*callbackPtr)(int**, int, int) = printbyRow;

        printf("\nEnter rowInput = ");
        scanf("%d", &rowInput);
        
        printf("\nPrint Row:\n\n");
        callbackFunc(callbackPtr, arr, rowInput, col);
    }
    return 0;
}
