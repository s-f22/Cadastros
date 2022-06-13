/*

5- Reutilizando o algoritmo do caixa eletrônico, implemente um laço faça enquanto
que verifique se o usuário deseja continuar, caso a variável coletada for igual 1
reinicie o laço, mantendo o valor do saldo

*/

#include <stdio.h>

int main()

{
	float saldo, saque, deposito;
	int option, continuar;
	
	printf("Insira um valor de saldo inicial: R$");
	scanf("%f", &saldo);
	
	do
	{
	printf("\nInsira a opcao desejada:\n\n1: exibir saldo; \n2: efetuar saque; \n3: efetuar deposito \n");
	scanf("%i", &option);
	
	switch (option)
	{
		case 1:
			printf("Valor do saldo atual: R$%.2f\n", saldo);
			break;
			
		case 2:
			printf("\nInforme o valor do saque: R$");
			scanf("%f", &saque);
			
			if (saldo >= saque)
			{
				saldo = saldo - saque;
				printf("Saldo atualizado: R$%.2f \n", saldo);
			}
			else
			{
				printf("Saldo insuficiente.\n");
			}
			
			break;
			
		case 3:
			printf("\nInforme o valor do deposito: R$");
			scanf("%f", &deposito);
			
			saldo = saldo + deposito;
			printf("Saldo atualizado: R$%.2f\n", saldo);
			
			break;
			
		default:
			printf("Opcao Invalida\n");
			break;	
		
	}
	
	printf("\nDeseja fazer outra operacao? (1)sim (2)encerrar\n");
	scanf("%i", &continuar);
	
} while (continuar == 1);

printf("\nSistema encerrado.\n\n");
	
	return 0;
}


