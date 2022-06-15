#include<stdio.h>
int main()
{	int vet[5] = {7, 2, 4, 9, 6};
	printf("Imprimindo o endereco de vet[0] = %u\n", &vet[0]);
	printf("Imprimindo o endereco de vet[1] = %u\n", &vet[1]);
	printf("Imprimindo o endereco de vet[2] = %u\n", &vet[2]);
	printf("Imprimindo o endereco de vet[3] = %u\n", &vet[3]);
	printf("Imprimindo o endereco de vet[4] = %u\n", &vet[4]);
	printf("Imprimindo o simplesmente o valor da variavel vet = %u\n", vet);

	double vet2[5] = {7, 2, 4, 9, 6};
	printf("Imprimindo o endereco de vet2[0] = %u\n", &vet2[0]);
	printf("Imprimindo o endereco de vet2[1] = %u\n", &vet2[1]);
	printf("Imprimindo o endereco de vet2[2] = %u\n", &vet2[2]);
	printf("Imprimindo o endereco de vet2[3] = %u\n", &vet2[3]);
	printf("Imprimindo o endereco de vet2[4] = %u\n", &vet2[4]);
	printf("Imprimindo o simplesmente o valor da variavel vet2 = %u\n", vet2);

	char vet3[5] = {'a', 'b', 'c', 'd', 'e'};
	printf("Imprimindo o endereco de vet3[0] = %u\n", &vet3[0]);
	printf("Imprimindo o endereco de vet3[1] = %u\n", &vet3[1]);
	printf("Imprimindo o endereco de vet3[2] = %u\n", &vet3[2]);
	printf("Imprimindo o endereco de vet3[3] = %u\n", &vet3[3]);
	printf("Imprimindo o endereco de vet3[4] = %u\n", &vet3[4]);
	printf("Imprimindo o simplesmente o valor da variavel vet3 = %u\n", vet3);
	return 0;
}


