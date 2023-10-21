#include <iostream>
using namespace std;

class srs;

class dst 
{ 
    public: 
        int x;  

        dst()
        {

        }

        dst(const srs& s)
        {
            x = 5;
        }   
};

class srs
{ 
	private: 
        int x;
	public: 
		srs(int a):x(a){}
		operator dst() { dst d; d.x=x; return d; }
}; 



int main()
{
    srs s(1); 
    dst d=(dst)s;
    //we just gave access to private data
    cout << d.x;
    cin.get();
}

