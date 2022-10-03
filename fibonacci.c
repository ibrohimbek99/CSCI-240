#include <stdio.h>
#include <stdlib.h>
int Fib(int n);

void main()
{
    printf("%d\n", Fib(7));
    return;
}
int Fib(int n) 
{
	/*
	Series: 1, 1, 2, 3, 5
	*/
	if (n <= 2) 
		return 1;
	else
		return (Fib (n-1) + Fib(n-2));
		
		
	/*
	Series: 0, 1, 1, 2, 3, 5
	if (n == 1) 
		return 0;
	else if (n == 2)
		return 1;
	else
		return (Fib (n-1) + Fib(n-2));
		*/
}

