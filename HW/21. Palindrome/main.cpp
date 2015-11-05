#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int BaseConverse(int n,int base,int a[]);
int CheckPalindrome(int a[], int num);
int a[100];

int main(void)
{
	ifstream inStream;
	int cases;
	int n;

	inStream.open("input.txt");
	if(inStream.fail())
	{
		cerr<<"Input file opening failed.\n";
		exit(1);
	}

	inStream >> cases;

	for(int i=0; i<cases; i++)
	{
		inStream >> n;
		for(int j=2; j<=64; j++)
		{
		int b = BaseConverse(n,j,a);
		if(CheckPalindrome(a,b)) {
			cout << "1"<< endl;
			break; }
		if(j == 64)
			cout << "0" << endl;
		}
	}
}

int BaseConverse(int n, int base, int a[])
{
	int div = n / base;
	int res =  n % base;
    int i=0;
	//char arr[17] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	a[i] = res;

	while(1) {
		if(div == 0)
			break;
		else
		{
			i++;
			res = div % base;
			div = div / base;
			a[i] = res;
		}
	}
	return i;
}

int CheckPalindrome(int a[], int num)
{
	int start = 0;
	int end = num;
	while(start < end)
	{
		if(a[start] != a[end]) {
			return 0;
		}
		start++; end--;
	}
	return 1;
}