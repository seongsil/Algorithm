//20133277 Seongsil Heo
#include <stdio.h>

int countUp(int nCount)
{
	if(nCount > 0)
		countUp(nCount -1);
	printf("%d ", nCount);
}

int countDown(int nCount)
{
	printf("%d ", nCount);

	if(nCount > 0)
		countDown(nCount -1);
}

int main()
{
	countUp(4);
	countDown(4);
}
