/*

ALUNO: Samuel Figueiredo Silveira
ADS Ipiranga Noturno, 1ºSemestre

1- Crie um programa que controle uma lista de inscritos em um vestibular, armazene 
em uma matriz 10x3 os seguintes dados: primeira coluna : cpf do inscrito , segunda 
coluna: idade do inscrito, terceira coluna: curso escolhido 1-ADS 2-GECOM 3-Eventos 4-RH

somente insira a linha da matriz caso o CPF não tenha sido cadastrado anteriormente
Exiba ao  final a quantidade de inscritos de cada curso
Mostre a media de idade dos inscritos
Caso ja exista um cpf, mostre a mensagem CPF ja cadastrado registro não inserido

*/

#include <stdio.h>

int main()
{
    int dados[10][3];
    int cpf, media_idade, j;
    int ads, gecom, eventos, rh = 0;
    int flag = 0;
    int i = 0;

    printf("\nCADASTRO VESTIBULAR");

    do
    {
        printf("\n%io aluno", i + 1);
        printf("\nInsira o CPF do candidato: ");
        scanf("%i", &cpf);

        for (j = 0; j < 10; j++)
        {
            if (cpf == dados[j][0])
            {
                printf("\nEste CPF ja possui cadastro.\n\n");
                flag = 1;
                break;
            }
            else
                flag = 0;
        }

        if (flag == 0)
        {
            dados[i][0] = cpf;

            printf("Insira a idade do candidato: ");
            scanf("%i", &dados[i][1]);

            printf("Insira o curso escolhido: (1-ADS; 2-GECOM; 3-EVENTOS; 4-RH;)");
            scanf("%i", &dados[i][2]);

            i++;
        }

    } while (i < 10);

    for (i = 0; i < 10; i++)
    {
        if (dados[i][2] == 1)
            ads++;
        if (dados[i][2] == 2)
            gecom++;
        if (dados[i][2] == 3)
            eventos++;
        if (dados[i][2] == 4)
            rh++;
    }

    printf("\n\nForam matriculados %i alunos de ADS, %i de GECOM, %i de Eventos e %i de RH.\n", ads, gecom, eventos, rh);

    for (i = 0; i < 10; i++)
    {
        media_idade += dados[i][1];
    }

    media_idade = media_idade / 10;
    printf("Media de idade entre os alunos inscritos: %i\n", media_idade);

    return 0;
}