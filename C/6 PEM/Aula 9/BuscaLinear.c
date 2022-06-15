/******************************************************************************
10) Crie uma função recursiva que procure um número
dentro de um vetor, a partir de um dado índice. Se
achar o mesmo, o metodo retorna o índice onde ele
se encontra, senão, retorna -1 (busca linear
recursiva).

-> Só para entendermos melhor o problema, a versão
interativa (não-recursiva) seria assim:

	int busca(int vet[ ], int N, int indiceInicio, int procurado)
	{	int i;
		for(i=indiceInicio; i < N; i++)
		{	if(procurado == vet[i])
			{	return i;
			}
		}
		return -1;
	}

	Agora vamos pensar na versão recursiva....
*******************************************************************************/
#include <stdio.h>
int busca(int vet[ ], int N, int indiceInicio, int procurado)
{	int i;
	for(i=indiceInicio; i < N; i++)
	{	if(procurado == vet[i])
		{	return i;
		}
	}
	return -1;
}
int buscaRec(int vet[ ], int N, int indiceInicio, int procurado)
{   if(indiceInicio>=N) return -1;
    else if(vet[indiceInicio]==procurado) return indiceInicio;
    else return buscaRec(vet, N, indiceInicio+1, procurado);
}
int main()
{   int vet[] = {5,8,2,4,9,3,7,1,20,15,6};
    printf("Buscando o elemento 1: %d\n", busca(vet, 11, 0, 1));
    printf("Buscando o elemento 15: %d\n", busca(vet, 11, 0, 15));
    printf("Buscando o elemento 12: %d\n", busca(vet, 11, 0, 12));
    printf("Buscando (rec.) o elemento 1: %d\n", buscaRec(vet, 11, 0, 1));
    printf("Buscando (rec.) o elemento 15: %d\n", buscaRec(vet, 11, 0, 15));
    printf("Buscando (rec.) o elemento 12: %d\n", buscaRec(vet, 11, 0, 12));
    return 0;
}


