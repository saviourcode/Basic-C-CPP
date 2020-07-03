//ID-9 Palindrome Number

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

bool isPalindrome(int x){
    if(x<0){
        return false;
    }
    
    int copy=x;
    int temp=0;
    
    while(x!=0){
        if(temp>INT_MAX/10)
            return false;
        if(temp<INT_MIN/10)
            return false;
        temp = temp*10 + x%10;
        
        x=x/10;
    }
    
    if(temp==copy)
        return true;
    
    return false;
}

int main()
{
    printf("%d\n",isPalindrome(INT_MAX));

    return 0;
}