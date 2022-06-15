/*
ALUNO: SAMUEL FIGUEIREDO SILVEIRA
FATEC IPIRANGA - ADS - NOTURNO
P1 - PEM

3) Crie uma fun��o em C que receba por par�metro dois vetores de n�meros reais 
e um n�mero inteiro que represente o tamanho destes vetores; a fun��o deve calcular 
o chamado produto escalar de dois vetores. Este c�lculo multiplica os valores 
correspondentes dos dois vetores, ou seja, A[0] multiplicado por B[0], A[1] por B[1], �. , 
at� A[10] por B[10], e depois soma todos estes resultados parciais: 
(A[0] * B[0]) + (A[1] * B[1]) + (A[2] * B[2]) + � + (A[10] * B[10]). 
Pronto! A assinatura da fun��o � assim: int produtoEscalar (double A[ ], double B[ ], int N).

OBS.: USE COMANDOS DE REPETI��O, POIS OS VETORES PODEM SER DE TAMANHO ARBITR�RIO (O ACIMA � S� UM EXEMPLO).

*/


#include<stdio.h>

int produtoEscalar (int A[ ], int B[ ], int N)
{
	int i;
	double multi, soma = 0;
	int cont = N;
		
		for (i = 0; i < cont, N >= 0; i++)
		{
			multi = (A[i] = N) * (B[i] = N);
			soma = soma + multi;
			N = N - 1;
		}
		
	return soma;
}

int main()
{
	int N;
	int resultado;
	
	printf("Digite um numero: ");
	scanf("%i", &N);
	
	double A[N], B[N];
	
	resultado = produtoEscalar(A, B, N);
	
	printf("Produto escalar dos dois vetores equivalentes a N = %d", (int)resultado);
	
	return 0;
}
