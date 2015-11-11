#include <stdio.h>

//p(x,n) -= x^n
double p(int how_many, double n)
{
	if(how_many == 0)
		return 1.0;
	else
		return p(how_many-1,n) * n;
}

double fast_p(int how_many, double n)
{
	double y; 
	if(how_many == 0)
		return 1.0;
	else if(how_many % 2 == 0) {
		y = fast_p(how_many/2,n);
		return y*y;
	}
	else
		y = fast_p((how_many-1)/2, n);
		return n*y*y;
}

int main()
{
	printf("%f\n", p(2,5.0));
	printf("%f\n", fast_p(2,5.0));
}