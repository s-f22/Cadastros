/*



Obs. Até 1 ponto na nota p2

Crie um jogo de batalha naval, onde haverá as seguintes opções:

Criar campo de batalha
Jogar
Resultado
Sair
O campo de batalha sera composto por uma matriz 10x10
Ao criar o campo de batalha o primeiro jogador, terá 10 jogadas 
para definir as posições(linha e coluna) onde:(1-Para fragata 
2- para destróier e 3 - para submarino)
Ao escolher Jogar, o segundo jogador terá 10 jogadas, 
para dar o palpite das posições(linha e coluna) onde a 
cada posições que não for ZERO sera informado que este 
acertou e será sumarizado os pontos.
Ao escolher a opção 3 será exibido o total de pontos.

*/

#include <stdio.h>

int main()
{
    int opcao, i, j;
    int campoBatalha[10][10];
    int pontos = 0;
    int jogada = 1;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            campoBatalha[i][j] = 0;
        }
    }

    int linha, coluna;

    do
    {
        printf("\n---------MENU PRINCIPAL---------");

        printf("\nInsira:\n \n1 - Criar campo de batalha; \n2 - Jogar; \n3 - Resultado; \n4 - Sair\n");

        scanf("%i", &opcao);

        switch (opcao)
        {
        	
        case 1:
           
            do
            {
                if (jogada <= 4)
                {
                    printf("\n%i JOGADA\nInsira o par das primeiras coordenadas (linha/coluna) de fragata: ", jogada);
                    scanf("%i %i", &linha, &coluna);

                    campoBatalha[linha - 1][coluna - 1] = 1;
                }
                else
                {
                    if (jogada > 4 && jogada <= 7)
                    {
                        printf("\n%i JOGADA\nInsira o par de coordenadas (linha/coluna) dos destroyers: ", jogada);
                        scanf("%i %i", &linha, &coluna);

                        campoBatalha[linha - 1][coluna - 1] = 1;
                    }
                    else
                    {
                        if (jogada > 7 && jogada <= 10)
                        {
                            printf("\n%i JOGADA\nInsira o par de coordenadas (linha/coluna) dos submarinos: ", jogada);
                            scanf("%i %i", &linha, &coluna);

                            campoBatalha[linha - 1][coluna - 1] = 1;
                        }
                    }
                }

                jogada++;

            } while (jogada <= 10);

            jogada = 1;

            for (i = 0; i < 10; i++)
            {
                for (j = 0; j < 10; j++)
                {
                    if (i == 0 && j == 0)
                        printf("\nSeu campo de batalha ficou assim: \n\n");
                    printf("%i", campoBatalha[i][j]);

                    if (j == 9)
                        printf("\n");
                }
            }

            break;

        case 2:

            do
            {
                printf("\n%i JOGADA\nInsira o par das primeiras coordenadas (linha/coluna): ", jogada);
                scanf("%i %i", &linha, &coluna);

                if (campoBatalha[linha - 1][coluna - 1] == 1)
                {
                    printf("Belo tiro, acertou o alvo!\n");
                    pontos++;
                }

                jogada++;

            } while (jogada <= 10);

            jogada = 1;
            break;

        case 3:
            printf("\nRESULTADO:\n\nVoce fez %i pontos!\n", pontos);
            break;

        case 4:
            printf("\nAte logo!!!");
            break;

        default:
            printf("Opcao invalida.");
            break;
        }

    } while (opcao != 4);
}
