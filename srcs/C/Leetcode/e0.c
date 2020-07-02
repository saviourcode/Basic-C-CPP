#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 0;
    for(int i=0 ; i<numsSize; i++){
        for(int j=i+1; j<numsSize; j++){
            if(*(nums+i) + *(nums+j) == target){
                int *arr = (int*)malloc(sizeof(int)*2);
                *arr = i;
                *(arr+1) = j;
                *returnSize = 2;
                return arr;
            }
        }
    }

    return NULL;
    
}

int main()
{
    int arr[] = {2,7,11,13};
    int returnSize;
    int *result = twoSum(arr,4,9,&returnSize);

    for(int i =0; i<returnSize; i++)
        printf("%d ",*(result+i));

    printf("\n");
}
