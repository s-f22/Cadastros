#include <stdio.h>
#include <stdlib.h>

struct aviao{
    char nome[50]; //Nome do aviao
    char destino [50]; //Destino do voo
    int codigo; //codigo cia
    char cia[50]; //nome da cia aerea
    struct item *proximo;
};
typedef struct aviao item;

item *criaFila(){
    item *fila=(item*)malloc(sizeof(item));
    fila->proximo = NULL;
    return fila;
}

int filaVazia(item *p){
    if(p->proximo==NULL){
    return 1;
    } else {
    return 0;
    }
}

//colocaNaFila
//Adicionar um aviao na fila de espera
void queue(item *fila){
    item *novo=(item*)malloc(sizeof(item));
    printf("Informe o nome do aviao: ");
    scanf("%s", &novo->nome);

    printf("Informe o codigo: ");
    scanf("%i", &novo->codigo);

    printf("Informe a cia aerea: ");
    scanf("%s", &novo->cia);

    printf("Informe o destino: ");
    scanf("%s", &novo->destino);

    novo->proximo = NULL;

    if(filaVazia(fila)==1){
    fila->proximo=novo;
    } else {
        item *aux = fila->proximo;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = novo;    
    }
}

//Autorizar a decolagem do primeiro aviao da fila
//tiraDaFila
void unqueue(item *fila){
    if(filaVazia(fila) == 0){
        item *aux = fila->proximo;
        fila->proximo = aux->proximo;
        printf("Dados do aviao autorizado: \n Nome: %s. Codigo: %i. Cia: %s. Destino: %s \n", aux->nome, aux->codigo, aux->cia, aux->destino);
        free(aux);
    }
}

//Listar as caracteristicas do primeiro aviao da fila
void primeiro(item *fila){
    if(filaVazia(fila)==0){
        item *aux = fila->proximo;
        printf("Dados aviao (primeiro da fila): %s. Codigo: %i. Cia: %s. Destino: %s \n", aux->nome, aux->codigo, aux->cia, aux->destino);
    }
}

//Listar o numero de avioes aguardando na fila de decolagem
void mostrar(item *fila){
    item *aux = fila->proximo;
    while (aux != NULL){
        printf("Aviao: %s. Codigo: %i. Cia: %s. Destino: %s \n", aux->nome, aux->codigo, aux->cia, aux->destino);
        aux = aux->proximo;
    }
}

//Contar o numero de avioes aguardando na fila de decolagem
void contar(item *fila){
    int contador = 0;
    item *aux = fila->proximo;
    while(aux != NULL){
        contador++;
        aux = aux->proximo;
    }
    printf("Numero de Avioes na fila de espera : %i \n", contador);
}


int main(int menu, int opcao) {
    item *fila = criaFila();
    printf("Simulacao de controle de uma pista de decolagem");
    do
    {
        printf("\n-------------------------------------------------------------");

        printf("\n[1] Add um aviao na fila de espera\n");
        printf("[2] Mostrar os avioes aguardando na fila de espera\n");
        printf("[3] Autorizar a decolagem do primeiro aviao\n");
        printf("[4] Numero de avioes aguardando na fila de decolagem. \n");
        printf("[5] Dados do primeiro aviao da fila.");
        printf("\n\nInsira a opcao desejada: ");

        scanf("%i", &menu);

        switch(menu)
        {
            case 1: queue(fila); break;
            case 2: mostrar(fila); break;
            case 3: unqueue(fila); break;
            case 4: contar(fila); break;
            case 5: primeiro(fila); break;
            default: printf("Opcao Invalida\n"); break;
        }
        printf("Deseja continuar? [1] Sim [2] Nao:");
        scanf("%i", &opcao);
    }
    while(opcao == 1);
    return 0;
}
