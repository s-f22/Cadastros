/*
Aluno: Samuel Figueiredo
P1 ED



EX-3 - Implemente uma pilha dinâmica que simule o controle do historico de navagação de um browser, 
onde a cada pagina navegada e adicionada ao topo da pilha, implemente as seguintes funções (2,0):

    adicionar um nova pagina no historico

    mostrar a ultima página pesquisada

    implementar o metodo voltar, removendo o topo atual

    TAD Sugerido (codigo int, URL char(100))

*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char url[100];
    int codigo;
    struct item *proximo; 
} typedef item;

struct pilha {
    struct item *topo; 
} typedef pilha;


pilha *criarPilha(){
    pilha *p = (pilha*)malloc(sizeof(pilha));
    p->topo = NULL;
    return p;
}


void push(pilha *p){
    item *novo = (item*)malloc(sizeof(item)); 

    printf("Informe a url: ");
    scanf("%s", &novo->url);

    printf("Informe o codigo de acesso:");
    scanf("%i", &novo->codigo);

    novo->proximo = NULL;
    //pilha vazia
    if(p->topo==NULL){
        p->topo = novo;
    }else{
        item *aux = p->topo;
        novo->proximo = aux;
        p->topo = novo;
    }
    printf("Nova url %s, %i => %x \n", novo->url, novo->codigo, novo);
}


void pop(pilha *p){
    if(p->topo==NULL){
        printf("Pilha vazia.\n");
    }else{
        printf("URL Removida: %s, Codigo: %i => %x \n", p->topo->url, p->topo->codigo, p->topo);
        item *aux = p->topo->proximo;
        free(p->topo); 
        p->topo = aux;
    }
}


void mostrar(pilha *p){
    if(p->topo==NULL){
        printf("Pilha vazia.\n");
    }else{
        printf("Topo do url: %s, Codigo: %i => %x \n", p->topo->url, p->topo->codigo, p->topo);
    }
}


void contar(pilha *p){
    int contador = 1;
    if(p->topo==NULL){
        printf("url vazia \n");
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
    printf("Historico de URLs");

    do
    {
        printf("\n--------------------------------------------------------");
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
