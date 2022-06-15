/*



02 - Faça um programa que controle e 
armazene em um vetor a entrada de índice
de transito de hora em hora, ao final 
do dia exiba a media, menor e maior índice 
em km (2,5)

*/

#include <stdio.h>

int main()
{

//DECLAÇÃO DAS VARIAVEIS
    float vetor[24];
    float maior, menor;

    float media;
    int i, j;

    printf("\nINSIRA ABAIXO O INDICE DE TRANSITO DE CADA HORA (em KMs):\n\n");

//ESTRUTURA DE REPETIÇÃO PARA CAPTURAR OS VALORES DE INDICE A SEREM ANALISADOS
    for (i = 0; i < 24; i++)
    {
        printf("%io indice: ", i + 1);
        scanf("%f", &vetor[i]);

        media += vetor[i]; //INCREMENTO DO VALOR DA MEDIA
        
//INICIO DO PROCESSAMENTO, COM CONDIÇÕES PARA VERIFICAR O MAIOR E MENOR VALORES
        if (i == 0)
        {
            maior = vetor[i];
            menor = vetor[i];
        }
        else
        {
            if (vetor[i] > maior) maior = vetor[i];
            else
            {
                if (vetor[i] < menor) menor = vetor[i];
            }
        }
    }

    media = media / 24; // CALCULO DA MEDIA

// DEVOLUÇÃO DOS RESULTADOS
    printf("\nMedia dos indices: %.1f KMs", media);
    printf("\nMaior indice: %.1f KMs \nMenor indice: %.1f KMs", maior, menor);

    return 0;
}