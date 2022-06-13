/*
ALUNO: Samuel Figueiredo Silveira
RA: 2040482113024
DATA: 26/04/2021
TURMA: ADS IPIRANGA, NOTURNO, 1°SEMESTRE

P1 - ALGORITMOS - ATIVIDADE COMPLEMENTAR

Informe três números inteiros, utilizando comandos de seleção encadeados,
defina qual o menor, do meio e o maior número.

Caso os números forem iguais, mostre a mensagem : Números Iguais, verifique

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

