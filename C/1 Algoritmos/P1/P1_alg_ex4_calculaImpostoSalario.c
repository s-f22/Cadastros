/*


P1 - ALGORITMOS

04-Desenvolva um programa em C do problema a seguir (2,5): Utilizando comandos de sele��o aninhados, 
fa�a o c�lculo do sal�rio l�quido atrav�s de um sal�rio bruto informado seguindo as devidas regras:

Primeiro deduzir o INSS de 11% do sal�rio bruto antes de verificar a faixa do IR

Faixa de R$ 1,00 a R$ 1020,00 Isento de IR

Faixa de R$ 1020,01 a R$ 2.500,00 7% de taxa de IR

Faixa de R$ 2500,01 a R$ 3.800,00 15% de taxa de IR

Faixa de R$ 3800,01 e acima,  27.5% de taxa de IR

Sal�rio L�quido = (Sal�rio bruto � INSS) � IR

*/

#include <stdio.h>

int main ()
{

//declara��o de variaveis
	float sLiq, sBrut, inss, ir;
	
//entrada de dados	
	printf("Informe o salario BRUTO: ");
	scanf("%f", &sBrut);
	
//calculo do INSS e do valor restante ao desconta-lo do salario bruto
//inicio dos processamentos	
	inss = sBrut * 0.11;
	sLiq = sBrut - inss;

	if (sLiq > 0 && sLiq <= 1020.0)		//identifica condi��o de isen��o do IR
	{
		//bloco de saida de dados, devolvendo as informa��es calculadas ao usuario
		printf("\nIsento de IR. \n");
		printf("Salario Bruto: R$%.2f \n", sBrut);
		printf("INSS de 11%%: R$%.2f \n", inss);
		printf("Salario Liquido: R$%.2f \n", sLiq);
	}
	else
	{
		if (sLiq > 1020 && sLiq <= 2500)	//identifica salarios na faixa de desconto de 7% do IR
		{
			ir = sLiq * 0.07;	//calcula IR
			sLiq = sLiq - ir;	//calcula o salario liquido
			//bloco de saida de dados, devolvendo as informa��es calculadas ao usuario
			printf("\nSalario Bruto: R$%.2f \n", sBrut);
			printf("INSS de 11%%: R$%.2f \n", inss);
			printf("7%% de taxa de IR: R$%.2f \n", ir);
			printf("Salario Liquido: R$%.2f \n", sLiq);
		}
		else
		{
			if (sLiq > 2500 && sLiq <= 3800)	//identifica salarios na faixa de desconto de 15% do IR
			{
				ir = sLiq * 0.15;	//calcula IR
				sLiq = sLiq - ir;	////calcula o salario liquido
				//bloco de saida de dados, devolvendo as informa��es calculadas ao usuario
				printf("\nSalario Bruto: R$%.2f \n", sBrut);
				printf("INSS de 11%%: R$%.2f \n", inss);
				printf("15%% de taxa de IR: R$%.2f \n", ir);
				printf("Salario Liquido: R$%.2f \n", sLiq);
			}
			else
			{
				if (sLiq > 3800)	//identifica salarios na faixa de desconto de 27,5% do IR
				{
					ir = sLiq * 0.275;	//calcula IR
					sLiq = sLiq - ir;	////calcula o salario liquido
					//bloco de saida de dados, devolvendo as informa��es calculadas ao usuario
					printf("\nSalario Bruto: R$%.2f \n", sBrut);
					printf("INSS de 11%%: R$%.2f \n", inss);
					printf("27,5%% de taxa de IR: R$%.2f \n", ir);
					printf("Salario Liquido: R$%.2f \n", sLiq);
				}
				else
				{
					//bloco de saida de dados, casos o valor inserido em salario bruto seja menor ou igual a zero
					printf("\nValor de salario INVALIDO.\n");
				}
			}
		}
	}

	return 0;
// finaliza��o do programa
}
