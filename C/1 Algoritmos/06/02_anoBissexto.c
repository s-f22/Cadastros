/* 	
	
	
ATIVIDADE alg06
EX 02

2- Fa�a um programa em C que verifique se o ano � bissexto ou n�o. 
Se ele n�o for bissexto, indique quanto tempo falta para o pr�ximo bissexto.

Para ser bissexto, o ano deve ser:
Divis�vel por 4. Sendo assim, a divis�o � exata com o resto igual a zero;
N�o pode ser divis�vel por 100. Com isso, a divis�o n�o � exata, ou seja, 
deixa resto diferente de zero;
Pode ser que seja divis�vel por 400.

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
