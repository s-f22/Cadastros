/******************************************************************************
3) Crie uma função em C que receba por parâmetro dois vetores de números reais 
e um número inteiro que represente o tamanho destes vetores; a função deve 
calcular o chamado produto escalar de dois vetores. Este cálculo multiplica os 
valores correspondentes dos dois vetores, ou seja, A[0] multiplicado por 
B[0], A[1] por B[1], …. , até A[10] por B[10], e depois soma todos estes 
resultados parciais: (A[0] * B[0]) + (A[1] * B[1]) + (A[2] * B[2]) + … + (A[10] * B[10]). 
Pronto! A assinatura da função é assim: double produtoEscalar (double A[ ], double B[ ], int N).

*******************************************************************************/
#include <stdio.h>
double produtoEscalar (double A[ ], double B[ ], int N)
{   int i;
    double resp = 0;
    for(i=0; i<N; i++)
    {   resp = resp + A[i]*B[i];
    }
    return resp;
}
int main()
{   double a[]={3,4,5,6};
    double b[]={4,5,6,7};
    printf("%lf\n", produtoEscalar(a,b,4));
    return 0;
}
