#include <stdio.h> //Contains printf and other special characters (\n and EOF) 
#include <stdlib.h> //For Dynamic Memory allocation, malloc, realloc and free

void readline(char**); //readline function prototype

/* Main function */
int main()
{
	/* Pointer to point to the memory location
	 * where input string will be stored */
	char *s=NULL;
	/* Call by reference,the function will place 
	 * string in memory location where the pointer
	 *  is pointing */
	readline(&s); 
	printf("s=%s\n",s);
	/* Always free the memory allocated
	 * to prevent memory leak */
	free(s);
	return 0;
}

/* Readline function will
 * store each input character in
 * the allocated memory area. */
void readline(char** p)
{
	/* Create dynamic memory if not allocated already
	 * else use the same memory area and overwrite it */
	if(*p==NULL){
		*p=(char*)malloc(1*sizeof(char));
	}

	char c; //Variable to store each input character
	int i=0; //Counter to keep track of the size of the input string

	/* Read till newline or end-of-file is not reached
	 * whichever occurs first. 
	 * Store the input character into the dynamic memory
	 * Reallocate the memory if the string is greater than it's 
	 * initial size */ 
	while((c=getchar())!='\n' && c!=EOF){
		*p=(char*)realloc(*p,(i+1)*sizeof(char));
		*(*p+i)=c;
		i++;
	}
	*(*p+i)='\0'; //Null character to end the string.
}
