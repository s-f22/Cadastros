/* 
1) a) Qual o valor de y no final do programa?
   b) Escreva um coment�rio  em cada comando de atribui��o explicando o que ele faz e o valor da vari�vel �  esquerda do '=' ap�s sua execu��o.
*/

#include <stdio.h>
int main()
{
int x, y, *p, *q; //x e y s�o var. inteiras; p e q s�o var. ponteiro (end. mem�ria)
y = 19; //y recebe 19
p = &y; //p recebe o endere�o de mem�ria de y
x = *p; // recebe o endere�o de memoria, que aponta para o valor 19, em y
x = 7; //x recebe 7
(*p)++; // � equivalente a fazer x++
x--; // x = 6
(*p) = (*p) + x; //
printf ("y = %d\n", y); //
*q = 10; // IGNORAR ESSA LINHA

return 0;
}

/*
2) Comente o trecho abaixo linha-a-linha e mostre o que ser� impresso pelo comando printf:
*/

int a = 10, b = 7, c; //a recebe 10, b recebe 7, c n�o inicializado
int * p = &a; //p recebe o endere�o de a
int * q = &b; //
int * r = &c; //
*r = *p; //
*p = *q; //
*q = *r; //
printf("%d  -  %d", a, b); //
