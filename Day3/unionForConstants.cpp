#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class A
{
public:
    const int x = 99;
};

class AA
{
public:
    int x = 0;
};

union x_modifier
{
    A a;
    AA aa;

    x_modifier() { memset(this, 0, sizeof(x_modifier)); }
};

int main()
{
    x_modifier modifier;
    modifier.aa.x = 70;
    cout << modifier.a.x;
    getchar();
}