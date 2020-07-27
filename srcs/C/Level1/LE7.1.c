/* ID: 26. Remove Duplicates from Sorted Array
 * Problem Statement: Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
 *                    Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
 * Solution: We just have to return the length of new sorted array.
 *           The array is passed by reference so the array is automatically changed.
*/
#include <stdio.h>

int removeDuplicates(int* nums,int* newnums, int numsSize){
    if(numsSize==0){
        return 0;
    }

    int count = 0;
    
    for(int i=0;i<numsSize;i++){
        int flag = 0;
        for(int j=0;j<count;j++){
            if(nums[i]==newnums[j]){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            newnums[count++] = nums[i];
        }
    }

    return count;
}

int main(void)
{
    int ar[] = {1,2,1,2,1,1,3};
    int n = sizeof(ar)/sizeof(ar[0]);
    int newar[n];
    int len = removeDuplicates(ar,newar,n);
    printf("len=%d\n",len);
    for(int i=0;i<len;i++){
        printf("%d ",newar[i]);
    }
    printf("\n");
    return 0;
}