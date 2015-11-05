/********************************************************************************
*                                                                               *
*                          problem-Ducci Sequence                               *
*                                                                               *
********************************************************************************/
/*******************************************************************************
*                                                                              *
*          Kookmin university computer science 20133277 Seongsil Heo            *
*                                                                              *
********************************************************************************/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;
void whatTuple(int size, int arr[15]);

int main(void)
{
	ifstream inStream;
	int cases;
	int sizeOfTuple;

	inStream.open("input.txt");
	if(inStream.fail())
	{
		cerr<<"Input file opening failed./n";
		exit(1);
	}

	inStream >> cases;
	for(int i=0; i<cases; i++)
	{
		inStream >> sizeOfTuple;
		int n[15] = {0};
		for(int j=0; j<sizeOfTuple; j++)
		{
			inStream >> n[j];
		}
		whatTuple(sizeOfTuple,n);
	}
}

void whatTuple(int size,int arr[15])
{
	int first_n = arr[0];
	int count_step(0);

	while(1) {
		for(int j=0; j<=size; j++) //make next step
		{
			if(j != (size-1)) 	
				arr[j] = abs(arr[j+1] - arr[j]);
			else
				arr[j] = abs(first_n - arr[j]);
		}

		count_step++;

		int k;
		for(k=0; k<size; k++) //(0,0,0,0) 인지 아닌지 검사
		{
			if(arr[k] != 0)
				break;	
		}

		if(k == size) {  //(0,0,0,0)이면 ZERO
			cout << "ZERO" << endl; 
			break; }
		if(count_step == 1000) {
			cout << "LOOP" << endl;
			break; }
		first_n= arr[0];
	}
}