//If we misspell echo here, which was ehco then we run into
// the trouble of fork bombing because the process doesn't dies.

#include <unistd.h>
#define HELLO_NUMBER 10

int main()
{
    pid_t children[HELLO_NUMBER];
    int i;
    for(i =0; i<HELLO_NUMBER;i++){
        pid_t child = fork();

        //error checking
        if(child==-1){
            break;
        }

        if(child==0){
            //Child Process
            execlp("echo","echo","hello",NULL);
        }

        else{
            //Parent Process
            children[i] = child;
        }
    }

    //Wait for all the child processes to finish executing the code
    int j;
    for(j=0;j<i;j++){
        waitpid(children[j],NULL,0);
    }

    return 0;
}