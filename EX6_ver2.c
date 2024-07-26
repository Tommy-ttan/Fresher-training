#include <stdio.h>
#include <stdlib.h>

typedef enum {
    choice_none,
    choice_col,
    choice_row,
    choice_max,
}choice;

void inputArray2D(int **arr, int row, int cols){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < cols; j++){
            printf("\narr[%d][%d] = ", i, j);
            scanf("%d", &(arr[i][j]));
        }
    }
    return;
}

void printArray2D(int **arr, int row, int cols){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < cols; j++){
            printf("%5d\t", arr[i][j]);
        }
        printf("\n");
    }
    return;
}

int calcSum(int **arr, int row, int cols){
    int sum = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < cols; j++){
            if(i == j){
                sum += arr[i][j];
            }  
        }
    }
    return sum;
}

void cbPrintbyCol(int **arr, int row, int cols){
    for(int i = 0; i < row; i++){
        printf("%5d\n", arr[i][cols]);
    }
    return;
}

void cbPrintbyRow(int **arr, int row, int cols){
    for(int i = 0; i < cols; i++){
        printf("%5d\t", arr[row][i]);
    }
    return;
}

void execute_callback(void (*callbackPtr)(int**, int,int), int **arr, int row, int cols){
    callbackPtr(arr,row,cols);
    return;
}

int main(){
    int **arr;
    int row;
    int col;
    int rowInput;
    int colsInput;
    int choice;
    int (*funcPtr)(int**, int, int);
    void (*cbPtr)(int**, int, int);

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
    printf("Sum is %d", funcPtr(arr, row, col));

    printf("\nPrint by Row or Col? Col = 1 || Row = 2.");
    printf("\nEnter choice = ");
    scanf("%d", &choice);

    if(choice == choice_col){
        cbPtr = cbPrintbyCol;

        printf("\nEnter colInput = ");
        scanf("%d", &colsInput);
        
        printf("\nPrint Col:\n\n");
        execute_callback(cbPtr, arr, row, colsInput);
    }
    else if(choice == choice_row){
        cbPtr = cbPrintbyRow;

        printf("\nEnter rowInput = ");
        scanf("%d", &rowInput);
        
        printf("\nPrint Row:\n\n");
        execute_callback(cbPtr, arr, rowInput, col);
    }
    return 0;
}
