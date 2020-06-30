#include <stdio.h>

struct command {
    char *name;
    void (*function)(void);
};

typedef struct command command;

void help_command(void){ printf("Help\n");}
void quit_command(void){ printf("Quit\n");}

command commands[] = {
        {"Help",help_command},
        {"Quit",quit_command},
};

int main()
{
    int options = sizeof(commands)/sizeof(command);
    for(int i = 0; i< options; i++){
        printf("[%d] %s\n",i,commands[i].name);
    }
    int select;
    scanf("%d",&select);
    commands[select%options].function();

    return 0;
}
