/* Reference of this code is taken from: http://cslibrary.stanford.edu/103/LinkedListBasics.pdf
 * What works? 
 *  1. Pushing elements to the head of the list
 *  2. Appending elements to the tail of the list
 *  3. Copying one list to other list
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * next;
} node;

void printll(node * currentPtr);
void append(node ** head, int value);
void push(node ** head,int value);
node * copylist(node * head);

int main(void)
{
    node * head1 = NULL;
    node * head2 = NULL;

    push(&head1,40);

    append(&head1,1);

    push(&head1,35);
    
    printf("First List\n");
    printll(head1);

    printf("Copying List\n");
    head2 = copylist(head1);
    
    printll(head2);

    return 0;
}

void printll(node * currentPtr)
{
    while(currentPtr != NULL){
        printf("%d  ",currentPtr->data);
        currentPtr = currentPtr->next;
    }
    printf("\n");
}

void push(node ** head,int value)
{
    node * newNode = NULL;

    newNode = malloc(1*sizeof(node));
    newNode->data = value;
    newNode->next = * head;
    
    * head = newNode;
}

void append(node ** head, int value)
{
    node * currentPtr = *head;
    node * newNode = NULL;

    newNode = malloc(1*sizeof(node));
    newNode->data = value;
    newNode->next = NULL;

    if(* head == NULL){
        * head = newNode;
    }

    else{
        while(currentPtr->next != NULL){
            currentPtr = currentPtr->next;
        }
        currentPtr->next = newNode;
    }
    
}

node * copylist(node * head)
{
    node * current = head;
    node * newList = NULL;
    node * tail = NULL;

    while(current != NULL){
        if(newList == NULL){
            newList = malloc(1*sizeof(node));
            newList->data = head->data;
            newList->next = NULL;
            tail = newList;
        }
        else{
            tail->next = malloc(1*sizeof(node));
            tail = tail->next;
            tail->data = current->data;
            tail->next = NULL;
        }
        current = current->next;
    }

    return newList;
}