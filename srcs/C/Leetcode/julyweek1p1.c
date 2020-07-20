#include <stdio.h>
#include <math.h>

int arrangeCoins(int n){
    return (-0.5 + sqrt(0.25+(long)n*2));
}

int main(void)
{
    printf("%d\n",arrangeCoins(15));
    return 0;
}