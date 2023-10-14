#include <stdio.h>
#include <string.h>

int login(const char* token)
{
    char local_buffer[17];
    int is_authenticated = 0;
    strcpy(local_buffer, token);
    //...
    return is_authenticated;
}

int main()
{
    //...
    char* correct_token = "1234567891234567";
    int result = login(correct_token);
    printf("result=%d", result);
    //...
    getchar();
}


