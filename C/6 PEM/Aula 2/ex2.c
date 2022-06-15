#include <stdio.h>

int main()
{
    int tam = 1;
    int maior = 1;
    int vetor[8]; // vetor para 9 numeros
    int j = 0;

    do
    {
        printf("digite um numero da sequencia: ");
        scanf("%i", &vetor[j]);
        j++;

    } while (j < 9);

    j = 0;

    while (j < 9)
    {
        if (vetor[j + 1] > vetor[j])
        {
            tam++;
        }
        else
        {
            tam = 1;
        }

        if (tam > maior)
        {
            maior = tam;
        }

        j++;
    }
    printf("maior sequencia digitada = %d\n", maior);

    return 0;
}