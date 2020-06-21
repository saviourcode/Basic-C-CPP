#include <unistd.h> /* fork is declared here */
#include <stdio.h> /* printf is declared here */

int main()
{
    int answer = 84 >> 1;
    printf("Answer: %d",answer);
    fork();
    return 0;
}