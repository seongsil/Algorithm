/********************************************************************************
*                                                                               *
*                          problem - 방의 크기 구하기                           *
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

int totalRoomNumber(int col, int row,int roomSize[10]);
int floodFill(int i, int j);
int compare(const void *arg1, const void *arg2);

char fig[101][101];
int roomNumber; 
int main(void)
{
   ifstream inStream;
   int cases;
   int row,col;
   int roomSize[100] = {0};

   inStream.open("input.txt");
   if(inStream.fail())
   {
      cerr<<"Input file opening failed./n";
      exit(1);
   }

   inStream>>cases;
   for(int i=0; i<cases; i++)
   {
      inStream >> row >> col;
	  for(int j=0; j< col; j++) 
		  inStream >> fig[j];

	  cout << totalRoomNumber(col, row, roomSize) << endl;
	  qsort(roomSize, roomNumber, sizeof(int), &compare);
	  //base: 정렬할 배열의 첫번째 포인터, nel: 배열의 개수, width: 배열 하나의 크기, (*compar):비교함수
	  
	  for(int i=0; i<roomNumber; i++)
		  cout << roomSize[i] << " ";
	  cout << endl;

   roomNumber = 0;
   for(int i=0; i<100; i++)
   {roomSize[i] = NULL; }

   }
}

int floodFill(int i, int j)
{
		if(fig[i][j] != '.') 
			return 0; 
		else{
			fig[i][j] = roomNumber;
			return 1 + floodFill(i-1, j) + floodFill(i+1, j)
				+ floodFill(i, j-1) + floodFill(i, j+1);
	}
}
int totalRoomNumber(int col, int row, int roomSize[10])
{
	for(int i=1; i<col; i++)
		for(int j=1; j<row; j++)
		{
			if(i==(col-1) && j==(row-1))
				return roomNumber;
			if(fig[i][j] == '.') {
				roomSize[roomNumber++]=floodFill(i, j);
				}
		}
}

int  compare(const void *arg1, const void *arg2)
{
	return *(int*)arg2 - *(int*)arg1;
}
