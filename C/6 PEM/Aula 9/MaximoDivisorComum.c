#include <stdio.h>

int mdc(int a, int b)
{
	if(a % b == 0) return b;
	else return mdc(b, a % b);
}


int main()
{
	printf("mdc(77, 56) = %d\n", mdc(77,56));
	printf("mdc(24, 36) = %d\n", mdc(24,36));
	printf("mdc(18, 66) = %d\n", mdc(18,60));
	
	return 0;
}
