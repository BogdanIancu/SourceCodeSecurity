#include <stdio.h>
#include <string.h>

int safe_copy(char* str, int size)
 {
    char buf[80];
    if(size < sizeof(buf))
    {
        strcpy(buf, str); 
        return size;
    }
	else return 0;
 }

 int main()
 {
     int result = safe_copy("something", -2);
     printf("\n%s", result ? "Copied successfuly" : "Not copied!");
     getchar();
 }
