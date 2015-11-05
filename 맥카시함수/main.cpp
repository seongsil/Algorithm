/********************************************************************************
*                                                                               *
*                             problem - McCarthy                                *
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
int mc(int n);

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
	cout << mc(value) << endl;
   }
}

int mc(int n)
{ 
	if(n>100)
	return n-10;
	else
	return mc(mc(n+11));
}
