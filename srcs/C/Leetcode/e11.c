#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * countAndSay(int n){
    if(n<=0){
        return "";
    }
    int count=0;
    char *s = NULL,*t=NULL;
    s = malloc(2*sizeof(char));
    t = malloc(2*sizeof(char));
    
    *t='1';
    *(t+1)='\0';
    *s='1';
    *(s+1)='\0';

    for(int i=1;i<n;i++){
        int j=0;
        int d=0;
        char temp=*s;
        do{
            if(temp==*(s+j)){
                count++;
            }
            else if(temp!=*(s+j) && *(s+j)=='\0'){
                t=realloc(t,(d+3)*sizeof(char));
                *(t+d)=count+'0'; //Most Basic rule to store int into the char variable.
                *(t+d+1)=temp;
                *(t+d+2)='\0';
                count=0;
                temp=*(s+j);
                d=d+2;
            }
            else if(temp!=*(s+j) && *(s+j)!='\0'){
                t=realloc(t,(d+3)*sizeof(char));
                *(t+d)=count+'0'; //Most Basic rule to store int into the char variable.
                *(t+d+1)=temp;
                *(t+d+2)='\0';
                count=0;
                temp=*(s+j);
                d=d+2;
                j--;
            }
        }while(*(s+j++)!='\0');
        s=realloc(s,(d+1)*sizeof(char));
        memcpy(s,t,(d+1)*sizeof(char));
    }

    return s;
    int x=1;
    x++;

}

int main(void)
{
    char *p = NULL;

    p=countAndSay(30);

    printf("%s\n",p);

    return 0;
    
}