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
    char* wrong_token = "_any 18 characters";
    int result = login(wrong_token);
    printf("result=%d", result);
    //...
    getchar();
}


