/*


Instru��es
7. Dadas duas sequ�ncias com n n�meros inteiros entre 0 e 9, 
interpretadas como dois n�meros inteiros de n algarismos, 
calcular a sequ�ncia de n�meros que representa a soma dos dois inteiros.
Exemplo: n = 8,
1� sequ�ncia 8 2 4 3 4 2 5 1
2� sequ�ncia 3 3 7 5 2 3 3 7  +
        -----------------------
           1 1 6 1 8 6 5 8 8

*/

#include <stdio.h>

int main()
{
    int i, qtde = 0, vai_um = 0;

    printf("\nInsira a qtde de numeros para as duas sequencias: ");
    scanf("%i", &qtde);
    qtde -= 1;

    int seq_A[qtde], seq_B[qtde], result[qtde + 1];

    printf("\nPRIMEIRA SEQUENCIA: \n");

    for (i = 0; i <= qtde; i++)
    {
        printf("Insira um numero: ");
        scanf("%i", &seq_A[i]);
    }

    printf("\nSEGUNDA SEQUENCIA: \n");

    for (i = 0; i <= qtde; i++)
    {
        printf("Insira um numero: ");
        scanf("%i", &seq_B[i]);
    }

    printf("\nO numero correspondente a primeira sequencia digitada foi: ");
    for (i = qtde; i >= 0; i--)
    {
        printf("%i ", seq_A[i]);
    }

    printf("\nO numero correspondente a segunda sequencia digitada foi: ");
    for (i = qtde; i >= 0; i--)
    {
        printf("%i ", seq_B[i]);
    }

    for (i = 0; i <= qtde; i++)
    {
        result[i] = seq_A[i] + seq_B[i];

        if (vai_um == 1)
        {
            result[i] += 1;
        }

        if (result[i] > 9)
        {
            result[i] = result[i] - 10;
            vai_um = 1;
        }
        else
        {
            vai_um = 0;
        }
    }

    int tam_result = sizeof(result) / sizeof(result[0]); // Atribui o tamanho do vetor 'result' � variavel tam_result

    if (vai_um == 1) // verifica se a ultima soma foi maior q 10
    {
        result[tam_result] = 1;
    }

    printf("\nSoma correspondente a esses dois numeros: ");
    
    for (i = tam_result; i >= 0; i--)
    {
        printf("%i ", result[i]);
    }

    return 0;
}

