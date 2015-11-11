//20133277 Seongsil Heo
#include <stdio.h>

int sum(int arr[],int n)
{
	if(n==1) //=(X) ==(0)
		return arr[0];
	else
		return sum(arr, n-1) + arr[n-1];
}

int main()
{
	int a[5] = {3,6,2,5,4};
	printf("%d",sum(a, 5));
}
