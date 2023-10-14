#include <stdio.h>
#include <string.h>

struct custom_user
{
    char username[10];
    char password[10];
    int (*login_function)();
} user;

int f1()
{		
    printf("\nRight function!");
    if(strcmp("admin", user.username) == 0 &&
        strcmp("admin", user.password)== 0)
        {
            return 1;
        }	   
        else
        {
            return 0;
        }        
}

int f2()
{		
    printf("\nHacked function!!!");
    return 1;
}

int main()
{
    strcpy(user.username, "admin1");
    strcpy(user.password, "admin1");
    user.login_function = f1;

    // //strcpy(user.password, "some special selected string");
    //will be equivalent to
    // long* address = &user.login_function;
    // (*address) = f2;

    if(user.login_function())
    {
        printf("\nLogin successful!");
    }
    else
    {
        printf("\nBad credentials!");
    }
    getchar();
}

