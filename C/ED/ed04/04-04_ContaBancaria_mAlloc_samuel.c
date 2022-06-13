/*
Aluno: Samuel Figueiredo

4. Utilizando a alocação dinamica de memoria crie uma função para criar uma nova conta bancaria

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // malloc/calloc

 
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



int inicializar(contaBancaria *c1, int *qtdAtualContas)
{
	if(*qtdAtualContas > 0)
	{
		printf("\nInforme o ID da conta (xx.xxx-x): ");
		scanf("%s", &c1->nrConta);
		//strcpy(c1.nrConta,"12.123-8");
		//gets(c1->nrConta);
		
		printf("Informe o numero da agencia (xxxx-x): ");
		scanf("%s", &c1->nrAgencia);
		
		printf("Informe o CPF (xxx.xxx.xxx-xx): ");
		scanf("%s", &c1->cpf);
		
		printf("Informe o saldo inicial da conta: R$");
		scanf("%f", &c1->saldo);
		
		*qtdAtualContas = (*qtdAtualContas-1);
		return 1;
	}
	else
	{
		printf("\nQuantidade de contas esgotada.\n");
		return 0;
	}
}

void imprimirInfos(contaBancaria *c1, int *contaCarregada, int *qtdInicialContas)
{
	printf("\nConta atual: %i/%i\nID: %s\nAgencia: %s\nCPF: %s\nValor do saldo atual: R$%.2f\n", (*contaCarregada+1), (*qtdInicialContas), c1->nrConta, c1->nrAgencia, c1->cpf, c1->saldo);
}




int main()

{
	
	float valor;
	int opcao, continuar, qtdInicialContas, qtdAtualContas, contaCarregada, proxima;
	
	printf("Informe quantas contas o sistema podera criar: ");
	scanf("%i", &qtdInicialContas);
	
	contaBancaria *contas = (contaBancaria*)calloc(qtdInicialContas, sizeof(contaBancaria));
	qtdAtualContas = qtdInicialContas;
	contaCarregada = (qtdInicialContas - 1);
	
	
	inicializar(&contas[contaCarregada], &qtdAtualContas); //chama a funcao passando um ponteiro do tipo contaBancaria, na ultima posicao informada (ja decrementada anteriomente, acima, para correcao do valor)
	
	do
	{
		printf("\nNumero da conta atual: %i/%i\n", (contaCarregada+1), (qtdInicialContas));
		printf("\nDigite a opcao desejada para:\n\n1: exibir saldo e informacoes da conta;\n2: efetuar saque;\n3: efetuar deposito;\n4: acessar outra conta;\n5: criar nova conta;\n");
	
		scanf("%i", &opcao);
	
		switch (opcao)
		{			
			case 1:
				imprimirInfos(&contas[contaCarregada], &contaCarregada, &qtdInicialContas);
				break;
				
			case 2:
				printf("\nInforme o valor do saque: R$");
				scanf("%f", &valor);
				
				sacar(&contas[contaCarregada], &valor);
				
				break;
				
			case 3:
				printf("\nInforme o valor do deposito: R$");
				scanf("%f", &valor);
				
				depositar(&contas[contaCarregada], &valor);
				
				break;
				
			case 4:
				printf("Informe o numero da conta: ");
				scanf("%i", &proxima);
				
				if(contas[proxima-1].saldo > 0 && (proxima-1) < qtdInicialContas)
				{
					contaCarregada = proxima-1;
					printf("\nOperacao realizada.\n");
				}
				else
					printf("\nConta invalida.\n");
				
				
				break;
				
			case 5:			
				if( inicializar(&contas[qtdAtualContas-1], &qtdAtualContas) == 1 )
					contaCarregada = qtdAtualContas;
				
				break;
				
			default:
				printf("Opcao Invalida\n");
				break;	
			
		}
	
	printf("\nDeseja fazer outra operacao? (1)sim (2)encerrar\n");
	scanf("%i", &continuar);
	
} while (continuar == 1);

printf("\nSistema encerrado.\n\n");
	
	free(contas);
	return 0;
}
 

 
