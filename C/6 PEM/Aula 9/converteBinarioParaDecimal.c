#include <stdio.h>

int binDec(int n)
{
	if(n < 2) return n;
	else return 2 * binDec(n / 10) + n % 10;
}


int main()
{
	printf("%d\n", binDec(111010));
	return 0;
}


