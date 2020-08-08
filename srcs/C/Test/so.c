#include<stdio.h>
#include<string.h>
int main()
{
    int a,i;
    printf("\nEnter the number of names you want :");
    scanf("%d",&a);
    char c;
    scanf("%c",&c);
    char names[50][50];
    for(i=0;i<a;i++)
    {
        printf("\n%d name :",i);
        gets(names[i]);
    }
    printf("\nThe required name lists :");
    for(int i=0;i<a;i++)
    {
    printf("\n%d name :",i+1);
    puts(names[i]);
    }
    return 0;
}