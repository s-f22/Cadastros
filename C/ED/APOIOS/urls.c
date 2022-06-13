/*
Implemente uma pilha dinamica que simule o historico de navegacao de um browser, onde a cada pagina acessada uma nova
url e adicionada ao topo da pilha, implemente as seguintes funcoes:
a)adicionar nova url ao topo da pilha
b)mostrar url atual
c)voltar, removendo o topo da pilha
d)quantidade de urls adicionadas a pilha
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char historico[20];
    char dia[20];
    struct item *proximo; //elemento atual vai ter o endereco do proximo item.
} typedef item;

struct pilha {
    struct item *topo; //url que esta no topo da pilha
} typedef pilha;


pilha *criarPilha(){
    pilha *p = (pilha*)malloc(sizeof(pilha));
    p->topo = NULL;
    return p;
}

//adicionar nova url ao topo da pilha
void push(pilha *p){
    item *novo = (item*)malloc(sizeof(item)); //criar novo item

    printf("Informe a url: ");
    scanf("%s", &novo->historico);

    printf("Informe o dia de acesso (dd/mm/yyyy):");
    scanf("%s", &novo->dia);

    novo->proximo = NULL;
    //pilha vazia
    if(p->topo==NULL){
        p->topo = novo;
    }else{
        item *aux = p->topo;
        novo->proximo = aux;
        p->topo = novo;
    }
    printf("Nova url %s, %s => %x \n", novo->historico, novo->dia, novo);
}

//voltar, removendo o topo da pilha
void pop(pilha *p){
    if(p->topo==NULL){
        printf("Pilha vazia.\n");
    }else{
        printf("URL Removida: %s, Data de Acesso: %s => %x \n", p->topo->historico, p->topo->dia, p->topo);
        item *aux = p->topo->proximo;
        free(p->topo); //remove da memoria
        p->topo = aux;
    }
}

//mostrar url atual
void mostrar(pilha *p){
    printf("Topo do historico: %s, Data de Acesso: %s => %x \n", p->topo->historico, p->topo->dia, p->topo);
}

//quantidade de urls adicionadas a pilha
void contar(pilha *p){
    int contador = 1;
    if(p->topo==NULL){
        printf("Historico Vazio \n");
    }else{
        item*aux = p->topo;
        while(aux->proximo!=NULL){
            contador++;
            aux = aux->proximo;
        }
        printf("Total de URLs: %i\n", contador);
    }
}


int main(int menu, int opcao) {
    pilha *p = criarPilha();
    printf("**Simulacao do Historico de Navegacao**");

    do
    {
        printf("\n------------------------------------------------------------------");
        printf("\n[1] Adicionar uma url: \n");
        printf("[2] URL Atual: \n");
        printf("[3] Remover ultima url: \n");
        printf("[4] Quantidade de urls: \n");
        printf("\nInsira a opcao desejada: ");
        scanf("%i", &menu);

        switch(menu){
            case 1: push(p); break;
            case 2: mostrar(p); break;
            case 3: pop(p); break;
            case 4: contar(p); break;
            default: printf("Opcao Invalida\n"); break;
        }
        printf("\n\nDeseja continuar? [1] Sim [2] Nao: ");
        scanf("%i", &opcao);
    }while(opcao == 1);

    return 0;
}