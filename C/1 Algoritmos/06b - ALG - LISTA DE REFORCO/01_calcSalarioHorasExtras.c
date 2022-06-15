/* 
	LISTA DE REFORCO
	EXERCICIO 8
	
Elabore um programa em C que leia as vari�veis C e N, respectivamente c�digo e n�mero de horas trabalhadas de um oper�rio. 
E calcule o sal�rio sabendo-se que ele ganha R$ 10,00 por hora. Quando o n�mero de horas exceder a 50 calcule o excesso de 
pagamento armazenando-o na vari�vel E, caso contr�rio zerar tal vari�vel. A hora excedente de trabalho vale R$ 20,00. 
No final do processamento imprimir o sal�rio total e o sal�rio excedente

*/

#include <stdio.h>

int main()
{
	int C;
	float N, E, salario;
	
	printf("Insira o codigo: ");
	scanf("%i", &C);
	
	printf("Insira o numero de horas trabalhadas: \n");
	scanf("%f", &N);
	
	if (N > 50)
	{
		E = N - 50;
		salario = 50 * 10;
		E = E * 20;
	} 
	else
	{
		E = 0;
		salario = N * 10;
	}
	
	printf("Salario total do operario %i: R$%.2f. Salario excedente: R$%.2f \n", C, salario, E);
	
	return 0;
}
