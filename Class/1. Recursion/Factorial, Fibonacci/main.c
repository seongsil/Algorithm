//20133277 Seongsil Heo
#include <stdio.h>


int factorial(int n)
{
	if(n==0)
		return 1;
	else
		return n*factorial(n-1);
}

int fib(int n)
{
	if(n <= 1)
		return n;
	else
		return fib(n-1) + fib(n-2);
}
int main()
{
	printf("%d\n" ,factorial(5));
	printf("%d\n", fib(4));
}
