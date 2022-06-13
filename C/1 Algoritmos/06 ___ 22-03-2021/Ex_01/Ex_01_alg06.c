/* 	
	Aluno: 	Samuel Figueiredo Silveira
	Data:	22/03/2021
	
ATIVIDADE alg06
EX 01

1- A empresa XPTO concedeu um bônus de 20% do valor do salário a todos os funcionários
com tempo de trabalho na empresa igual ou superior a 5 anos e de 10% aos demais.
Faça um um programa em C que receba o salário e o tempo de serviço de um
funcionário, calcule e mostre o valor do bônus recebido por ele.

*/

#include<stdio.h>

int main()
{
	float salario, tServ, bonus;
	
	printf("Insira o valor do salario (R$): \n");
	scanf("%f", &salario);
	
	printf("Insira o tempo de servico (em anos): \n");
	scanf("%f", &tServ);
	
	if (tServ >= 5)
	{
		bonus = (salario * 0.2);
	} else 
		{
			bonus = (salario * 0.1);
		}
	
	printf("Valor calculado do bonus (R$): %.2f \n", bonus);
	
	return 0;
}
