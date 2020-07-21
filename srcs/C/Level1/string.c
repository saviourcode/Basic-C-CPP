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

void appendStr(string* p,char* s)
{
    while(*(s)!='\0'){
        append(p,*(s));
        s++;
    }
}

void scanStr(string* p){
    char c;
    while((c=getchar())!='\n' && c!=EOF){
        append(p,c);
    }
}

int main(void)
{
    string result = BLANK;
    printf("Enter the name: ");
    // Scan the input from the User.
    //scanStr(&result);
    appendStr(&result,"Hello");
    append(&result,66);

    printf("result = %s size=%d\n",result.str,result.size);

    return 0;
}