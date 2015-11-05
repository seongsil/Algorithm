/********************************************************************************
*                                                                               *
*                             problem - Palindrome                              *
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
int is_pal(int start, int end, char str[]);

int main(void)
{
	ifstream inStream;
	int cases;
	char word[1000];

	inStream.open("input.txt");
	if(inStream.fail())
	{
		cerr<<"Input file opening failed./n";
		exit(1);
	}

	inStream>>cases;
	for(int i=0; i<cases; i++)
	{
		inStream >> word;
		cout << is_pal(0,strlen(word)-1,word) << endl;
	}
}

int is_pal(int start, int end, char str[])
{
	if(start >= end)
		return 1;
	if(str[start] != str[end])
		return 0;
	return is_pal(++start,--end, str);
}
