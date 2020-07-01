#include <stdio.h>
void fibo(int n);

int a = 0;
int result = 1;

int main()
{
    printf("%d %d ",a,result);
    fibo(10);
}

void fibo(int n)
{
    if(n>2){
        if(n%2==0){
            a=result+a;
            printf("%d ",a);
        }
        else{  
            result=result+a;
            printf("%d ",result);
        }
        fibo(--n);
    }
    else
        return;
}
