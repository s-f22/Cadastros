#include <stdio.h>

int main()
{
	float p1, p2, p3, faltas, mediaA, mediaB, percFaltas;
	
	printf("Insira as notas P1, P2 e a quantidade de faltas: \n");
	scanf("%f %f %f", &p1, &p2, &faltas);
	
	mediaA = (p1 + p2) / 2;
	percFaltas = faltas / 20;
		
	if (percFaltas > 0.3f)
	{
		printf("Aluno REPROVADO por %.0f faltas. \n", faltas);
	} else {
		if (mediaA >= 6)
		{
			printf("Aluno APROVADO com media %.1f. \n", mediaA);
			printf("Percentual de faltas: %.2f", percFaltas);
		} else {
			printf("Insira a nota P3 do exame: \n");
			scanf("%f", &p3);
			mediaB = (p1 + p2 + p3) / 3;
			if (mediaB >= 6)
			{
				printf("Aluno APROVADO no exame com media final %.1f. \n", mediaB);
				printf("Percentual de faltas: %.2f", percFaltas);
			} else {
				printf("Aluno REPROVADO no exame com media final %.1f. \n", mediaB);
				printf("Percentual de faltas: %.2f", percFaltas);
			}
		}
	}

	return 0;
}
