#include <stdio.h>

int binarySearch(int *nums,int numsSize,int target)
{
    int start = 0;
    int end = numsSize - 1;

    while(end>=start){
        int mid = (end+start)/2;
        int guess = *(nums+mid);

        if(guess == target){
            return mid;
        }

        else if(guess > target){
            end = mid - 1;
        }

        else if(guess < target){
            start = mid + 1;
        }
    }

    return -1;
}

int main(void)
{
    int ar[] = {1,2,3,4,5,6,7};
    int n = sizeof(ar)/sizeof(ar[0]);
    
    int val=9;

    printf("%d\n",binarySearch(ar,n,val));

    return 0;
}