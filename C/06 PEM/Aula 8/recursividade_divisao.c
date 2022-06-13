#include <stdio.h>
/*

*/

int divisao(int a, int b)
{   
	if (a < b) return 0;
		else return divisao(a - b, b) + 1;
}
int main()
{
    printf("divisao de 23 por 4 = %i\n", divisao(23, 4));
    return 0;
}



/*
int divisao(int a, int b)
{   if(a<b) return 0;
    else return divisao(a-b, b) + 1;
}
int main()
{   printf("divisao de 23 por 4 = %d\n", divisao(23, 4));
    return 0;
}
*/
