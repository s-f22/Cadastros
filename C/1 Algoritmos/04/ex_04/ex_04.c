#include <stdio.h>

int main()
{
	float salario, emprestimo, percentual;
	
	percentual = 1 * 0.2;
	
	printf("Digite o valor do salario: ");
	scanf("%f", &salario);
	
	printf("Digite o valor da prestacao do emprestimo: ");
	scanf("%f", &emprestimo);
	
	if (emprestimo / salario > percentual)
	{
		printf("Emprestimo NAO concedido.");
	}else{
		printf("Emprestimo CONCEDIDO!");
	}
	
	return 0;
}
