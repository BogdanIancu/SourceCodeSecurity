void primes(int cap) 
{  
	int i, j, composite;  
	for(i = 2; i < cap; i++) 
	{   composite = 0;    
		for(j = 2; j < i; j++)  
				composite += !(i % j);   
 		if(!composite) printf("%d\t", i);  
	}
}
int main() {   primes(100); getchar(); }

