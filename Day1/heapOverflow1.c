#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFSIZE 16
#define OVERSIZE 5
    
int main()
{
    unsigned long diff;
    char* buf1 = (char*)malloc(BUFFSIZE);
    char* buf2 = (char*)malloc(BUFFSIZE);
    diff = (unsigned long)buf2 - (unsigned long)buf1;
    printf("buf1 = %p, buf2 = %p, diff = %x bytes\n", buf1, buf2, diff);
    memset(buf2, 'A', BUFFSIZE-1);
    buf2[BUFFSIZE-1] = '\0';
    printf("before overflow: buf2 = %s\n", buf2);
    memset(buf1, 'B', (unsigned int)(diff + OVERSIZE));
    printf("after overflow: buf2 = %s\n", buf2);
    getchar();
}


