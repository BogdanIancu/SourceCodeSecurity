#include <stdio.h>

void f(int x)
{ 
    for (int i=0; i<10; ++i) 
		printf("  %d ",*((int*)x+i));
}

int main()
{
	int a=1,b,c;
	a=(b=2, c=3, a<0) ? (b-=1, b-1) : (c-=2, c+2);
	printf("%d %d %d", a, b, c);
	// forging a pointer
	int vect[]={0,1,2,3,4,5,6,7,8,9};
	int i= (int)(vect);
	f(i);
	getchar();
}

