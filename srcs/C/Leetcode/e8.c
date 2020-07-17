/* ID: 27. Remove Element
 * Problem Statement: Given an array nums and a value val, remove all instances of that value in-place and return the new length.
 *                    Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 *                    The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 *                    Example: 
 *                          Input: Given nums = [3,2,2,3], val = 3,
 *                          Output: [2,2], returned value must be new size of array = 2
 * Solution: Find the instance of the element using loop and if condition then remove those elements from the arrays using nested loop
*/
#include <stdio.h>

int removeElement(int* nums, int numsSize, int val){
    if(numsSize==0){
        return 0;
    }
    int temp;
    int len=numsSize;
    for(int i=0;i<len;i++){
        if(*(nums+i)==val){
            for(int j=i;j<len-1;j++)
                *(nums+j)=*(nums+j+1);
            len--;
            i--;
        }
            
    }
    return len;
}


int main(void)
{
    int ar[] = {1,1,1,2,2,3,3};
    int len;
    len = removeElement(ar,7,3);
    printf("Len=%d\n",len);
    for(int i=0;i<len;i++){
        printf("%d ",ar[i]);
    }
    printf("\n");

    return 0;
}