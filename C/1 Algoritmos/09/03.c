/*

3- Fa�a um la�o que calcule a media de todos os n�meros informados, 
a condi��o de termino do la�o e quando for digitado ZERO

*/

#include <stdio.h>

int main()
{
	int numero; 
	int contador = -1;
	float media = 0;
	
	do
	{
		printf("Digite um numero: ");
		scanf("%i", &numero);
		
		media = media + numero;
		contador++;
		
	} while (numero != 0);
	
	media = media / contador;
	
	printf("Media: %.2f", media);
	
	return 0;
}
