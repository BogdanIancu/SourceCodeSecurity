#include <iostream>
using namespace std;

//A is part of a libaray
//and its code cannot be changed
class A
{
    public:
        int x = 99;
};

class B
{
    private:
        bool some_boolean = false;
        int y = 10;
    //the + operator which adds As and Bs
    //should be declared either in A
    //either as a friend method
    //if A's code cannot be modified
    friend int operator+ (A& a, B& b);

    public:
        bool get_some_boolean()
        {
            return some_boolean;
        }
};

//passing by reference is common in C++
//to avoid additional copy constructor calls
int operator+(A& a, B& b)
{
    //the friend method can access all the private fields
    b.some_boolean = true;
    return a.x + b.y;
}

int main()
{
    A a; B b;
    cout << "intial value: " <<  b.get_some_boolean() << endl;
    cout << a + b << endl;
    cout << "modified value: " <<  b.get_some_boolean() << endl;
}

