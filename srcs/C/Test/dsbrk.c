#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/mman.h>

int main(void)
{
    void *f = sbrk(0);
    void *s = sbrk(4096);
    void *t = sbrk(0);

    uint8_t* fn = mmap(NULL,4096,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);

    int *ptr = (int*)(t) - 1;
    *ptr = 0xDEAD;

    printf("%p\n%p\n%p\n%p\n",f,s,t,fn);

    return 0;
}