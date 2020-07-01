#include <unistd.h>
#include <stdio.h>

int main()
{
    printf("I'm printed once!");
    fork();
    printf("This line twice!\n");

    return 0;
}