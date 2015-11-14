//20133277 Seongsil Heo
/* 동전교환문제-2
서로 다른 단위의 동전이 주어졌을 때, 거스름돈을 교환해 주는 동전의 조합의 수를 계산하시오. 
단, 모든 단위의 동전은 무수히 많다고 가정한다.
ex) 동전의 종류 : 1원, 2원, 4원
    거스름 돈 4원
	        -교환방법 : 4가지
			>> {1,1,1,1}, {1,1,2}, {2,2}, {1,3}
*/
/*
N(n,k) : 거스름돈 K원을 n개의 동전 c1,c2,...,cn으로 교환하는 동전 조합의 수
          0                         n = 0 and K > 0 (base case)
N(n,K) =  1                         K = 0 (base case)
          0                         K < 0 (base case)
		  N(n-1,K) + N(n, k-cn)     otherwise (recursive step)
*/

#include <stdio.h>

#define MAX_COINS 101
#define MAX_CHANGE 1001

int coins[4] = {1,2,3,5};
int countCoinExchange(int change);

int main(void)
{
	int change = 7;
	printf("최소 동전 조합의 수 : %d\n", countCoinExchange(7));
}

int countCoinExchange(int change)
{
	int i, j, numComb;
	int N[MAX_COINS][MAX_CHANGE] = {0};

	// base cases
	for(i = 0; i < change; i++)
		N[0][i] = 0;
	for(i = 0; i < sizeof(coins)/sizeof(int); i++)
		N[i][0] = 1;

	for(i = 1; i < sizeof(coins)/sizeof(int); i++) //coin 하나 선택
		for(j = 1; j <= change; j++)
		{
			if( j - coins[i] < 0) // base cases;
				numComb = 0;
			else
				numComb = N[i][j-coins[i]];

			N[i][j] = N[i-1][j] + numComb;
		}
		return N[sizeof(coins)/sizeof(int)][change];
}