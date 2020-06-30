#include <stdio.h>

struct command {
    char *name;
    void (*function) (void);
};

typedef struct command command;

void help_command(void){ printf("Help\n");}
void quit_command(void){ printf("Quit\n");}

command commands[] = {
        {"help",help_command},
        {"quit",quit_command},
};

int main()
{
    printf("%ld\n",sizeof(commands));
    commands[0].function();
}
