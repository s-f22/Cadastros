/*


1) Dada a defini��o da fun��o  alg  abaixo,

int alg(int a, int b)
{
   if(b == 0)  return a;
   else return alg(a+1, b-1) + a * b;
}

Que valor a seguinte chamada devolve?

alg ( 1 , 5 )    ?    __________________

RESPOSTA: alg ( 1 , 5 )  === 41 ===

*/

#include<stdio.h>


int alg(int a, int b)
{
   if(b == 0)  return a;
   else return alg(a+1, b-1) + a * b;
}


int main()
{
	printf( "%i", alg (1, 5) );
	
	return 0;
}
