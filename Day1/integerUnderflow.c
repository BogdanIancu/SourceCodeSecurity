#include <stdio.h>
#include <stdlib.h>

int allocate(void** address, unsigned short size)
{
    size -=2; // we want to save 2B
    *address = malloc(size);
    if(*address == NULL) return 0;
					else return size;
}

int main()
{
    char* pointer; 
    unsigned nb_of_bytes = 1;
    unsigned int allocated_bytes = 
        allocate((void**)&pointer, nb_of_bytes );
    printf("allocated bytes=%d", allocated_bytes);

    getchar();
}

