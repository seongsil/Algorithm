/* ������ ���� ���� ������ �������� �־��� ���� �� �Ž������� ���� ���� ���� ��������
��ȯ ���ַ��� ��� �ָ� �Ǵ°�?
���� ����: 50��, 12��, 5��, 1��
�Ž����� �ݾ�: 15��
*/

#include <stdio.h>

int coins[5] = {1,5,10,21,25}; //��������
int coinsUsed[5]; //�Ž��������� ���� ���� ���� ������ ����
int lastCoin[5]; //�������� ���� ����

void coinExchange(int change);
void printResult(int change);

int main(void)
{
	int change = 12; //�Ž����� 21���� ����� ����.
	coinExchange(change);
	printResult(change);

}

void coinExchange(int change)
{
	int cents;
    //"Bottom up" ����� �� ���̹Ƿ� �Ž����� 21���� ���ϱ� ���� 1������ ���ʴ�� �� ���ϱ�
	for(cents = 1; cents <= change; cents++) 
	{
		int minCoins = cents; int newCoin = 1;
		int j;
		for(j = 0; j < sizeof(coins) / sizeof(int); j++)
		{
			if(coins[j] > cents)
				continue;
			//min(C[k-25=],C[k-21],C[k-10],C[k-3],C[k-1]) + 1 ��
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
		printf("�ּҵ����� ���� : %d\n", coinsUsed[change]);
		printf("�ּҰ����� ���õ� ���� : %d\n", lastCoin[change]);
	}
}