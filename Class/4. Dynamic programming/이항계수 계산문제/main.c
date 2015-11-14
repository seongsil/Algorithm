//20133277 Seongsil Heo
/* 이항계수 계산문제
B[n][k] = 1                           k = 0 or k = n (base case)
          B[n-1][k-1] + B[n-1][k]     0 < k < n <recursive step)
*/

#include <stdio.h>

#define MAX 30

int binCoeff(int n, int k);

int main(void)
{
	printf("%d\n", binCoeff(6,3));
}

int binCoeff(int n, int k)
{
	int i, j;
	int B[MAX][MAX];

	if(n < k) 
		return 0;

	for(i = 0; i <= n; i++)
		for(j = 0; j <= k; j++)
			if( j == 0 || j == i)
				B[i][j] = 1; //base case
			else
				B[i][j] = B[i-1][j-1] + B[i-1][j];
	return B[n][k];
}