#include <stdio.h>

int solve(int a,int b,int c)
{
    int Days;
    (a>=b)? (b>=c? (Days=c,c-=c):(Days=b,b-=b)):(a>=c? (Days=c,c-=c):(Days=a,a-=a));
        
    Days+=(a==0) ? (b>=c? c:b):((b==0) ? (a>=c? c:a):((a>=b) ? b:a));

    return Days;
}

int main(void)
{
    printf("Days: %d \n",solve(4,1,1));
    printf("Days: %d \n",solve(8,1,4));
    printf("Days: %d \n",solve(7,4,10));
    printf("Days: %d \n",solve(12,12,12));
    printf("Days: %d \n",solve(1,23,2));
    return 0;
}