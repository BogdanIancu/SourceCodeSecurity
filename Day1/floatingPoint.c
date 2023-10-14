#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    float f = 8.4;

    //will be evaluated to false
    if(f == 8.4)
    {
        printf("Egual");
    }
    else
    {
        printf("Not equal!");
    }

    //that's how we should compare
    //two floating point numbers
    if (fabs(f - 8.4) < 0.01)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
    getchar();
}


