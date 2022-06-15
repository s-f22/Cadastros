/*
ALUNO: Samuel Figueiredo

Instruções
2-Implemente uma lista duplamente encadeada para simular uma rede social
de pessoas conhecidas, implemente todas as funções

typedef struct pessoa {
  char[30] nome;
  struct pessoa *ant;
  struct pessoa *prox;
} Pessoa;

*/

#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

struct pessoa
{
    char nome[30];
    struct pessoa *anterior;
    struct pessoa *proximo;
};
// transformando o struct pessoa em ListaTipoPessoa
typedef struct pessoa ListaTipoPessoa;

ListaTipoPessoa *criaLista()
{
    ListaTipoPessoa *lista = (ListaTipoPessoa *)malloc(sizeof(ListaTipoPessoa)); // ponteiro e um end na memoria
    lista->proximo = NULL;
    return lista;
}

int listaVazia(ListaTipoPessoa *p)
{
    if (p->proximo == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void colocaNaLista(ListaTipoPessoa *lista)
{
    ListaTipoPessoa *novo = (ListaTipoPessoa *)malloc(sizeof(ListaTipoPessoa));
    printf("Informe um nome:");
    scanf("%s", &novo->nome);
    novo->proximo = NULL;
    novo->anterior = NULL;

    if (listaVazia(lista) == 1)
    {
        lista->proximo = novo;
        novo->anterior = lista;
    }
    else
    {
        ListaTipoPessoa *temp = lista->proximo;
        while (temp->proximo != NULL)
        {
            temp = temp->proximo;
        }
        temp->proximo = novo;
        novo->anterior = temp;
    }
}

void colocaInicioLista(ListaTipoPessoa *lista)
{
    ListaTipoPessoa *novo = (ListaTipoPessoa *)malloc(sizeof(ListaTipoPessoa));
    printf("Informe um nome:");
    scanf("%s", &novo->nome);
    novo->proximo = NULL;
    novo->anterior = lista;

    if (listaVazia(lista) == 1)
    {
        lista->proximo = novo;
    }
    else
    {
        // atualiza o proximo elemento do ListaTipoPessoa recem criado com o primeiro atual
        novo->proximo = lista->proximo;
        // atualizou o endereco do primeito atual com endereco do novo
        lista->proximo->anterior = novo;
        lista->proximo = novo;
    }
}

void removerLista(ListaTipoPessoa *lista, char nome)
{
    if (listaVazia(lista) == 0)
    {
        ListaTipoPessoa *temp = lista->proximo; // end do primeiro ListaTipoPessoa associado
        ListaTipoPessoa *anterior = lista;      
        while (temp != NULL)
        {
            if (temp->nome == nome)
            {
                anterior->proximo = temp->proximo;
                temp->proximo->anterior = anterior;
                printf("Item Removido %x %i \n", temp, temp->nome);
                free(temp);
                break;
            }
            else
            {
                anterior = temp;
                temp = temp->proximo;
            }
        }
    }
}

void exibe(ListaTipoPessoa *lista)
{
    ListaTipoPessoa *temp = lista->proximo;
    while (temp != NULL)
    {
        printf("Pessoa %x %s Ant=%x prox=%x \n", temp, temp->nome, temp->anterior, temp->proximo);
        temp = temp->proximo;
    }
}

void total(ListaTipoPessoa *lista)
{
    int comprimento = 0;
    ListaTipoPessoa *temp = lista->proximo;
    while (temp != NULL)
    {
        comprimento++;
        temp = temp->proximo;
    }
    printf("Total de pessoas : %i \n", comprimento);
}

int main(int argc, char *argv[])
{
    // vai cria end. inicial da final cabe?da fila
    ListaTipoPessoa *lista = criaLista();
    colocaNaLista(lista);
    colocaNaLista(lista);
    colocaNaLista(lista);
    colocaInicioLista(lista);
    exibe(lista);
    total(lista);
    removerLista(lista, "ana");
    exibe(lista);
    removerLista(lista, "jose");
    total(lista);

    return 0;
}
