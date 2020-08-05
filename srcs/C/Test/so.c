#include <stdio.h>

int main(void){
    char first[20];
    char last[20];
    printf("Enter first name: ");
    scanf("%s", first);
    printf("Enter last name: ");
    scanf("%s", last);
    printf("Hello %-60s %-60s. \n", first, last);
    return 0;
}