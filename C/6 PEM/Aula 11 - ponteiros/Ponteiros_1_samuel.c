/*
1) a) Qual o valor de y no final do programa?

==>   O valor final de y � 26.

   b) Escreva um "coment�rio" em cada comando de atribui��o explicando o que ele faz e o valor da vari�vel � esquerda do '=' ap�s sua execu��o.
*/

#include <stdio.h>
#include <stdlib.h>
 
int main()
{
int x, y, *p, *q; //x e y s�o variaveis do tipo int; p e q s�o variaveis ponteiro (para armazenamento de endere�os de mem�ria)
y = 19; // ==> y recebe 19
p = &y; // ==> p recebe o endere�o de mem�ria de y
x = *p; // ==> x recebe o conteudo apontado por p, que � 19
x = 7; //  ==> x recebe 7
(*p)++; // ==> imcrement de 1 no conteudo apontado por p ("y = 19 + 1")
x--; // =====> decrementa 1 de x (x = 7 - 1)
(*p) = (*p) + x; // ==> O conteudo apontado por p (que agora � 20) recebe o valor de x (que agora � 6)
printf ("Valor final => y = %d\n", y); // ==> valor final de y � 26.
 
return 0;
}

/*
  notas:
  
    *p = conteudo apontado por p;
*/
