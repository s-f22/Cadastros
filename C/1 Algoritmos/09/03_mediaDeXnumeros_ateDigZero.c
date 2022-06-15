/*

3- Faça um laço que calcule a media de todos os números informados, 
a condição de termino do laço e quando for digitado ZERO

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
