#include <stdio.h>

typedef struct sum_AP {
    long long int sum;
    long long int terms;
    int d;
    int a;
} sum_AP;

sum_AP initstruct(long int,int);
void sum(sum_AP *);

int main(void)
{
    long int n;
    printf("Enter n=");
    scanf("%ld",&n);

    sum_AP three,five,fifteen;

    three = initstruct(n,3);
    five = initstruct(n,5);
    fifteen = initstruct(n,15);

    sum(&three);
    sum(&five);
    sum(&fifteen);

    printf("%lld\n",three.sum);
    printf("%lld\n",five.sum);
    printf("%lld\n",fifteen.sum);

    return 0;
}

sum_AP initstruct(long int n,int digit)
{
    sum_AP num;

    num.sum = 0;
    num.terms = (n-1)/digit;
    num.d = digit;
    num.a = digit;

    return num;
}

void sum(sum_AP *num)
{
    num->sum = ((num->terms)*(2*num->a + (num->terms - 1)*num->d))/2;
}