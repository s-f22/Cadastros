#include <stdio.h>

int main()
{
	float n1, n2, n3, p1, p2, p3, media;
	p1 = 1;
	p2 = 1;
	p3 = 2;
	
	printf("Insira o valor da primeira nota: ");
	scanf("%f", &n1);
	
	printf("Insira o valor da segunda nota: ");
	scanf("%f", &n2);
	
	printf("Insira o valor da terceira nota: ");
	scanf("%f", &n3);
	
	media = ((n1 * p1) + (n2 * p2) + (n3 * p3)) / (p1 + p2 + p3);
	
	printf("A media ponderada do aluno foi %.1f.\n", media);
	
	if(media >= 60)
	{
		printf("Aluno APROVADO.");
	}else{
		printf("Aluno REPROVADO.");
	}
		
	return 0;
}
