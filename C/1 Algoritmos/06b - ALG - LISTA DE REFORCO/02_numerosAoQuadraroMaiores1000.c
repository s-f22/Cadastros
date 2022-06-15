/*

9-Desenvolva um programa em C que: Leia 4 (quatro) números; Calcule o quadrado de cada um; 
Se o valor resultante do quadrado do terceiro for >= 1000, imprima-o e finalize; 
Caso contrário, imprima os valores lidos e seus respectivos quadrados.

*/

#include <stdio.h>
// #include <math.h>

int main ()
{
	int n1, n2, n3, n4;
	int q1, q2, q3, q4;
	
	printf("Insira quatro numeros inteiros: ");
	scanf("%i %i %i %i", &n1, &n2, &n3, &n4);
	
	q1 = n1 * n1;	// pow(n1, 2);
	q2 = n2 * n2;	// pow(n2, 2);
	q3 = n3 * n3;	// pow(n3, 2);
	q4 = n4 * n4;	// pow(n4, 2);
	
	if (q3 >= 1000)
	{
		printf("Quadrado de %i: %i \n", n3, q3);
	}
	else
	{
		printf("Foram digitados %i, %i, %i e %i. Seus respectivos quadrados sao: %i, %i, %i e %i \n", n1, n2, n3, n4, q1, q2, q3, q4);
	}
	
	return 0;
}
