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
int fib_result[31] = {0};

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
		fib_result[value] = fib(value);
		cout << fib_result[value] << endl;
	}
}

int fib(int x)
{
	if(x==1 || x == 0)
		return x;

	else
	{
		if(fib_result[x] != 0) {
			return fib_result[x]; }
		else {
			return fib(x-1)+fib(x-2); }
	}
}