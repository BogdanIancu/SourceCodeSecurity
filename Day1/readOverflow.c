#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[100];
    unsigned short length = 0;
    do
    {
        printf("Length = ");
        scanf("%d", &length);
        fflush(stdin);
        //The size of the message might be shorter
        printf("Message = ");
        gets(buffer);
        printf("The message is: ");
        //if length > actual size of the message
        //this will display old values of buffer
        for(int i = 0; i < length; i++)
        {
            putchar(buffer[i]);
        }
        printf("\n");
    } while (strcmp(buffer, "exit") != 0);
}

