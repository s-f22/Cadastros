#include <stdio.h>

int main() 
{
	float indiceP;
	
	printf("Informe o indice de poluicao: \n");
	scanf("%f", &indiceP);
	
	if (indiceP >= 0.05f && indiceP <=0.25f )
	{
		printf("indice de poluicao ACEITAVEL");
	}
	
	if (indiceP >= 0.3f)
	{
		printf("Industrias do grupo 1: PARAR atividades.\n");
	 if (indiceP >= 0.4f) {
			printf("Industrias do grupo 2: PARAR atividades.\n");
		 if (indiceP >= 0.5f) {
				printf("Industrias do grupo 3: PARAR atividades.\n");
			}
		}
	}
	return 0;
}
