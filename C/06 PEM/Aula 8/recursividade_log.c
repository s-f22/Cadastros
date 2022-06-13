#include <stdio.h>
/*

*/

int logaritmo(int n, int b)
{   
	if (n < b) return 0;
		else return logaritmo(n / b, b) + 1;
}
int main()
{
    printf("log de 1024 na base 2 = %d\n", logaritmo(1024, 2));
    return 0;
}




