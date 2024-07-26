#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *head = NULL;

int lengthList(){
    int length = 0;
    Node *tempNode;
    for(tempNode = head; tempNode != NULL; tempNode = tempNode->next){
        length++;
    }
    return length;
}

void addFirst(int data){
    Node *newNode = ( Node*)malloc(sizeof( Node));

    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return;
}

void inputNode(){
    int num;
    int data;

    do{
        printf("\nEnter Num = ");
        scanf("%d", &num);
    }while(num <= 0);

    for(int i = 0; i < num; i++){
        printf("\nData %d = ", i);
        scanf("%d", &data);
        addFirst(data);
    }
    return;
}

void deleteFirst(){
    Node *tempNode = head;
    
    if(head == NULL){
        return;
    }

    head = head->next;
    free(tempNode);
    return;
}

void addLast(int data){
    Node *newNode  = (Node*)malloc(sizeof(Node));
    Node *tempNode = head;

    newNode->data = data;
    newNode->next = NULL;
    
     if( head == NULL){
        head = newNode;
     }

    while(tempNode->next != NULL){
        tempNode = tempNode->next;
    }
    tempNode->next = newNode;
    return;
}

void deleteLast(){
    Node *tempNode = head;
    Node *delNode = tempNode->next;
    if(head == NULL){
        return;
    }

    if(tempNode->next == NULL){
        free(head);
        head = NULL;
    }

    while(tempNode->next->next != NULL){
        tempNode = tempNode->next;
    }
    
    tempNode->next = NULL;
    free(delNode);
    return;
}

void insertNode(int position, int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    Node *tempNode = head;
    int length = lengthList();
    
    if( position > (length + 1)){
        printf("\nImpossible\n");
        return;
    }
     if( position == 0){
        addFirst(data);
        return;
    }
    
    else{
        for(int i = 1; i < (position - 1); i++){
            tempNode = tempNode->next;
        }
        newNode->next = tempNode->next;
        tempNode->next = newNode;
    }
    return;  
}

void deleteNode(int position){
    Node *tempNode = head;
    Node *nodeCurrent;

    if(position < 0){
        printf("\nImpossible.\n");
        return;
    }
    if(position == 0){
        deleteFirst();
        return;
    }
    else{
        for(int i = 1; i < (position - 1); i++){
            tempNode = tempNode->next;
        }
        nodeCurrent    = tempNode->next;
        tempNode->next = nodeCurrent->next;
        free(nodeCurrent);
    }
    return;
}

int findDataIndex(int dataFind){
    Node *current = head;
    int countIndex = 0;

    if (head == NULL){
        return 0 ;
    }

    while(current->data != dataFind){
        if(current->next == NULL){
            return 0;
        }
        else{
            current = current->next;
            countIndex++;
        }
    }
    return countIndex;
}

void sort(){
    Node *i;
    Node *j;
    for(i = head; i != NULL; i = i->next){
        for(j = i->next; j != NULL; j = j->next){
            if(i->data > j->data){
                int tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
    return;
}


bool isEmpty(){
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
}

void printList(){
    Node *ptr = head;
    while(ptr != NULL){
        printf("%5d", ptr->data);
        ptr = ptr->next;
    }
    return;
}

int main(){

    int positionInsert;
    int dataInsert;
    int positionDelete;
    int dataFindIndex;
    int index = 0;
    
    if(isEmpty()){
        printf("\nEmpty\n");
    }

    inputNode();
    printList();

    printf("\nEnter positionInsert = ");
    scanf("%d", &positionInsert);
    printf("\nEnter dataInsert =");
    scanf("%d", &dataInsert);

    insertNode(positionInsert, dataInsert);

    printf("\nAfter Insert:\n");
    printList();

    printf("\nEnter positionDelete = ");
    scanf("%d", &positionDelete);

    deleteNode(positionDelete);

    printf("\nAfter delete:\n");
    printList();

    printf("\nEnter dataFindIndex = ");
    scanf("%d", &dataFindIndex);

    index = findDataIndex(dataFindIndex);
    printf("\nIndex = %d", index);

    sort();
    printf("\nAfter Sort:\n");
    printList();

    return 0;
}
