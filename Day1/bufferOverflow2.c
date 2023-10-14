#include <stdio.h>

void get_some_invalidated_input()
{
    char new_password[12];
    printf("Your new password: ");
    scanf("%s", new_password);
    //injected code begins
    char* ip = new_password + 28;
    (*ip) += 8;
    //injected code ends
    printf("Ok, your new password is: %s. Exiting the function.\n", new_password);
}

int main()
{
    int x;
    x = 0;
    get_some_invalidated_input();
    x = 1; //this line of code will be ignored
    printf("x=%d\n", x);
    getchar();
    getchar();
}

