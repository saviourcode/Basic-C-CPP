#include <stdio.h>
#include <stdlib.h>
#define BLANK {NULL,0}

typedef struct string{
    char* str;
    int size;
}string;

void append(string* p,char c)
{
    if(p->str==NULL){
        p->str = malloc((p->size+2)*sizeof(char));
    }
    else{
        p->str = realloc(p->str,(p->size+2)*sizeof(char));
    }

    *(p->str+p->size) = c;
    *(p->str+p->size+1) = '\0';
    p->size++;
}

int main(void)
{
    string result = BLANK;
    char c;
    printf("Enter the name: ");
    // Scan the input from the User.
    while((c=getchar())!='\n' && c!=EOF){
        append(&result,c);
    }

    printf("result = %s\n",result.str);

    return 0;
}