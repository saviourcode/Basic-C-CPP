/* ID: 26. Remove Duplicates from Sorted Array
 * Problem Statement: Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
 *                    Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 * Solution: We just have to return the length of new sorted array.
 *           The array is passed by reference so the array is automatically changed.
*/
#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    if(numsSize==0){
        return 0;
    }
    int temp;
    int len=1;
    temp=*(nums+0);
    for(int i=1;i<numsSize;i++){
        if(temp!=*(nums+i)){
            temp=*(nums+i);
            *(nums+(len))=temp;
            len++;
        }
    }

    return len;
}

int main(void)
{
    int ar[] = {};
    int len = removeDuplicates(ar,0);
    printf("len=%d\n",len);
    for(int i=0;i<len;i++){
        printf("%d ",ar[i]);
    }
    printf("\n");
    return 0;
}