/*
Aluno: Samuel Figueiredo Silveira

4- Reescreva o programa do caixa eletr�nico utilizando ponteiros. 

Fa�a um algoritmo que simule o funcionamento de um caixa eletr�nico, onde ser� 
apresentado uma lista de opera��es: 

1-Saldo 
2-Saque 
3-Deposito 

Ao iniciar o programa determine um valor inicial para a vari�vel saldo 
(utilize um ponteiro para manter o valor do saldo), se o cliente escolher a op��o 1 
mostre o valor do saldo, caso escolha o valor 2 leia o valor a ser sacado e verifique 
se existe saldo suficiente, se o saldo for maior ou igual , deduza da vari�vel saldo o 
valor solicitado, caso n�o haja saldo suficiente mostre a mensagem �Saldo Insuficiente�, 
caso a op��o 3 seja escolhida adicione o valor informado de deposito ao saldo. 
Implemente um la�o fa�a enquanto que verifique se o usu�rio deseja continuar, 
caso a vari�vel coletada for igual 1 reinicie o la�o, mantendo o valor do saldo. 

*/

#include <stdio.h>
#include <string.h>


void sacar(float *saldo, float *valor)
{
	if (*saldo >= *valor)
	{
		*saldo -= *valor; 
		printf("Saldo atualizado: R$%.2f \n", *saldo);
	}
	else
		printf("Saldo insuficiente.\n");
}

void depositar(float *saldo, float *valor)
{
	*saldo += *valor;
	printf("Saldo atualizado: R$%.2f\n", *saldo);
}

void imprimirSaldo(float *saldo)
{
	printf("\nValor do saldo atual: R$%.2f\n", *saldo);
}

float inicializar(float *saldo)
{
	printf("Insira um valor de saldo inicial: R$");
	scanf("%f", &saldo);
}


int main()

{
	float saldo, valor;
	int opcao, continuar;
	
	saldo = inicializar(&saldo);
	
	do
	{
	printf("\nDigite a opcao desejada para:\n\n1: exibir saldo; \n2: efetuar saque; \n3: efetuar deposito \n");
	scanf("%i", &opcao);
	
	switch (opcao)
	{
		case 1:
			imprimirSaldo(&saldo);
			break;
			
		case 2:
			printf("\nInforme o valor do saque: R$");
			scanf("%f", &valor);
			
			sacar(&saldo, &valor);
			
			break;
			
		case 3:
			printf("\nInforme o valor do deposito: R$");
			scanf("%f", &valor);
			
			depositar(&saldo, &valor);
			
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

