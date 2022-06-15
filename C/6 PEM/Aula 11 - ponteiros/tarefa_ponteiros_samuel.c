/* 
1) a) Qual o valor de y no final do programa?
   b) Escreva um comentário  em cada comando de atribuição explicando o que ele faz e o valor da variável à  esquerda do '=' após sua execução.
*/

#include <stdio.h>
int main()
{
int x, y, *p, *q; //x e y são var. inteiras; p e q são var. ponteiro (end. memória)
y = 19; //y recebe 19
p = &y; //p recebe o endereço de memória de y
x = *p; // recebe o endereço de memoria, que aponta para o valor 19, em y
x = 7; //x recebe 7
(*p)++; // é equivalente a fazer x++
x--; // x = 6
(*p) = (*p) + x; //
printf ("y = %d\n", y); //
*q = 10; // IGNORAR ESSA LINHA

return 0;
}

/*
2) Comente o trecho abaixo linha-a-linha e mostre o que será impresso pelo comando printf:
*/

int a = 10, b = 7, c; //a recebe 10, b recebe 7, c não inicializado
int * p = &a; //p recebe o endereço de a
int * q = &b; //
int * r = &c; //
*r = *p; //
*p = *q; //
*q = *r; //
printf("%d  -  %d", a, b); //
