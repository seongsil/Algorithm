//20133277 Seongsil Heo
/* ������ȯ����-2
���� �ٸ� ������ ������ �־����� ��, �Ž������� ��ȯ�� �ִ� ������ ������ ���� ����Ͻÿ�. 
��, ��� ������ ������ ������ ���ٰ� �����Ѵ�.
ex) ������ ���� : 1��, 2��, 4��
    �Ž��� �� 4��
	        -��ȯ��� : 4����
			>> {1,1,1,1}, {1,1,2}, {2,2}, {1,3}
*/
/*
N(n,k) : �Ž����� K���� n���� ���� c1,c2,...,cn���� ��ȯ�ϴ� ���� ������ ��
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
	printf("�ּ� ���� ������ �� : %d\n", countCoinExchange(7));
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

	for(i = 1; i < sizeof(coins)/sizeof(int); i++) //coin �ϳ� ����
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