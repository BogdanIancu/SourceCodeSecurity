#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char number[3];
    unsigned int test = 0;
    int x = 12345678;
    itoa(x, number, 10);
    printf("number = %s\n", number);
    printf("test = %d\n", test);

    getchar();
}


