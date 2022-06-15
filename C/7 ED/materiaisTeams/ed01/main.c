#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


float media(float n1, float n2){
	float retorno = (n1+n2)/2;
	return retorno;
}

void mostrarMaior(float n1, float n2){
	if(n1>n2){
		printf("N1 e maior=%f \n", n1);	
	}	else {
		printf("N2 e maior=%f \n", n2);		
	}
}

int main(int argc, char *argv[]) 
{
	float x = media(45.23, 23.675);
	printf("A media = %f \n", x);
	
	mostrarMaior(234,2352);
	return 0;
}
