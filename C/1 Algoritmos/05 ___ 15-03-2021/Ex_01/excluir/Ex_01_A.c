#include <stdio.h>
int main()
{
	float p1, p2, p3, media, exame;
	int faltas, totalFaltas;
	
	printf("Digite a nota 1, nota 2 e total de faltas: ");
	scanf("%f %f %i", &p1, &p2, &faltas);
		
	media = ((p1 + p2) / 2);
	totalFaltas = 20 * 0.3;
			
	if (faltas > totalFaltas)
	{
		printf("REPROVADO por faltas.");
	} else {
		if (media >= 6)
		{
			printf("Aluno APROVADO.");
		} else {
			printf("Digite a nota 3: ");
			scanf("%f", &p3);
			if (((p1 + p2 + p3) / 3 ) >= 6)
			{
				printf("APROVADO no exame.");
			} else {
				printf("REPROVADO no exame.");
			}
		}
	}

	return 0;
}
