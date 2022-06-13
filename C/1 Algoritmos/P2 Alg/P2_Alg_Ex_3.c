/*

ALUNO: Samuel Figueiredo Silveira
CURSO: ADS Ipiranga, Noturno 1º Semestre
RA: 2040482113024

03 - Faça um algoritmo que armazene em um 
vetor 5x3 quer armazene a altura, peso de 
cada pessoa e na terceira coluna calcule o 
IMC  => PESO/(ALTURA X ALTURA) de cada 
individuo de uma família, ao final exiba 
quantos quilos cada pessoa deve perder para 
alcançar o IMC  25  (3,00)

*/

#include <stdio.h>

//DECLARAÇÃO DAS VARIAVEIS
int main()
{
    float infos[5][3];
    int i;
    int altura = 0;
    int peso = 1;
    int imc = 2;

    float pesoIdeal, dif_peso;

    //LAÇO PARA CARREGAR OS VALORES NA MATRIZ
    for (i = 0; i < 5; i++)
    {
        printf("\nInsira a altura da pessoa %i: ", i + 1);
        scanf("%f", &infos[i][altura]);

        printf("Insira o peso da pessoa %i: ", i + 1);
        scanf("%f", &infos[i][peso]);

        infos[i][imc] = infos[i][peso] / (infos[i][altura] * infos[i][altura]); // CALCULO DO IMC NA TERCEIRA COLUNA DE CADA LINHA / INICIO DO PROCESSAMENTO
    }
printf("\n-------------------------------------------\n");

// LAÇO PARA EXIBIR OS VALORES CALCULADOS/INFORMADOS, DE ACORDO COM AS CONDIÇÕES ABAIXO
    for (i = 0; i < 5; i++)
    {
        printf("\nIMC da pessoa %i: %.1f", (i + 1), infos[i][imc]);
        printf("\nPeso informado: %.1f Kgs", infos[i][peso]);

        pesoIdeal = 25 * (infos[i][altura] * infos[i][altura]);
        printf("\nPeso ideal: %.1f Kgs", pesoIdeal);

// ANALISE DAS CONDIÇÕES DE PESO IDEAL, CONFORME VALOR REFERENCIA DE 25
        if (infos[i][imc] > 25)
        {
            dif_peso = infos[i][peso] - pesoIdeal;
            if (dif_peso > 0 && dif_peso < 0.1f)
                printf("\nA pessoa %i esta em seu peso ideal\n", (i + 1));
            else
                printf("\nA pessoa %i precisa perder %.1f Kgs\n", (i + 1), dif_peso);
        }
        else
        {
            if (infos[i][imc] < 25)
            {
                dif_peso = pesoIdeal - infos[i][peso];
                if (dif_peso > 0 && dif_peso < 0.1f)
                    printf("\nA pessoa %i esta em seu peso ideal\n", (i + 1));
                else
                    printf("\nA pessoa %i precisa ganhar %.1f Kgs\n", (i + 1), dif_peso);
            }
        }
    }

    return 0;
}