#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
//()()()))((

void find_vps(char arr[50], int& index, int& num);
int main(void)
{
   ifstream inStream;
   int cases;
   char ps[50];

   inStream.open("input.txt");
   if(inStream.fail())
   {
      cerr<<"Input file opening failed./n";
      exit(1);
   }

   inStream>>cases;
   for(int i=0; i<cases; i++)
   {
	int num(0), index(0);
	   inStream >> ps;
	   find_vps(ps,index,num);
   }
}

void find_vps(char arr[50], int& index, int& num)
{

	if(arr[index] == '\0') {

	if(num == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	}

	if(arr[index] == '(') {
		num++; index++;
		find_vps(arr, index,num);
		}
	else if(arr[index] == ')') {
		if(num == 0) {
			cout << "NO" << endl; }
		else {
		num--; index++;
		find_vps(arr, index,num); }
	}
}
