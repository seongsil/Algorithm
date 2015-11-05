/********************************************************************************
*                                                                               *
*                             problem - Fibonacci                               *
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

int fib(int x);

int main(void)
{
	ifstream inStream;
	int cases;
	int value;

	inStream.open("input.txt");
	if(inStream.fail())
	{
		cerr<<"Input file opening failed./n";
		exit(1);
	}

	inStream >> cases;
	for(int i=0; i<cases; i++)
	{
		inStream >> value;
		cout << fib(value) << endl;
	}
}

int fib(int x)
{
	if(x==1 || x == 0)
		return x;

	else
		return fib(x-1)+fib(x-2);
}

//�迭 ����� �Ǻ���ġ ���� �����س����� �ð��� ������ �� �ִ�.