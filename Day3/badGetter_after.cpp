#include <iostream>
using namespace std;

class Foo
{
    private:
        unsigned int size = 0;
        int* array = NULL;

    public:
        Foo(int _size, int* _array)
        {
            size = _size;
            array = new int[size];
            for(unsigned i = 0; i < size; i++)
            {
                array[i] = _array[i] + 1;
            }
        }

        int* get_array()
        {
            int* copy = new int[size];
            for(unsigned i = 0; i < size; i++)
            {
                copy[i] = array[i];
            }
            return copy;
            //or use smart pointers
        }

        //...
};

int main()
{
    int v[] = { 1, 2, 3, 4 };
    Foo foo(4, v);

    int* p = foo.get_array();

    //get_array returns a copy
    p[1] = 99;
    //...
    delete[] p;
}

