#include <stdio.h>


float media(float n1, float n2)
{
	float retorno = (n1 + n2)/2;
	return retorno;
}

void mostrarMaior(float n1, float n2)
{
	if(n1>n2)
	{
		printf("\nN1 e maior = %f", n1);
	}
	else
	{
		printf("\nN2 e maior = %f", n2);
	}
}


 int main()
 { 	
 	float x = media(45.23, 23.675); 	
 	printf("A media e igual a: %f", x);
 	mostrarMaior(234, 2352);
 	
 	return 0;
 }
