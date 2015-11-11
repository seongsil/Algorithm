/* 다음과 같이 여러 단위의 동전들이 주어져 있을 때 거스름돈을 가장 적은 수의 동전으로
교환 해주려면 어떻게 주면 되는가?
동전 단위: 50원, 12원, 5원, 1원
거스름돈 금액: 15원
*/

#include <stdio.h>

int coins[5] = {1,5,10,21,25}; //단위동전
int coinsUsed[5]; //거스름돈에서 가장 적은 수의 동전의 갯수
int lastCoin[5]; //마지막에 사용된 동전

void coinExchange(int change);
void printResult(int change);

int main(void)
{
	int change = 12; //거스름돈 21원을 만들어 보자.
	coinExchange(change);
	printResult(change);

}

void coinExchange(int change)
{
	int cents;
    //"Bottom up" 방식을 쓸 것이므로 거스름돈 21원을 구하기 위해 1원부터 차례대로 값 구하기
	for(cents = 1; cents <= change; cents++) 
	{
		int minCoins = cents; int newCoin = 1;
		int j;
		for(j = 0; j < sizeof(coins) / sizeof(int); j++)
		{
			if(coins[j] > cents)
				continue;
			//min(C[k-25=],C[k-21],C[k-10],C[k-3],C[k-1]) + 1 패
			if(coinsUsed[cents-coins[j]] + 1 < minCoins) 
			{
				minCoins = coinsUsed[cents-coins[j]] + 1;
				newCoin = coins[j];
			}
		}
		coinsUsed[cents] = minCoins;
		lastCoin[cents] = newCoin;
	}
}

void printResult(int change)
{
	if(change > 0)
	{
		printf("최소동전의 개수 : %d\n", coinsUsed[change]);
		printf("최소값으로 선택된 동전 : %d\n", lastCoin[change]);
	}
}