/* ID: 20. Valid Parentheses
 * Problem Statement: Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *                      An input string is valid if:
 *                          Open brackets must be closed by the same type of brackets.
 *                          Open brackets must be closed in the correct order.
 *                          Note that an empty string is also considered valid.
 * Solution: I have used Stack Data Structure to solve this problem, 
 *              Push into stack when it encounters any open brackets
 *              Pop from stack when it encounters any closing brackets
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//Refactoring for Heap Memory required
// char *p = NULL;
char p[1000];
int stkptr=-1;
void reset(void){
    // p=NULL;
    stkptr=-1;
}
void stackpush(char c){
    stkptr++;
    // if(p==NULL){
    //     p=(char *)calloc(1,sizeof(char));
    //     if (!p) {
    //         fprintf(stderr,"mem failure, exiting \n");
    //         exit(EXIT_FAILURE);
    //     }
    // }
    *(p+stkptr)=c;
    // p=realloc(p,sizeof(char)*(stkptr+2));
}

int stackpop(char c){

    if(stkptr<0){
        return 1;
    }

    char openc;

    if(c==')')
        openc='(';
    else if(c=='}')
        openc='{';
    else if(c==']')
        openc='[';

    if(*(p+stkptr)==openc){
        stkptr--;
        // if(stkptr>0)
        //     p=realloc(p,sizeof(char)*(stkptr+1));
        return 0;
    }
    else
        return 1;
}

bool isValid(char *s)
{
    int popchecker=0;
    for(int i=0;*(s+i)!='\0';i++){
        if((*(s+i)=='(') || (*(s+i)=='[') || (*(s+i)=='{')){
            stackpush(*(s+i));
        }
        else if((*(s+i)==')') || (*(s+i)==']') || (*(s+i)=='}')){
            popchecker=stackpop(*(s+i));
            if(popchecker==1)
                return false;
        }
    }

    for(int i=0;i<=stkptr;i++){
        printf("%c ",*(p+i));
    }
    printf("\n");

    if(stkptr>=0){
        reset();
        return false;
    }

    reset();
    return true;
}

int main(void)
{
    bool a;
    a=isValid("[({(())}[()])]");
    printf("%d\n",a);
    return 0;
}