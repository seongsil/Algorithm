/********************************************************************************
*                                                                               *
*                                problem-Henry                                  *
*                                                                               *
********************************************************************************/
/*******************************************************************************
*                                                                              *
*         Kookmin university computer science 20133277 Seongsil Heo            *
*                                                                              *
********************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int gcd(int a, int b) {
	if( b == 0)
		return a;
	else
		return gcd(b, a%b);
}

void henry(int son, int mom) {;
	int a,g;
	if(son <= 1) 
		cout << mom << endl;
	else {
		a = mom/son;
		son = son*(a+1) -mom;
		mom = mom*(a+1);
		
		g = gcd(son, mom);
		henry(son/g , mom/g);
	}
}

int main(void)
{
   ifstream inStream;
   int cases;
   int son; int mom;

   inStream.open("input.txt");
   if(inStream.fail())
   {
      cerr<<"Input file opening failed./n";
      exit(1);
   }

   inStream >> cases;
   for(int i=0; i<cases; i++)
   {
	   inStream >> son >> mom;
	   henry(son, mom);
   }
}