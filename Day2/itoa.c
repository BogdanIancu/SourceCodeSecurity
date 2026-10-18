#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char number[3];
    unsigned int test = 0;
    int x = 12345678;
    itoa(x, number, 10);
    // you can do this instead
    //snprintf(number, sizeof(number), "%d", x);
    printf("number = %s\n", number);
    printf("test = %d\n", test);

    getchar();
}