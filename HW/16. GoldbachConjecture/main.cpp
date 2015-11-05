#include <iostream>
#include <fstream>

using namespace std;

int count;

int checkPrime(int num)
{
	int flag=1; //prime number

	for(int j=2; j*j <= num; j++) //2,3,4에서 나머지0 안되고 5로 처음나머지 0이려면 5*5인경우
	{
		if(num % j == 0)
		{
			flag = 0; //not prime number
		}
	}
	return flag;
}
void goldbach(int num)
{
	//반으로 쪼개서 소수면 출력, ex) 5 + 5
	if((checkPrime(num - count)) == 1 && (checkPrime(num + count)) == 1)
		cout << num - count << " " << num + count<< endl;
	else {
		//소수아니면 다음 숫자 4 + 6으로 넘김
		count++;
		goldbach(num);
	}
}
int main(void)
{
	ifstream inStream;
	int cases;
	int num;

	inStream.open("input.txt");
	if(inStream.fail())
	{
		cerr << "Input file opening failed.\n";
		exit(1);
	}
	
	inStream >> cases;
	for(int i=0; i<cases; i++)
	{
		inStream >> num;
		count = 0;
		goldbach(num/2);
	}

}