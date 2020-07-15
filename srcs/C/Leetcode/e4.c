#include <stdio.h>
#include <stdlib.h>

char * commonTwo(char *str1, char *str2)
{
    char *p = NULL;
    p = calloc(1,sizeof(char));
    *p='\0';
    int size[2] = {0,0};
    
    while(*(str2+size[1])!='\0'){
        size[1]++;
    }

    while(*(str1+size[0])!='\0'){
        size[0]++;
    }

    int compsize = size[0]>=size[1]?size[1]:size[0];

    printf("%s = %d, %s = %d\n",(str1),size[0],(str2),size[1]);
    int j=0;
    for(;j<compsize;j++){
        if(*(str1+j)==*(str2+j)){
            *(p+j) = *(str1+j);
            p = realloc(p,sizeof(char)*(j+2));
        }
        else {
            break;
        }
    }
    *(p+j)='\0';
    
    printf("common=%s\n",p);
    return p;
}

char * longestCommonPrefix(char ** strs, int strsSize){
    char *p = NULL;
    p = *(strs);

    for(int i=0;i<strsSize-1;i++){
        p=commonTwo(p,*(strs+i+1));
    }
    
    return p;
}

int main()
{
    char *strs[] = {"1234567", "12345","1234567","12345","123","1234567","1234","12345678","1234","1","1","123","1",""};
    char *s = NULL;
    s = longestCommonPrefix(strs,14);
    printf("Result=%s\n",s);
    return 0;
}