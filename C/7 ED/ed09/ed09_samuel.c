/*
Aluno: Samuel Figueiredo
ed09

Instruções
1- O que é uma árvore binária e quais seus componentes?
As árvores são estruturas de dados baseadas em listas encadeadas que possuem um nó superior 
também chamado de raiz que aponta para outros nós, chamados de nós filhos, que podem ser pais 
de outros nós. Os elementos de uma árvore são: Nós – são todos os itens guardados na árvore; 
Raiz – é o nó do topo da árvore ; Filhos – são os nós que vem depois dos outros nós; Pais – 
são os nós que vem antes dos outros nós; Folhas – são os nós que não têm filhos; são os últimos 
nós da árvore 

2-Qual a diferença entre uma AB e uma ABB ?
Em uma arvore binaria simples (AB), os registros serão chamados nós. Cada nó tem um endereço e
 três campos: um valor e dois ponteiros para nós;
Uma árvore binária de busca (ABB) também é uma estrutura de dados baseada em nós. No entanto, 
todos os nós da sub-árvore esquerda possuem um valor numérico inferior ao nó raiz, e todos os 
nós da sub-árvore direita possuem um valor superior ao nó raiz, estruturando assim seus dados 
de forma flexivel. 


3-Usando o primeiro exemplo de  AB implemente uma função para contar a altura de uma arvore

*/

#include <stdio.h>
#include <stdlib.h>

/***************** Arvore.h *********************/

typedef struct _no
{
    int info;
    struct _no *esq;
    struct _no *dir;
} no;


typedef struct
{
    no *raiz;
} arvore;



/*Cria um no em uma arvore!*/
void inserir(arvore *a, int v)
{
    no *novo = (no *)malloc(sizeof(no));
    novo->info = v;
    novo->dir = NULL;
    novo->esq = NULL;

    printf("\nADICIONANDO %i %x", v, novo);

    if (a->raiz == NULL)
    {
        a->raiz = novo;
    }
    else
    {
        no *aux = a->raiz;
        while (aux != NULL)
        {
            if (novo->info > aux->info)
            {
                printf("->");
                // direita
                if (aux->dir == NULL)
                {
                    aux->dir = novo;
                    break;
                }
                else
                {
                    aux = aux->dir;
                }
            }
            else
            {
                printf("<-");
                // esquerda
                if (aux->esq == NULL)
                {
                    aux->esq = novo;
                    break;
                }
                else
                {
                    aux = aux->esq;
                }
            }
        }
    }
}

/*Cria um no em uma arvore!*/
void remover(arvore *a, int valor)
{
    printf("\nREMOVENDO %i", valor);
    if (a->raiz == NULL)
    {
        printf("Arvore vazia !!");
    }
    else
    {
        no *aux = a->raiz;
        no *anterior = NULL;

        while (aux != NULL)
        {
            if (valor == aux->info)
            {
                printf("item removido !");
                free(aux);
                break;
            }
            else
            {
                anterior = aux;
                if (valor > aux->info)
                {
                    printf("->"); // direita
                    aux = aux->dir;
                }
                else
                {
                    printf("<-"); // esquerda
                    aux = aux->esq;
                }
            }
        }
        if (anterior != NULL && valor > anterior->info)
        {
            anterior->dir = NULL;
        }
        else
        {
            anterior->esq = NULL;
        }
    }
}

int altura(arvore *a){
    if(a->raiz == NULL){
        return -1;
    }
    else{
        int esq = altura(a->raiz->esq);
        int dir = altura(a->raiz->dir);
        if(esq > dir)
            return esq + 1;
        else
            return dir + 1;
    }
}

/****************** Prog.c **********************/

int main()
{

    arvore a = {NULL};

    inserir(&a, 50);
    inserir(&a, 30);
    inserir(&a, 90);
    inserir(&a, 20);
    inserir(&a, 40);
    inserir(&a, 95);
    inserir(&a, 10);
    inserir(&a, 35);
    inserir(&a, 45);
    int h = altura(&a);
    printf("\nAltura h: %i", h);
    remover(&a, 10);
    remover(&a, 199);
    remover(&a, 45);
    return 0;
}