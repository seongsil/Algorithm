/********************************************************************************
*                                                                               *
*                                문제-소수                                      *
*                                                                               *
********************************************************************************/
/*******************************************************************************
*                                                                              *
*          국민대학교 전자정보통신대학 컴퓨터공학부 20133277 허성실            *
*                                                                              *
********************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int eureka(int num);
int main(void)
{
	ifstream inStream;
	int cases, num;
	inStream.open("input.txt");
	if(inStream.fail())
	{
		cerr<<"Input file opening failed./n";
		exit(1);
	}

	inStream>>cases;
	for(int i=0; i<cases; i++)
	{
		inStream>> num;

		cout << eureka(num) << endl;
	}
}

int eureka(int num)
{
	int n= 1; int eureka = 0;
	int sum1(0), sum2(0), sum3(0);
	while( (n*(n+1)/2) <= num) {
		n++;
	}

	for(int a=1; a<=n; a++) {
		sum1 = (a*(a+1))/2;

		for(int b=1; b<=n; b++) {
			sum2 = (b*(b+1))/2;

			for(int c=1; c<=n; c++) {
				sum3 = (c*(c+1))/2;
				if(sum1+sum2+sum3 == num) {
					eureka = 1;
					break; }
			}
		}
	}
	return eureka;
}