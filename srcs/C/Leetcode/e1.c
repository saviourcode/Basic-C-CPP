//ID-7 Reverse Integer
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int reverse(int x)
{
    //int a = INT_MAX;
    //printf("%d\n",a);
    int temp=0;

    while(x!=0){
        if(temp>INT_MAX/10)
            return 0;
        if(temp<INT_MIN/10)
            return 0;
        temp=temp*10+x%10;
        //printf("%d\n",temp);
        x=x/10;
    }
   // printf("%d\n",temp);

    return temp;
}

int main()
{
    int rev;
    rev = reverse(INT_MAX);
    printf("%d\n",rev);

    return 0;
}