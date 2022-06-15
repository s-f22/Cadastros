/*


P1 - ALGORITMOS - ATIVIDADE COMPLEMENTAR

Informe tr�s n�meros inteiros, utilizando comandos de sele��o encadeados,
defina qual o menor, do meio e o maior n�mero.

Caso os n�meros forem iguais, mostre a mensagem : N�meros Iguais, verifique

*/

#include <stdio.h>

int main()

{
	int n1, n2, n3;
	int p, s, t;
	
	printf("Informe 3 numeros inteiros para ordena-los: ");
	scanf("%i %i %i", &n1, &n2, &n3);
	
	
	if (n1 == n2 || n1 == n3 || n2 == n3)
	{
		printf("Numeros iguais, verifique.");
	}
	else
	{
	
	if (n1 < n2 && n1 < n3)
	{
		p = n1;
		
		if (n2 < n3)
		{
			s = n2;
			t = n3;
		}
		else
		{
			s = n3;
			t = n2;
		}
	}
	else
	{
		if (n2 < n1 && n2 < n3)
		{
			p = n2;
			
			if (n1 < n3)
			{
				s = n1;
				t = n3;
			}
			else
			{
				s = n3;
				t = n1;
			}
		}
		else
		{
			p = n3;
			
			if (n1 < n2)
			{
				s = n1;
				t = n2;
			}
			else
			{
				s = n2;
				t = n1;
			}
		}
	}	
	
	printf("Numeros em ordem crescente: %i, %i e %i.", p, s, t);
		
	}
	
	
	
	return 0;
}

