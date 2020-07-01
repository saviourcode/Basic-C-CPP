#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

void printll(node* currentPtr)
{
    while(currentPtr != NULL){
        printf("%d  ",currentPtr->data);
        currentPtr = currentPtr->next;
    }
}

void push(node** head,int value)
{
    node *newNode = NULL;

    newNode = malloc(1*sizeof(node));
    newNode->data = value;
    newNode->next = *head;
    
    *head = newNode;
}

void append(node** head, int value)
{
    node *currentPtr = *head;
    node *newNode = NULL;

    newNode = malloc(1*sizeof(node));
    newNode->data = value;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
    }

    else{
        while(currentPtr->next != NULL){
            currentPtr = currentPtr->next;
        }
        currentPtr->next = newNode;
    }
    
}

int main(void)
{
    node* head = NULL;

    push(&head,40);

    append(&head,1);

    push(&head,35);

    printll(head);

    return 0;
}