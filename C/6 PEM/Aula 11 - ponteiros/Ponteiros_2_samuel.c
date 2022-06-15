#include <stdio.h>
#include <stdlib.h>

/*
 2) Comente o trecho abaixo linha-a-linha e mostre o que será impresso pelo comando printf: 
*/

int main(int argc, char *argv[]) {

int a = 10, b = 7, c; // ==> a recebe 10, b recebe 7, c é somente declarada, não inicializada;
int * p = &a; // ==> p recebe o endereço de a ==> p aponta para o valor de a, que é 10;
int * q = &b; // ==> q recebe o endereço de b ==> q aponta para o valor de b, que é 7;
int * r = &c; // ==> r recebe o endereço de c ==> r aponta para o valor de c que não foi definido;
*r = *p; // ==> r recebe o conteudo apontado por p ( = 10) 
*p = *q; // ==> p recebe o conteudo apontado por q ( = 7)  
*q = *r; // ==> q recebe o conteudo apontado por r ( = 10)


printf("%d  -  %d\n", a, b); // ==> imprime os valores de a=7 e b=10, agora invertidos

/*

Pegamos o conteudo apontado por (*p) que recebeu o endereço de "a" que é 10 e colocamos em r (*r = *p); depois disso,
p recebe outro conteudo (*p = *q), que é o apontado por (*q) que recebeu o endereço de "b" que é 7. """ Ou seja, *p que
tinha o endereço de 'a' agora tem o endereço de 'b'. """ Em seguida, q recebe o conteudo de (*r) que recebeu o conteudo 
apontado por (*p) que recebeu o endereço de "a". """ Ou seja, *q agora tem o endereço de 'a'. Por isso, temos a=7 e b=10"""

*/

	return 0;
}
