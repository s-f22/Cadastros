/*
ALUNO: Samuel Figueiredo Silveira
RA: 2040482113024
DATA: 12/04/2021
TURMA: ADS IPIRANGA, NOTURNO, 1°SEMESTRE

P1 - ALGORITMOS

03- Desenvolva um programa em C do problema a seguir (2,5): Utilizando comandos de seleção aninhados, 
identifique e calcule a comissão de um vendedor baseado no valor de venda informado:

0 a 100, comissão de 1%

101 a 200, comissão de 2%

201 a 300, comissão de 3 %

301 a 400, comissão de 4%

Acima de 400, comissão de 5%

*/

#include <stdio.h>

int main()
{
//declação de variaveis
	float v, c;

//entrada de dados - valor de venda
	printf("Informe o valor de venda: ");
	scanf("%f", &v);

//inicio do processamento e calculo das comissões
	if (v > 0 && v <=100)
	{
		c = v * 0.01;	//calcula valor da comissão quando a condição for de 1%
		printf("\nValor de venda informado: R$%.2f\n", v);	//saida de dados, informando o valor de venda digitado
		printf("Comissao de 1%% = R$%.2f\n", c);	//saida de dados, informando o valor da comissão
	}
	else
	{
		if (v > 100 && v <=200)
		{
			c = v * 0.02;	//calcula valor da comissão quando a condição for de 2%
			printf("\nValor de venda informado: R$%.2f\n", v);	//saida de dados, informando o valor de venda digitado
			printf("Comissao de 2%% = R$%.2f\n", c);	//saida de dados, informando o valor da comissão
		}
		else
		{
			if (v > 200 && v <=300)
			{
				c = v * 0.03;	//calcula valor da comissão quando a condição for de 3%
				printf("\nValor de venda informado: R$%.2f\n", v);	//saida de dados, informando o valor de venda digitado
				printf("Comissao de 3%% = R$%.2f\n", c);	//saida de dados, informando o valor da comissão
			}
			else
			{
				if (v > 300 && v <=400)
				{
					c = v * 0.04;	//calcula valor da comissão quando a condição for de 4%
					printf("\nValor de venda informado: R$%.2f\n", v);	//saida de dados, informando o valor de venda digitado
					printf("Comissao de 4%% = R$%.2f\n", c);	//saida de dados, informando o valor da comissão
				}
				else
				{
					if (v > 400)
					{
						c = v * 0.05;	//calcula valor da comissão quando a condição for de 5%
						printf("\nValor de venda informado: R$%.2f\n", v);	//saida de dados, informando o valor de venda digitado
						printf("Comissao de 5%% = R$%.2f\n", c);	//saida de dados, informando o valor da comissão
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
