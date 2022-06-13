#include <stdio.h>
#include <stdlib.h>

struct cliente {
    char nome[50];
    char cnpj[20];
};

typedef struct cliente CLIENTE;

int main()
{   int N = 1, fichas = 0, i;
    CLIENTE *cadastro = (CLIENTE *) malloc(N*sizeof(CLIENTE)); //semelhante a CLIENTE cadastro[N];

    for(i=0; i<10; i++)
    {   if(fichas>=N) //estourei o vetor
        {   N = N*2;
            cadastro = (CLIENTE *) realloc(cadastro, N * sizeof(CLIENTE));
            printf("Armazenamento redimensionado para %d fichas\n", N);
        }
        
        printf("Entre com o nome: ");
        fgets(cadastro[fichas].nome, 50, stdin);
        printf("Entre com o CNPJ: ");
        fgets(cadastro[fichas].cnpj, 20, stdin);
        fichas++;
    }
    
    for(i=0; i<10; i++)
    {   printf("%d) Nome: %s", i+1, cadastro[i].nome);
        printf("   CNPJ: %s", cadastro[i].cnpj);
    }
    return 0;
}


