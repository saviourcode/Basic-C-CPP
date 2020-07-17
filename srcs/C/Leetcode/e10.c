/* ID: 35. Search Insert Position
 * Problem Statement: Given a sorted array and a target value, return the index if the target is found. 
 *                    If not, return the index where it would be if it were inserted in order.
 *                    You may assume no duplicates in the array.
 *                    Example: 
 *                            Input: [1,3,5,6] target = 5
 *                            Output: 2
 *
 *                            Input: [1,3,5,6] target = 2
 *                            Output: 1
 * Solution: Use Binary Search Algorithm to find the target element inside the array.
 *           Reference: https://www.geeksforgeeks.org/binary-search/
 */

#include <stdio.h>

int avg(int *a,int start,int end,int val)
{
    
    if(end>=start){
        int mid = start + (end-start)/2;
        
        if(*(a+mid) == val){
            return mid; 
        }

        else if(*(a+mid) > val){
            
            return avg(a, start, mid - 1, val);
        }

        else if(*(a+mid) < val){
            return avg(a, mid + 1, end, val);
        }

    }
    
    return start;
}

int searchInsert(int* nums, int numsSize, int target)
{
    if(numsSize==0){
        return 0;
    }

    int index = avg(nums,0,numsSize-1,target);

    return index;

}

int main(void)
{
    int ar[] = {1,20,30,40,100,200,300,500};
    int n = sizeof(ar)/sizeof(ar[0]);
    int index;
    index = searchInsert(ar,n,21);
    printf("%d\n",index);
    return 0;
}