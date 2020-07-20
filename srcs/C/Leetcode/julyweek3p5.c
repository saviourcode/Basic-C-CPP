#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char* bin(long int n)
{
    char* p = NULL;
    p = malloc(1*sizeof(char));
    *p='\0';
    int j=0;
    unsigned int i = UINT32_C(1) << sizeof(int)*8 - 1;
    for(;i>0;i=i>>1){
        if(n & i)
            break;
    }
    for(; i>0; i=i>>1,j++){
        if(n & i){
            *(p+j)='1';
        }
        else
            *(p+j)='0';
        p=realloc(p,(j+2)*sizeof(char));
    }
    *(p+j)='\0';

    return p;
}

char * addBinary(char * a, char * b)
{
    char* s=NULL;
    unsigned int** num1 = NULL;
    *num1 = malloc(33*sizeof(char));
    for(int i=0;)


    //unsigned long long int num1 = strtol(a,NULL,2);
    //unsigned long long int num2 = strtol(b,NULL,2);

    //printf("%lld\n",num1);
    //printf("%lld\n",num2);

    //s=bin(num1+num2);
    // if(*s=='\0')
    //     return "0";
    return s;
}

int main(void)
{
    printf("%ld\n",sizeof(unsigned int));
    printf("%s\n",addBinary("10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101","110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011"));

    return 0;
}