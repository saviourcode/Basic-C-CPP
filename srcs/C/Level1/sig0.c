//C Program to illustrate, how to use default signalhandler
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    signal(SIGINT, SIG_DFL);
    while(1)
    {
        printf("Hello, World\n");
        sleep(1);
    }

    return 0;
}