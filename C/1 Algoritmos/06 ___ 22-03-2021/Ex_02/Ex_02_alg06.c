/* 	
	Aluno: 	Samuel Figueiredo Silveira
	Data:	22/03/2021
	
ATIVIDADE alg06
EX 02

2- Faça um programa em C que verifique se o ano é bissexto ou não. 
Se ele não for bissexto, indique quanto tempo falta para o próximo bissexto.

Para ser bissexto, o ano deve ser:
Divisível por 4. Sendo assim, a divisão é exata com o resto igual a zero;
Não pode ser divisível por 100. Com isso, a divisão não é exata, ou seja, 
deixa resto diferente de zero;
Pode ser que seja divisível por 400.

*/

#include <stdio.h>

int main()
{
	int ano, resto_4, resto_100, resto_400, contador;
	
	printf("Digite um ano qualquer: \n");
	scanf("%i", &ano);
	
	resto_4 = ano % 4;
	resto_100 = ano % 100;
	resto_400 = ano % 400;
	contador = 4 - resto_4;
	
	if (resto_4 == 0)
	{
		if (resto_100 == 0)
		{
			if (resto_400 == 0)
			{
				printf("%i = ano BISSEXTO. \n", ano);
			} else
			{
				printf("%i = NAO Bissexto. ", ano);
				printf("Falta(m) %i ano(s) para o proximo bissexto. \n", contador);
			}
		} else 
		{
			printf("%i = ano BISSEXTO. \n", ano);
		}
	} else
	{
		printf("%i = NAO Bissexto. ", ano);
		printf("Falta(m) %i ano(s) para o proximo bissexto. \n", contador);
	}
	
	return 0;
}
