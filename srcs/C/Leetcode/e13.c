#include <stdio.h>
#include <stdlib.h>

int lengthOfLastWord(char * s)
{
    int i=0,j=0;
    int space=0;
    int word=0;
    int *seq = NULL;
    seq = malloc(sizeof(int));
    while(*(s+j)!='\0'){
        printf("[space=%d word=%d] [%c] \n",space,word,*(s+j));
        if(*(s+j)==' '){
            if(word!=0){
                *(seq+i++)=word;
                seq=realloc(seq,(i+1)*sizeof(int));
                printf("\t[%d]\n",*(seq+i-1));
                word=0;
            }
            space++;
        }
        else{
            word++;
        }
        j++;
    }
    if(j>0 && *(s+(j-1))!=' '){
        *(seq+i)=word;
        printf("\t\t[%d]\n",*(seq+i));
        return word;
    }

    if(j>0 && *(s+(j-1))==' ' && i>0){
        return *(seq+(--i));
    }

    if(j==0 || (i<=1 && space!=0)){
        printf("r1\n");
        return 0;
    }

    printf("r2\n");
    return *(seq+(--i));
}

int main(void)
{
    char* s = " ";

    printf("%d\n",lengthOfLastWord(s));

    return 0;
}