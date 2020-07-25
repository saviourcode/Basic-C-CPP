#include <stdio.h>

int sol(int * nums,int numsSize)
{
    int count = 1;
    int large = 0;
    for(int i=0;i<numsSize;i++){
        if(i!=numsSize-1 && nums[i]<=nums[i+1]){
           count++;
        }
        else if(i!=numsSize-1 && nums[i]>nums[i+1]){
            if(count>=large){
                large=count;
            }
            count = 1;
        }
    }

    return large;
}

int main(void)
{
    int ar[] = {10,23,1,5,3,6,7,9,9,3};
    int n = sizeof(ar)/sizeof(ar[0]);

    int r = sol(ar,n);
    printf("%d\n",r);
}