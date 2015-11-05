#include <iostream>
#include <fstream>

using namespace std;

int count;

int checkPrime(int num)
{
	int flag=1; //prime number

	for(int j=2; j*j <= num; j++) //2,3,4���� ������0 �ȵǰ� 5�� ó�������� 0�̷��� 5*5�ΰ��
	{
		if(num % j == 0)
		{
			flag = 0; //not prime number
		}
	}
	return flag;
}
void goldbach(int num)
{
	//������ �ɰ��� �Ҽ��� ���, ex) 5 + 5
	if((checkPrime(num - count)) == 1 && (checkPrime(num + count)) == 1)
		cout << num - count << " " << num + count<< endl;
	else {
		//�Ҽ��ƴϸ� ���� ���� 4 + 6���� �ѱ�
		count++;
		goldbach(num);
	}
}
int main(void)
{
	ifstream inStream;
	int cases;
	int num;

	inStream.open("input.txt");
	if(inStream.fail())
	{
		cerr << "Input file opening failed.\n";
		exit(1);
	}
	
	inStream >> cases;
	for(int i=0; i<cases; i++)
	{
		inStream >> num;
		count = 0;
		goldbach(num/2);
	}

}