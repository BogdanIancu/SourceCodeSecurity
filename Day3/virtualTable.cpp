#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class base
{
private:
    int x;
    float y;
public:
    base()
    {
        x = 2;
        y = 3.5f;
    }
	virtual void f() { cout << "Base function" << endl; }
};

class derived : public base
{
private:
    int a;
    float b;
public:
    derived()
    {
        a = 10;
        b = 11;
    }
	void f() override { cout << "Derived function" << endl; }
};

void hackedFunction()
{
	cout << "Your program has been hacked!" << endl;
}

struct vTable
{
	void (*f)();
};

int main()
{
	base b;
	derived d;
	base* pb = &d;
	pb->f();

	vTable virtualTable;
	virtualTable.f = hackedFunction;
	vTable* virtualTablePtr = &virtualTable;
	memcpy(&d, &virtualTablePtr, sizeof(int));
	pb->f();

    getchar();
}