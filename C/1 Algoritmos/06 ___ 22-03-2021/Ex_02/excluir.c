/* 	
	Aluno: 	Samuel Figueiredo Silveira
	Data:	22/03/2021
	
ATIVIDADE alg06
EX 02

2-Fa�a um programa em C que verifique se o ano � bissexto ou n�o. Se ele n�o for bissexto, 
indique quanto tempo falta para o pr�ximo bissexto.

Para ser bissexto, o ano deve ser:
	- Divis�vel por 4. Sendo assim, a divis�o � exata com o resto igual a zero;
	- N�o pode ser divis�vel por 100. Com isso, a divis�o n�o � exata, ou seja, 
	deixa resto diferente de zero;
	- Pode ser que seja divis�vel por 400.

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
