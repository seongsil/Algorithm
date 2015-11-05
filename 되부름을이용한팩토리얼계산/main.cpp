/********************************************************************************
*                                                                               *
*                             problem - Factorial                               *
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
int recursive(int n);

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

	inStream>>cases;
	for(int i=0; i<cases; i++)
	{
		inStream >> value;
		cout << recursive(value) << endl;
	}
}

int recursive(int n)
{
	if(n==0)
		return 1;
	else
		return n*recursive(n-1);
}


