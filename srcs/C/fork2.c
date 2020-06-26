#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t id = fork();

    if(id==-1) exit(1); //fork failed

    if(id>0){
        printf("Hello from the parent process\n");
    }

    else{
        printf("hello from the child process\n");
    }

    return 0;
}