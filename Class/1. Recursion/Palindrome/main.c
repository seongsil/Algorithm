//20133277 Seongsil Heo
#include <stdio.h>
#include <string.h>

//1 return ÇÏ¸é palindrome
int checkPalindrome(char str[],int first, int last)
{
	if(first >= last)
		return 1;

	if(str[first] == str[last])
		return checkPalindrome(str,first+1, last-1);
	else
		return 0;
}

int main()
{
	char line[256] = "malayalam";
	printf("%d \n", checkPalindrome(line, 0, strlen(line)-1));
}
