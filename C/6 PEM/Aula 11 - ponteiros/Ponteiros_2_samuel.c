#include <stdio.h>
#include <stdlib.h>

/*
 2) Comente o trecho abaixo linha-a-linha e mostre o que ser� impresso pelo comando printf: 
*/

int main(int argc, char *argv[]) {

int a = 10, b = 7, c; // ==> a recebe 10, b recebe 7, c � somente declarada, n�o inicializada;
int * p = &a; // ==> p recebe o endere�o de a ==> p aponta para o valor de a, que � 10;
int * q = &b; // ==> q recebe o endere�o de b ==> q aponta para o valor de b, que � 7;
int * r = &c; // ==> r recebe o endere�o de c ==> r aponta para o valor de c que n�o foi definido;
*r = *p; // ==> r recebe o conteudo apontado por p ( = 10) 
*p = *q; // ==> p recebe o conteudo apontado por q ( = 7)  
*q = *r; // ==> q recebe o conteudo apontado por r ( = 10)


printf("%d  -  %d\n", a, b); // ==> imprime os valores de a=7 e b=10, agora invertidos

/*

Pegamos o conteudo apontado por (*p) que recebeu o endere�o de "a" que � 10 e colocamos em r (*r = *p); depois disso,
p recebe outro conteudo (*p = *q), que � o apontado por (*q) que recebeu o endere�o de "b" que � 7. """ Ou seja, *p que
tinha o endere�o de 'a' agora tem o endere�o de 'b'. """ Em seguida, q recebe o conteudo de (*r) que recebeu o conteudo 
apontado por (*p) que recebeu o endere�o de "a". """ Ou seja, *q agora tem o endere�o de 'a'. Por isso, temos a=7 e b=10"""

*/

	return 0;
}
