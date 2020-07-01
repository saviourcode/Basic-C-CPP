#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    pid_t id;
    int status;

    while(--argc && (id=fork())){ //Parent forks into child till all arguments are finished
        waitpid(id,&status,0);
    }
    printf("%d:%s\n",argc,argv[argc]);

    return 0;
}