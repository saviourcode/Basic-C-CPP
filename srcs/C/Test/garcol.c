#include "garcol.h"

string **shadowTable = NULL;

static int unqID=0;

void mon_allocShadow(void)
{
    if(shadowTable==NULL)
        shadowTable = (string **)malloc(sizeof(string*));
    else
        shadowTable = (string **)realloc(shadowTable,(unqID+1)*sizeof(string*));
}

void mon_freeShadow(void)
{
    for(int i=0;i<unqID;i++){
        printf("Freeing\n");
        free(shadowTable[i]->str);
        shadowTable[i]->str = NULL;
        shadowTable[i]->size = 0;
    }
    free(shadowTable);
    shadowTable = NULL;

    printf("In FreeShadow: %s\n",shadowTable[1]->str);
    printf("Done\n");
}

void add_shadowEntry(string* p)
{
    shadowTable[unqID] = p;
    unqID++;
    mon_allocShadow();
}