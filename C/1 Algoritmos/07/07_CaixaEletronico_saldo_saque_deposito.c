/*

1) faça um algoritmo que simule o funcionamento de um caixa eletrônico, onde será apresentado uma lista de operações:

1-Saldo
2-Saque
3-Deposito

Ao iniciar o programa determine um valor inicio para a variável saldo, se o cliente escolher a opção 1 mostre o valor do saldo,
caso escolha o valor 2 leia o valor a ser sacado e verifique se existe saldo suficiente, se o saldo for maior ou igual , 
deduza da variável saldo o valor solicitado, caso não haja saldo suficiente mostre a mensagem “Saldo Insuficiente”, 
caso a opção 3 seja escolhida adicione o valor informado de deposito ao saldo.

*/

#include <stdio.h>

int main()

{
	float saldo, saque, deposito;
	int option;
	
	printf("Insira um valor de saldo: R$");
	scanf("%f", &saldo);
	
	printf("Insira a opcao desejada:\n 1: exibir saldo; 2: efetuar saque; 3: efetuar deposito \n");
	scanf("%i", &option);
	
	switch (option)
	{
		case 1:
			printf("Valor do saldo: R$%.2f\n", saldo);
			break;
			
		case 2:
			printf("Informe o valor do saque: R$");
			scanf("%f", &saque);
			
			if (saldo >= saque)
			{
				saldo = saldo - saque;
				printf("Saldo atualizado: R$%.2f \n", saldo);
			}
			else
			{
				printf("Saldo insuficiente.");
			}
			
			break;
			
		case 3:
			printf("Informe o valor do deposito: R$");
			scanf("%f", &deposito);
			
			saldo = saldo + deposito;
			printf("Saldo atualizado: R$%.2f\n", saldo);
			
			break;
			
		default:
			printf("Opcao Invalida");
			break;	
		
	}
	
	return 0;
}
