/*
Aluno: Samuel Figueiredo

1-Implemente todos os metodos de uma pilha (push, pop e topo) de um TAD chamado caixa{codigo, peso, proximo} 

*/

#include <stdio.h>
#include <stdlib.h>

struct itm{
    int codigo;
    float peso;
    struct itm *proximo;   
} typedef caixa;

struct {
    caixa *topo;
} typedef pilha;

void push(pilha *p){
    printf("PUSH ");  
    caixa *novo = (caixa*)malloc(sizeof(caixa));
    printf("\nInforme numero inteiro para o codigo: ");
    scanf("%i", &novo->codigo);
    printf("Informe um valor para o peso: ");
    scanf("%f", &novo->peso);
    printf("\nNovo elemento criado. Endereco: %p\n", novo);
    novo->proximo = p->topo;
    p->topo = novo;
}

void pop(pilha *p){
    printf("POP");  
    if(p->topo!=NULL) {
        caixa *atual = p->topo->proximo;
        printf("\nElemento a ser removido %p; \nProximo elemento %p\n\n", p->topo, p->topo->proximo);
        free(p->topo);
        p->topo = atual;
    } else {
        printf("\nPilha vazia");  
    }
}

void mostrar(pilha *p){
    if(p->topo!=NULL) {
        printf("Topo da pilha: %p\nCodigo: %i; Peso: %.2f\n\n", p->topo, 
        p->topo->codigo, p->topo->peso);
    } else {
        printf("\nNao ha elementos na pilha.");
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



