/******************************************************************************
primeira pilha
*******************************************************************************/

#include <stdio.h>

struct itm{
    int numero;   
    struct itm *proximo; //endereço do proximo item   
} typedef item;

struct {
    item *topo;
} typedef pilha;

void push(pilha *p){
     printf("\nPUSH");  
    item *novo = (item*)malloc(sizeof(item));
    printf("\nInforme um valor:");
    scanf("%i", &novo->numero);
    printf("\n Novo elemento criado end %x", novo);
    novo->proximo = p->topo;
    p->topo = novo;
}

void pop(pilha *p){
    printf("\nPOP");  
    if(p->topo!=NULL) {
        item *atual = p->topo->proximo;
        printf("-elemento a ser removido %x ,\nproximo elemento %x", p->topo, p->topo->proximo);
        free(p->topo);
        p->topo = atual;
    } else {
        printf("-pilha vazia");  
    }
}

void mostrar(pilha *p){
    if(p->topo!=NULL) {
        printf("\nTopo da pilha %x, valor=%i", p->topo, 
        p->topo->numero);
    } else {
        printf("\npilha vazia");
    }
}


int main()
{
    pilha pilha1 = {NULL};
    
    
    push(&pilha1);
    mostrar(&pilha1);
    push(&pilha1);
    mostrar(&pilha1);
    pop(&pilha1);
    mostrar(&pilha1);
    
    push(&pilha1);
    mostrar(&pilha1);
    pop(&pilha1);
    mostrar(&pilha1);
    pop(&pilha1);
     pop(&pilha1);
       mostrar(&pilha1);
    return 0;
}
