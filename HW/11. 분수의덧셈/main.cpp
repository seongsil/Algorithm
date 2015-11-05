/********************************************************************************
*                                                                               *
*                             problem - ºÐ¼öÀÇ µ¡¼À                             *
*                                                                               *
********************************************************************************/
/*******************************************************************************
*                                                                              *
*                 Kookmin University  20133277 Seongsil Heo                    *
*                                                                              *
********************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int gcd(int a, int b) {
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main(void)
{
   ifstream inStream;
   int cases;
   int son1, mom1, son2, mom2;   //son: ºÐÀÚ, mom: ºÐ¸ð
   int mom3, son3;

   inStream.open("input.txt");
   if(inStream.fail())
   {
      cerr<<"Input file opening failed./n";
      exit(1);
   }

   inStream>>cases;

   for(int i=0; i<cases; i++)  
   {
      inStream >> son1 >> mom1 >> son2 >> mom2;

	  mom3 = mom1*mom2;
	  son3 = son1*mom2 + son2*mom1;

	  cout << son3/gcd(son3,mom3) << " " << mom3/gcd(son3, mom3) << endl;
   }
}