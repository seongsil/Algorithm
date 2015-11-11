#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
	char* tmp;
	tmp = a;
	a = b;
	b= tmp;
}
void permuteString(char *str, int begin, int end)
{
	int i;
	int range = end - begin;

	if(range == 1)
		printf("%s\n", str);
	else
	{
		for(i=0; i<range; i++)
		{
			swap(&str[begin], &str[begin+i]);
			permuteString(str, begin+1, end);
			swap(&str[begin], &str[begin+i]); // recover
		}
	}
}

void permute(char *str)
{
	permuteString(str, 0, strlen(str));
}

int main()
{
	char str[] = "abcd";
	permute(str);
}