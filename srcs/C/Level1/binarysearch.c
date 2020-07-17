#include <stdio.h>

int binarySearch(int *a,int start,int end,int val)
{
    
    if(end>=start){
        int mid = start + (end-start)/2;
        
        if(*(a+mid) == val){
            return mid; 
        }

        else if(*(a+mid) > val){
            return binarySearch(a, start, mid - 1, val);
        }

        else if(*(a+mid) < val){
            return binarySearch(a, mid + 1, end, val);
        }

    }
    
    return start;
}

int main(void)
{
    int ar[] = {1,20,30,40,100,200,300,500};
             // 0,1, 2, 3, 4,  5,  6,  7
    int n = sizeof(ar)/sizeof(ar[0]);
    int i;
    i = binarySearch(ar,0,n-1,201);
    printf("Element is present at=%d\n",i);
}

