/*

ALUNO: Samuel Figueiredo Silveira
ADS Ipiranga Noturno, 1ºSemestre

2-Crie uma tabela de um campeonato de futebol, com 10 times e 4 colunas

Na coluna 0 e o total de vitorias (multiplique por 3 pontos)
Na coluna 1 o total de empates (multiplique por 1 ponto)
Na coluna 2 o total de derrotas (multiplique por 0 pontos)
Na coluna 3 , calcule o total de pontos
Mostre ao final, o três primeiros colocados da tabela

*/

#include <stdio.h>

int main()
{
    int tabela[10][4];
    int i, j, vitorias, empates, derrotas;
    int primeiro, segundo, terceiro = 0;
    int s;
    int a, b, c = 0;

    printf("\nTABELA GERAL DE TIMES\n\n");

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j == 0)
            {
                printf("Insira o total de vitorias do time %i: ", i + 1);
                scanf("%i", &tabela[i][j]);

                tabela[i][j] = tabela[i][j] * 3;
            }

            if (j == 1)
            {
                printf("Insira o total de empates do time %i: ", i + 1);
                scanf("%i", &tabela[i][j]);

                tabela[i][j] = tabela[i][j] * 1;
            }

            if (j == 2)
            {
                printf("Insira o total de derrotas do time %i: ", i + 1);
                scanf("%i", &tabela[i][j]);

                tabela[i][j] = tabela[i][j] * 0;
            }

            tabela[i][3] = tabela[i][0] + tabela[i][1] + tabela[i][2];
        }
    }

    for (s = 0; s < 10; s++)
    {
        if (s == 0)
            primeiro = tabela[s][3];

        if (tabela[s][3] > primeiro)
        {
            primeiro = tabela[s][3];
            a = s;
        }
    }

    for (s = 0; s < 10; s++)
    {
        if (s == 0 && s != a)
            segundo = tabela[s][3];

        if (tabela[s][3] > segundo && tabela[s][3] != primeiro)
        {
            segundo = tabela[s][3];
            b = s;
        }
    }

    for (s = 0; s < 10; s++)
    {
        if (s == 0 && s != a && s != b)
            terceiro = tabela[s][3];

        if (tabela[s][3] > terceiro && tabela[s][3] != primeiro && tabela[s][3] != segundo)
        {
            terceiro = tabela[s][3];
            c = s;
        }
    }

    printf("\nResultados: \n\n");
    printf("1o colocado: Time %i (%i pontos);\n", a + 1, tabela[a][3]);
    printf("2o colocado: Time %i (%i pontos);\n", b + 1, tabela[b][3]);
    printf("3o colocado: Time %i (%i pontos);\n", c + 1, tabela[c][3]);

    return 0;
}
