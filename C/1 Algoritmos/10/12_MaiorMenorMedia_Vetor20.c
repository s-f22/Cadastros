/*

Nome: Samuel Figueiredo Silveira
ADS Ipiranga Noturno 1� Semestre

c � fa�a um algoritmo que implemente um vetor de 20 posi��es, 
leia as 20 posi��es e identifique em um novo la�o, qual o 
maior e menor numero informado e qual a media dos n�meros informados.

*/

#include <stdio.h>

int main()
{
	int vetor[20];
	int i, j;
	
	double media = 0;
	
	for(i = 0; i < 20; i++)
	{
		printf("Digite um numero inteiro: ");
		scanf("%i", &vetor[i]);
	}
	
	int maior = vetor[0];
	int menor = vetor[0];
	
	for(j = 0; j < 20; j++)
	{
		if(vetor[j] > maior) maior = vetor[j];
		
		if (vetor[j] < maior && vetor[j] < menor) menor = vetor[j];
		
		media += vetor[j];
	}
	
	media = media / 20;
	
	printf("\nMaior: %i \nMenor: %i \nMedia: %.1f \n\n", maior, menor, media);
	
	return 0;
}
