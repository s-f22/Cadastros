#include<stdio.h>
#include<stdlib.h>
int * funcao()
{   int * vet = (int *) malloc(5 * sizeof(int));
    vet[0] = 1;
    vet[1] = 2;
    vet[2] = 3;
    vet[3] = 4;
    vet[4] = 5;
    return vet;
}

int main()
{   int *p;
    p = funcao();
    //Agora vai!!!
    printf("%d - %d - %d - %d - %d\n", p[0], p[1], p[2], p[3], p[4]);
    return 0;
}
