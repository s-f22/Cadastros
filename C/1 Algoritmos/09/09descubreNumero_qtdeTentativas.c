/*

9- Crie um algoritmo onde será informado um valor inteiro inicial,  
e um laço o usuário devera informar outro numero inteiro, o programa 
deverá responder se o numero atual e menor ou maior que o numero 
inicial informado, o laço somente será interrompido quando o numero 
atual for igual ao número anterior informado. Exiba quantas tentativas 
foram necessárias para que o numero fosse descoberto.

*/

#include <stdio.h>

int main ()
{
	int chave = 51;
	int numero;
	int contador = 0;
	int parar = 0;
	
	do
	{
		printf("\nInsira um numero inteiro: ");
		scanf("%i", &numero);
		
		if (numero == chave)
		{
			if (numero == chave && contador == 0)
			{
				printf("Parabens! Voce descobriu na primeira tentativa!!!\n");
				parar = 1;
				break;
			}
			
			contador++;
			printf("Parabens! Voce descobriu o numero correto em %i tentativas.\n", contador);
			parar = 1;
		}
		else
		{
			if (numero > chave)
			{
				printf("O numero digitado e maior que a chave. Tente novamente.\n");
				contador++;
			}
			else
			{
				printf("O numero digitado e menor que a chave. Tente novamente.\n");
				contador++;
			}
		}
	} while(parar == 0);
	
	
	return 0;
}
