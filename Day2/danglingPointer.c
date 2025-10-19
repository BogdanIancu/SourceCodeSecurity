#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* v = (int*)malloc(24);
    v[0] = 1, v[1] = 2, v[2] = 3, v[3] = 4, v[4] = 5, v[5] = 6;
    printf("%p %d %d %d %d %d %d \n", v, v[0], v[1], v[2], v[3], v[4], v[5]);
    free(v);
    v = NULL;
    //printf("%p %d %d %d %d %d %d \n", v, v[0], v[1], v[2], v[3], v[4], v[5]);
    printf("%p \n", v);
    getchar();
}