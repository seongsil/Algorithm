//20133277 Seongsil Heo
#include <stdio.h>

int gcd(int a,int b)
{
	if(b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int main()
{
	printf("%d", gcd(1071,1029));
}
