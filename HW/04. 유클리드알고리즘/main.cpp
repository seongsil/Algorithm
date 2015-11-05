/********************************************************************************
*                                                                               *
*                        problem - Euclid's Algorithm                           *
*                                                                               *
********************************************************************************/
/*******************************************************************************
*                                                                              *
*                 Kookmin University  20133277 Seongsil Heo                    *
*                                                                              *
********************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
int gcd(int a,int b);

int main(void)
{
	ifstream inStream;
        int cases;
	int value1;
	int value2;

        inStream.open("input.txt");
        if(inStream.fail())
        {
        cerr<<"Input file opening failed./n";
        exit(1);
        }

        inStream >> cases;
   for(int i=0; i<cases; i++)
   {
	inStream >> value1 >> value2;
	cout << gcd(value1, value2) << endl;
   }
}

int gcd(int a, int b)
{ 
	if(b==0)
	return a;
	else
	return gcd(b,a%b);
}