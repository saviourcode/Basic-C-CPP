/* ID: 21. Merge Two Sorted Lists
 * Problem Statement: Merge two sorted linked lists and return it as a new sorted list. 
 *                     The new list should be made by splicing together the nodes of the first two lists.
 *                     Example:
 *                              Input: 1->2->4, 1->3->4
 *                               Output: 1->1->2->3->4->4
 * Solution: Insert and Scroll Method used. If any of the element is inserted into the merged list then only scroll to the next element in that list.
 *           If the element is not inserted then keep the pointer in that place only.
 *
 *            +--------+--------+-------------+
 *            | List 1 | List 2 | Merged List |
 *            +--------+--------+-------------+ 
 *            | 1 <-   | 1 <-   |      1      |
 *            | 2      | 3      |      1      |
 *            | 4      | 5      |             |
 *            +--------+--------+-------------+
 *            | 1      | 1      |      1      |
 *            | 2 <-   | 3 <-   |      1      |
 *            | 4      | 5      |      2      |
 *            +--------+--------+-------------+
 *            | 1      | 1      |      1      |
 *            | 2      | 3 <-   |      1      |
 *            | 4 <-   | 5      |      2      |
 *            |        |        |      3      |
 *            +--------+--------+-------------+
 *            | 1      | 1      |      1      |
 *            | 2      | 3      |      1      |
 *            | 4 <-   | 5 <-   |      2      |
 *            |        |        |      3      |
 *            |        |        |      4      |
 *            +--------+--------+-------------+
 *            |      List 1 Reached NULL      |
 *            +--------+--------+-------------+
 *            |  NULL  | 1      |      1      |
 *            |        | 3      |      1      |
 *            |        | 5 <-   |      2      |
 *            |        |        |      3      |
 *            |        |        |      4      |
 *            |        |        |      5      |
 *            +--------+--------+-------------+
*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void printll(struct ListNode* head)
{
    struct ListNode* currentPtr=NULL;
    currentPtr=head;
    while(currentPtr!=NULL){
        printf("%d->",currentPtr->val);
        currentPtr=currentPtr->next;
    }
    printf("NULL\n");
}

void push(struct ListNode** head,int value)
{
    struct ListNode* newNode=NULL;
    newNode=malloc(1*sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = *head;

    *head = newNode;
}

void append(struct ListNode** head, int value)
{
    struct ListNode* currentPtr = *head;
    struct ListNode* newNode = NULL;

    newNode = malloc(1*sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;

    if(*head==NULL){
        *head=newNode;
    }
    else{
        while(currentPtr->next!=NULL){
            currentPtr=currentPtr->next;
        }
        currentPtr->next=newNode;
    }
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* mergeList = NULL;
    
    while(l1!=NULL && l2!=NULL){
        if(l1->val>l2->val){
            append(&mergeList,l2->val);
            l2=l2->next;
        }
        else if(l1->val<l2->val){
            append(&mergeList,l1->val);
            l1=l1->next;
        }
        else if(l1->val==l2->val){
            append(&mergeList,l1->val);
            append(&mergeList,l2->val);
            l1=l1->next;
            l2=l2->next;
        }
    }

    while(l1!=NULL){
        append(&mergeList,l1->val);
        l1=l1->next;
    }

    while(l2!=NULL){
        append(&mergeList,l2->val);
        l2=l2->next;
    }

    return mergeList;
}

int main(void)
{
    struct ListNode* headl1=NULL;
    struct ListNode* headl2=NULL;
    struct ListNode* mergeHead = NULL;

    append(&headl1,1);
    append(&headl1,2);
    append(&headl1,4);

    append(&headl2,1);
    append(&headl2,3);
    append(&headl2,5);

    // Debugging
    // printll(headl1);
    // printll(headl2);

    mergeHead=mergeTwoLists(headl1,headl2);

    printll(mergeHead);
}