/*


01 - Fa�a um programa que receba e armazene 
em um vetor 30 n�meros inteiros e verifique 
qual a maior sequencia de n�meros pares 
informados (1,5)	

*/

#include <stdio.h>

int main()
{
//DECLARA��O DAS VARIAVEIS
	int i, num[30], contador_1 = 0, contador_2 = 0, resto;
    
// ESTRUTURA DE REPETI��O PARA CAPTURAR OS VALORES
	for (i = 1; i <= 30; i++)
    {
		printf("Informe o %i numero: ", i);
		scanf("%i", &num[i]);

		resto = num[i] % 2; //modulo = resto da divisao inteira 

// VERIFICA��O DA SEQUENCIA DE NUMEROS PARES 
		if(resto == 0 )
        {
			contador_1++; // contador_1 = contador_1 + 1;

			if(contador_1 > contador_2)
				contador_2 = contador_1;	
		}
        else 
			contador_1 = 0;
	}
//RETORNO DE INFORMA��ES NA TELA
	printf("A maior sequencia de numeros pares foi: %i", contador_2);	
	
	return 0;
}

