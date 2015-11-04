/********************************************************************************
*                                                                               *
*                          problem - prime number                               *
*                                                                               *
********************************************************************************/
/*******************************************************************************
*                                                                              *
*                 Kookmin University  20133277 Seongsil Heo                    *
*                                                                              *
********************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;
int prime(int num);

int main()
{
	ifstream inStream;
	int cases;
	int num;
	inStream.open("input.txt");
	if(inStream.fail())
	{
		cerr << "Input file Opening failed\n";
		exit(1);
	}

	inStream >> cases;
	for(int i=0; i<cases; i++)
	{
		inStream >> num;
		cout << prime(num) << endl;
	}
}

int prime(int num)
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