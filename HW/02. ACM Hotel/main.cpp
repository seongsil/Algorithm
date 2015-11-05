/********************************************************************************
*                                                                               *
*                             problem - ACM hotel                               *
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

int main(void)
{
   ifstream inStream;
   int cases;
   int length=0;
   int width=0; 
   int rankOfCustomer=0;

   inStream.open("input.txt");
   if(inStream.fail())
   {
      cerr<<"Input file opening failed./n";
      exit(1);
   }

   inStream>>cases;

   for(int i=0; i<cases; i++)
   {
      inStream>> width >> length >> rankOfCustomer;
	  cout << (width-1)%length + 1;
	  if((width-1)/length+1<10)
		  cout << "0" << width-1/length+1;
	  else
		  cout << width-1/length+1;
   }
}