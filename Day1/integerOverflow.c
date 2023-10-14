#include <stdio.h>

#define N 10000

struct test
{
    int a;
    int b;
} t;

int allocate_vector(void** address, unsigned short dimen, unsigned short size)
{
    unsigned short necessary_bytes = dimen * size;
   *address = malloc(necessary_bytes);
    if(address == NULL) return 0;
		       else return 1;
}

int main()
{
    unsigned short bytes_allocated = N * sizeof(t);
    printf("allocated: %u bytes instead of %u !!!", 
			bytes_allocated, 10000*sizeof(t) );
    getchar();
}

