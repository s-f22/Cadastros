/******************************************************************************
6. Dados dois números naturais m e n e duas sequências
ordenadas com m e n números inteiros, obter uma única
sequência ordenada contendo todos os elementos das
sequências originais sem repetição.
Sugestão: Imagine uma situação real, por exemplo, dois
fichários de uma biblioteca.
Exemplo: 
Sequência 1:  1, 1, 2, 3, 4, 8, 9
Sequência 2:  1, 3, 5, 7, 10
Sequência gerada:
1, 1, 1, 2, 3, 3, 4, 5, 7, 8, 9, 10 (+ fácil)
Sequência gerada (sem repetição):
1, 2, 3, 4, 5, 7, 8, 9, 10
*******************************************************************************/
#include <stdio.h>
int main()
{
    int seq1[] = {1, 1, 2, 3, 4, 8, 9}, N1 = 7;
    int seq2[] = {1, 3, 5, 7, 10}, N2 = 5;
    int N3 = N1 + N2;
    int seq3[N3];
    int seq4[N3];
    int i1 = 0, i2 = 0, i3 = 0, i4;
    while (i3 < N3)
    {
        if (i1 < N1 && i2 < N2) //há elementos nas duas seq.
        {
            if (seq1[i1] < seq2[i2])
            {
                seq3[i3] = seq1[i1];
                i1++;
            }
            else
            {
                seq3[i3] = seq2[i2];
                i2++;
            }
        }
        else if (i1 < N1) //só tem elem. na seq1
        {
            seq3[i3] = seq1[i1];
            i1++;
        }
        else //só tem elem. na seq2
        {
            seq3[i3] = seq2[i2];
            i2++;
        }
        printf("%d ", seq3[i3]);
        i3++;
    }
    seq4[0] = seq3[0];
    printf("\n%d ", seq4[0]);
    i4 = 1;
    for (i3 = 1; i3 < N3; i3++)
    {
        if (seq3[i3] != seq4[i4 - 1])
        {
            seq4[i4] = seq3[i3];
            printf("%d ", seq4[i4]);
            i4++;
        }
    }

    return 0;
}
