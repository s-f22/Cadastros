/*
Aluno: Samuel Figueiredo

3. Crie um TAD que implemente o controle de uma conta bancaria, 
implemente funções para inicializar, deposito, 
sacar e imprimir o saldo.
*/

#include <stdio.h>
#include <string.h>
#include<conio.h>
#include <stdlib.h> // malloc

struct {
	char nrConta[9];
	char nrAgencia[7];
	char cpf[15];
	float saldo;
}typedef contaBancaria;


void sacar(contaBancaria *c1, float *valor)
{
	if(*valor > 0)
	{
		if (c1->saldo >= *valor)
		{
			c1->saldo -= *valor; 
			printf("Saldo atualizado: R$%.2f \n", c1->saldo);
		}
		else
			printf("Saldo insuficiente.\n");
	}
	else
		printf("Valor invalido\n");
}


void depositar(contaBancaria *c1, float *valor)
{
	if (*valor > 0)
	{
		c1->saldo += *valor;
		printf("Saldo atualizado: R$%.2f\n", c1->saldo);
	}
	else
		printf("Valor invalido\n");
}


void imprimirSaldo(contaBancaria *c1)
{
	printf("\nValor do saldo atual: R$%.2f\n", c1->saldo);
}


void inicializar(contaBancaria *c1)
{
	printf("Informe o numero da conta (xx.xxx-x): ");
	scanf("%s", &c1->nrConta);
	//strcpy(c1.nrConta,"12.123-8");
	//gets(c1->nrConta);
	
	printf("Informe o numero da agencia (xxxx-x): ");
	scanf("%s", &c1->nrAgencia);
	
	printf("Informe o CPF (xxx.xxx.xxx-xx): ");
	scanf("%s", &c1->cpf);
	
	printf("Informe o saldo inicial da conta: R$");
	scanf("%f", &c1->saldo);
}

void imprimirInfos(contaBancaria *c1)
{
	printf("\nNumero da conta: %s\nAgencia: %s\nCPF: %s\n", c1->nrConta, c1->nrAgencia, c1->cpf);
}


int main()

{
	contaBancaria c1;
	float valor;
	int opcao, continuar;
	
	inicializar(&c1);
	
	do
	{
	printf("\nDigite a opcao desejada para:\n\n1: exibir saldo; \n2: efetuar saque; \n3: efetuar deposito; \n4: exibir informacoes da conta \n");
	scanf("%i", &opcao);
	
	switch (opcao)
	{
		case 1:
			imprimirSaldo(&c1);
			break;
			
		case 2:
			printf("\nInforme o valor do saque: R$");
			scanf("%f", &valor);
			
			sacar(&c1, &valor);
			
			break;
			
		case 3:
			printf("\nInforme o valor do deposito: R$");
			scanf("%f", &valor);
			
			depositar(&c1, &valor);
			
			break;
			
		case 4:
			
			imprimirInfos(&c1);
			
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
