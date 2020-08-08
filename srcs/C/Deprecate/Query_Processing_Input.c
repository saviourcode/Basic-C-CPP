#include <stdio.h> 
#include <stdlib.h>

void getString(char**); // function prototype

/* Main function */
int main()
{
    /* Pointer to point to the memory location
     * where input string will be stored */
    char *s=NULL;
    /* Call by reference,the function will place 
     * string in memory location where the pointer
     *  is pointing */
    getString(&s); 
    printf("s=%s\n",s);

    free(s);
    return 0;
}

/* getString function will
 * store each input character in
 * the allocated memory area. */
void getString(char** p)
{
    if(*p==NULL){
        if((*p=malloc(1*sizeof(char)))==NULL)
            exit(0);
    }

    int c; //Variable to store each input character
    size_t i=0; //Counter to keep track of the size of the input string

    while((c=getchar())!='\n' && c!=EOF){
        char* newp = realloc(*p,i+1);
        if(newp==NULL){
            fprintf(stderr,"realloc failed\n");
            free(p);
            exit(0);
        }
        *p = newp;
        *(*p+i)=c;
        i++;
    }
    *(*p+i)='\0'; //Null character to end the string.
}