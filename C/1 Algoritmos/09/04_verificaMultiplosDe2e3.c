/*

4- fa�a um la�o �fa�a at� com 10 intera��es, verifique quantas
vezes n�meros m�ltiplos de 2 e de 3 s�o informados

*/

#include <stdio.h>

int main ()
{
	int i, numero;
	int m_2 = 0;
	int m_3 = 0;
	
	for (i = 1; i <= 10; i++)
	{
		printf("Informe um numero inteiro: ");
		scanf("%i", &numero);
		
		if ((numero % 2) == 0)
		{
			m_2++;
		}
		
		if ((numero % 3) == 0)
		{
			m_3++;
		}
	}
	
	printf("\nForam digitados %i numeros multiplos de 2.\n", m_2);
	printf("Foram digitados %i numeros multiplos de 3.\n\n", m_3);
	
	return 0;
}
