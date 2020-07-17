/* ID: 28. Implement strStr()
 * Problem Statement: Implement strStr().
 *                    Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 *                    Example: 
 *                            Input: haystack = "hello", needle = "ll"
 *                            Output: 2, if not found then -1, if needle is NULL then return 0
 * Solution: Compare character by character using nested loop, start the loop only when the first character is matched.
 */
#include <stdio.h>

int strStr(char * haystack, char * needle){
    if(*(needle)=='\0'){
        return 0;
    }

    int haystacklen=0;
    int needlelen=0;

    for(int i=0;*(haystack+i)!='\0';i++){
        haystacklen++;
    }

    for(int i=0;*(needle+i)!='\0';i++){
        needlelen++;
    }
    
    int index=-1;

    for(int i=0;i<=haystacklen-needlelen;i++){
        if(*(haystack+i)==*(needle)){
            index=i;
            for(int j=0;j<needlelen;j++){
                if(*(needle+j)!=*(haystack+i+j)){
                    index=-1;
                    break;
                }
            }
            if(index==i){
                return index;
            }
        }
    }

    return index;
}

int main(void)
{
    int index;
    index = strStr("hello","o");
    printf("%d\n",index);
    return 0;
}