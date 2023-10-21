#include <iostream>
using namespace std;

class A
{
public:
    virtual void print_value(int x = 1) { cout << "A: " << x << endl; }
};

class B : public A
{
public:
    void print_value(int x = 2) override { cout << "B: " << x << endl; }
};

int main()
{
    B* b = new B();
    A* a = b;
    a->print_value();
    b->print_value();

    getchar();
}