#include <stdio.h>

int decBin(int n)
{
	if(n < 2 )
	{
		printf("%d", n);
	}
	else
	{
		decBin(n/2);
		printf("%d", n%2);
	}
}


int main()
{
	decBin(58);
	return 0;
}


