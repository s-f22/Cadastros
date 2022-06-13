/*

Aluno: Samuel Figueiredo Silveira
ADS Ipiranga Noturno 1 Semestre

2 - Crie um programa que armazene em uma matriz 10x3 
em cada uma das colunas armazene o tamanho de uma aresta 
de um triangulo, ao final exiba o percentual de triangulos 
isoceles, equilateros e escalenos

*/

#include <stdio.h>

int main()
{
	float triangulo [10][3];
	int i;
	float isoceles = 0;
	float equilatero = 0;
	float escaleno = 0;
	
	
	for(i = 0; i < 10; i++)
	{
		printf("\nAresta A do %i triangulo: ", i + 1);
		scanf("%f", &triangulo[i][0]);
		
		printf("Aresta B do %i triangulo: ", i + 1);
		scanf("%f", &triangulo[i][1]);
		
		printf("Aresta C do %i triangulo: ", i + 1);
		scanf("%f", &triangulo[i][2]);
		
		if((triangulo[i][0] == triangulo[i][1] && triangulo[i][0] != triangulo[i][2]) || triangulo[i][0] == triangulo[i][2] && triangulo[i][0] != triangulo[i][1])
		{
			isoceles++;
		}
		else
		{
			if(triangulo[i][0] == triangulo[i][1] && triangulo[i][0] == triangulo[i][2])
			{
				equilatero++;
			}
			else
			{
				escaleno++;
			}
		}
	}
	
	escaleno = escaleno * 10;
	isoceles = isoceles * 10;
	equilatero = equilatero * 10;
	
	printf("\n\nQuantidade total de tringulos: \n\n");
	printf("Escaleno: %.1f%%\n", escaleno);
	printf("Isoceles: %.1f%%\n", isoceles);
	printf("Equilatero: %.1f%%\n\n", equilatero);
	
	return 0;
}
