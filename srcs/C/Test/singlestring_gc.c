#include <stdio.h>
#include <stdlib.h>
#define BLANK {NULL,0}

void mon_allocShadow(void) __attribute__((constructor));
void mon_freeShadow(void) __attribute__((destructor));

typedef struct string {
     char* str;
     size_t size;
}string;

#define String static string

string **shadowTable = NULL;

static size_t unqID=0;

void append(string*,char);
void appendStr(string*,char*);
void scanStr(string*);
void mon_allocShadow(void);
void mon_freeShadow(void);
void add_shadowEntry(string*);

int main(void)
{
    String a = BLANK;
	String b = BLANK;
	String c = BLANK;
	String d = BLANK;
	String e = BLANK;
	
	appendStr(&a,"Hello, World!");
	appendStr(&b,"Hi");
	appendStr(&c,"Hello, World!");
	appendStr(&d,"Hi");
	appendStr(&e,"a");
	
    return 0;
}

void mon_allocShadow(void)
{
    if(shadowTable==NULL){
		printf("Invoking Garbage Collector for monitoring.\n");
		printf("ShadowTable Created.\n");
        shadowTable = (string **)malloc(sizeof(string*));
	}
    else{
        shadowTable = (string **)realloc(shadowTable,(unqID+1)*sizeof(string*));
	}
}

void mon_freeShadow(void)
{
    for(size_t i=0;i<unqID;i++){
        free(shadowTable[i]->str);
        shadowTable[i]->str = NULL;
        shadowTable[i]->size = 0;
		printf("Freeing Object %ld\n",unqID-i);
    }
    free(shadowTable);
    shadowTable = NULL;
	printf("ShadowTable Deleted.\n");
}

void add_shadowEntry(string* p)
{
	printf("Registering Object.\n");
    shadowTable[unqID] = p;
    unqID++;
	printf("\tObject Registered in ShadowTable! Total Objects: %ld\n",unqID);
    mon_allocShadow();
}

void scanStr(string* p)
{
    char c;
    while((c=getchar())!='\n' && c!=EOF){
        append(p,c);
    }
}

void appendStr(string* p,char* s)
{
	while(*(s)!='\0'){
		append(p,*(s));
		s++;
	}
}

void append(string* p,char c)
{
    if(p->str == NULL){
		p->str = (char *)malloc(2*sizeof(char));
		add_shadowEntry(p);
	}
	else{
		p->str = (char *)realloc(p->str,(p->size+2)*sizeof(char));
	}
	*(p->str+p->size) = c;
	*(p->str+p->size+1) = '\0';
	p->size++;
}