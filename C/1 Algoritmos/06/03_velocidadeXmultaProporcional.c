/* 	
	
ATIVIDADE alg06
EX 03

3- Leia a velocidade m�xima permitida em uma avenida e a velocidade 
com que o motorista estava dirigindo nela. Calcule e mostre a multa 
que uma pessoa vai receber, sabendo que s�o pagos: R$ 50 reais se o 
motorista ultrapassar em at� 10km/h a velocidade permitida; R$ 100 reais, 
se o motorista ultrapassar de 11 a 30 km/h a velocidade permitida; e R$ 200 reais, 
se estiver acima de 31km/h da velocidade permitida.

*/

#include <stdio.h>

int main()
{
	float vMaxPermit, vMot, dif;
	
	printf("Insira a velocidade maxima PERMITIDA na via: \n");
	scanf("%f", &vMaxPermit);
	
	printf("Insira a velocidade do MOTORISTA: \n");
	scanf("%f", &vMot);
	
	dif = vMot - vMaxPermit;
	
	if (dif > 0 && dif <= 10)
	{
		printf("Multado em: R$50,00. \n");
	} else
	{
		if (dif >= 11 && dif <= 30)
		{
			printf("Multado em: R$100,00. \n");
		} else
		{
			if (dif >= 31)
			{
				printf("Multado em: R$200,00. \n");
			} else
			{
				printf("Velocidade normal. \n");
			}
		}
	}
	
	return 0;
}
