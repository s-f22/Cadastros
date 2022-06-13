/* 	
	Aluno: 	Samuel Figueiredo Silveira
	Data:	22/03/2021
	
ATIVIDADE alg06
EX 02

2-Faça um programa em C que verifique se o ano é bissexto ou não. Se ele não for bissexto, 
indique quanto tempo falta para o próximo bissexto.

Para ser bissexto, o ano deve ser:
	- Divisível por 4. Sendo assim, a divisão é exata com o resto igual a zero;
	- Não pode ser divisível por 100. Com isso, a divisão não é exata, ou seja, 
	deixa resto diferente de zero;
	- Pode ser que seja divisível por 400.

*/

#include <stdio.h>

int main()
{
	int ano, resto4, resto100, resto400, faltam;
	
	printf("Insira um ano qualquer para verificar se bissexto: \n");
	scanf("%i", &ano);
	
	resto4 = ano % 4;
	resto100 = ano % 100;
	resto400 = ano % 400;
	faltam = 4 - resto4;
	
	if (resto4 == 0)
	{
		if (resto100 != 0)
		{
			printf("%i = Bissexto. \n", ano);
		} else
		{
			printf("%i = invalido. ", ano);
			if (faltam != 4)
			{
				printf("Falta(m) %i ano(s) para o proximo bissexto. \n", faltam);
			}
		}
	} else
	{
		if (resto400 == 0)
		{
			printf("%i = Bissexto. \n", ano);
		} else
		{
			printf("%i = invalido. ", ano);
			if (faltam != 4)
			{
				printf("Falta(m) %i ano(s) para o proximo bissexto. \n", faltam);
			}
		}
	}
	
	return 0;
}
