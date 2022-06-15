/*

A – Faça um algoritmo que implemente um laço que leia X números inteiros e identifique 
qual o menor o maior e a media, quando o número informado for zero, interrompa o 
laço e exiba os valores.

*/

#include <stdio.h>

int main()

{
	
        int numero;
        int menor;
        int maior;
        float media;
        int teste;
        
		printf("Digite um numero: \n");
		scanf("%i", &menor);
		
		printf("\nDigite outro numero: \n");
		scanf("%i", &numero);
		
		if (menor > numero)
		{
			menor = numero;
		}
		else
		{
			maior = numero;
		}
		
		
		while (numero != 0)
		
		{
			printf("\nDigite outro numero: \n");
			scanf("%i", &numero);
			
			if (menor > numero)
		{
			menor = numero;
		}
		else
		{
			maior = numero;
		}
		
		if (menor == 1)
		{
			teste = 1;
		}
		
		}
		
		if (teste == 1)
		{
			media = (maior + menor) / 2;
			printf("\nNumeros: %i e %i\n", teste, maior);
			printf("Media: %f", media);
		}
		else
		{
		media = (maior + menor) / 2;
		printf("\nNumeros: %i e %i\n", menor, maior);
		printf("Media: %f", media);
		}
		
			
	return 0;
}


