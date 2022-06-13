/******************************************************************************
3) Crie uma fun��o em C que receba por par�metro dois vetores de n�meros reais 
e um n�mero inteiro que represente o tamanho destes vetores; a fun��o deve 
calcular o chamado produto escalar de dois vetores. Este c�lculo multiplica os 
valores correspondentes dos dois vetores, ou seja, A[0] multiplicado por 
B[0], A[1] por B[1], �. , at� A[10] por B[10], e depois soma todos estes 
resultados parciais: (A[0] * B[0]) + (A[1] * B[1]) + (A[2] * B[2]) + � + (A[10] * B[10]). 
Pronto! A assinatura da fun��o � assim: double produtoEscalar (double A[ ], double B[ ], int N).

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
