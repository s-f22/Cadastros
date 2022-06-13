/*
1) a) Qual o valor de y no final do programa?

==>   O valor final de y é 26.

   b) Escreva um "comentário" em cada comando de atribuição explicando o que ele faz e o valor da variável à esquerda do '=' após sua execução.
*/

#include <stdio.h>
#include <stdlib.h>
 
int main()
{
int x, y, *p, *q; //x e y são variaveis do tipo int; p e q são variaveis ponteiro (para armazenamento de endereços de memória)
y = 19; // ==> y recebe 19
p = &y; // ==> p recebe o endereço de memória de y
x = *p; // ==> x recebe o conteudo apontado por p, que é 19
x = 7; //  ==> x recebe 7
(*p)++; // ==> imcrement de 1 no conteudo apontado por p ("y = 19 + 1")
x--; // =====> decrementa 1 de x (x = 7 - 1)
(*p) = (*p) + x; // ==> O conteudo apontado por p (que agora é 20) recebe o valor de x (que agora é 6)
printf ("Valor final => y = %d\n", y); // ==> valor final de y é 26.
 
return 0;
}

/*
  notas:
  
    *p = conteudo apontado por p;
*/
