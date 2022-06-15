/*


P1 - ALGORITMOS

03- Desenvolva um programa em C do problema a seguir (2,5): Utilizando comandos de sele��o aninhados, 
identifique e calcule a comiss�o de um vendedor baseado no valor de venda informado:

0 a 100, comiss�o de 1%

101 a 200, comiss�o de 2%

201 a 300, comiss�o de 3 %

301 a 400, comiss�o de 4%

Acima de 400, comiss�o de 5%

*/

#include <stdio.h>

int main()
{
//decla��o de variaveis
	float v, c;

//entrada de dados - valor de venda
	printf("Informe o valor de venda: ");
	scanf("%f", &v);

//inicio do processamento e calculo das comiss�es
	if (v > 0 && v <=100)
	{
		c = v * 0.01;	//calcula valor da comiss�o quando a condi��o for de 1%
		printf("\nValor de venda informado: R$%.2f\n", v);	//saida de dados, informando o valor de venda digitado
		printf("Comissao de 1%% = R$%.2f\n", c);	//saida de dados, informando o valor da comiss�o
	}
	else
	{
		if (v > 100 && v <=200)
		{
			c = v * 0.02;	//calcula valor da comiss�o quando a condi��o for de 2%
			printf("\nValor de venda informado: R$%.2f\n", v);	//saida de dados, informando o valor de venda digitado
			printf("Comissao de 2%% = R$%.2f\n", c);	//saida de dados, informando o valor da comiss�o
		}
		else
		{
			if (v > 200 && v <=300)
			{
				c = v * 0.03;	//calcula valor da comiss�o quando a condi��o for de 3%
				printf("\nValor de venda informado: R$%.2f\n", v);	//saida de dados, informando o valor de venda digitado
				printf("Comissao de 3%% = R$%.2f\n", c);	//saida de dados, informando o valor da comiss�o
			}
			else
			{
				if (v > 300 && v <=400)
				{
					c = v * 0.04;	//calcula valor da comiss�o quando a condi��o for de 4%
					printf("\nValor de venda informado: R$%.2f\n", v);	//saida de dados, informando o valor de venda digitado
					printf("Comissao de 4%% = R$%.2f\n", c);	//saida de dados, informando o valor da comiss�o
				}
				else
				{
					if (v > 400)
					{
						c = v * 0.05;	//calcula valor da comiss�o quando a condi��o for de 5%
						printf("\nValor de venda informado: R$%.2f\n", v);	//saida de dados, informando o valor de venda digitado
						printf("Comissao de 5%% = R$%.2f\n", c);	//saida de dados, informando o valor da comiss�o
					}
					else
					{
						printf("\nValor de venda INVALIDO.\n");	//saida de dados, informando/validando valor de venda quando menor ou igual a zero
					}
				}
			}
		}
	}
	
	return 0;
//fim do programa
}
