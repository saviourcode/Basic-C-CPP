#include "strobj.h"

void append(string* p,char c)
{
    if(p->str==NULL){
        p->str = malloc((p->size+2)*sizeof(char));
        add_shadowEntry(p);
    }
    else{
        p->str = realloc(p->str,(p->size+2)*sizeof(char));
    }

    *(p->str+p->size) = c;
    *(p->str+p->size+1) = '\0';
    p->size++;

    printf("p = %s %p %d\n",p->str,p->str,p->size);
    //printf("shadowTable = %s %p %d\n",shadowTable[unqID-1]->str,shadowTable[unqID-1]->str,shadowTable[unqID-1]->size);
}

void appendStr(string* p,char* s)
{
    while(*(s)!='\0'){
        append(p,*(s));
        s++;
    }
}

void scanStr(string* p)
{
    char c;
    while((c=getchar())!='\n' && c!=EOF){
        append(p,c);
    }
}