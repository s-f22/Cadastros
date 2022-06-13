#include <stdio.h>
float expressao(int n)
{   
	if (n == 0)return 1.0;
		else return expressao(n - 1) + 1.0/n;
}
int main()
{
    printf("Expressao(5): %f\n", expressao(5));
    return 0;
}


/*
 
 
 
4) Calcule recursivamente o valor da expressão: expressao(n) = 1/1 + 1/2 + 1/3 + ...+ 1/(n-1) + 1/n
a)  n=1 -> expressao(1) = 1/1
    n=2 -> expressao(2) = 1/1 + 1/2
    n=3 -> expressao(3) = 1/1 + 1/2 + 1/3
    n=4 -> expressao(4) = 1/1 + 1/2 + 1/3 + 1/4
Situação (instância) mais simples: n=1 -> expressao(1) = 1.0
b) expressao(n) = 1/1 + 1/2 + 1/3 + 1/4 + 1/5 + 1/6 + ...+ 1/(n-1) + 1/n
A um pouco mais simples: expressao(n-1) = 1/1 + 1/2 + 1/3 + 1/4 + 1/5 + 1/6 + ...+ 1/(n-1) 
c) expressao(n) = expressao(n-1) + 1/n

#include <stdio.h>
float expressao(int n)
{   if(n==1) return 1.0;
    else return expressao(n-1) + 1.0/n;
}
int main()
{   printf("expressao(5): %f\n", expressao(5));
    return 0;
}
 
 
*/
