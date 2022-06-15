/*
Implemente uma fila dinâmica em um programa que simule o controle de uma pista de decolagem de aviões em um aeroporto.
Neste programa, o usuário deve ser capaz de realizar as seguintes tarefas:
a) Listar o número de aviões aguardando na fila de decolagem;
b) Autorizar a decolagem do primeiro avião da fila;
c) Adicionar um avião à fila de espera;
d) Listar todos os aviões na fila de espera;
e) Listar as características do primeiro avião da fila.
Considere que os aviões possuem um nome e um número inteiro como identificador. Adicione outras características conforme
achar necessário.
*/


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
    //printf("\nFila vazia\n\n");
    return 1;
    } else {
        return 0;
    }
}

//Adicionar um aviao na fila de espera
void colocarNaFila(item *fila){
    item *novo=(item*)malloc(sizeof(item));
    printf("\nInforme o nome do aviao: ");
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
void retirarDaFila(item *fila){
    if(filaVazia(fila) == 0){
        item *aux = fila->proximo;
        fila->proximo = aux->proximo;
        printf("Dados do aviao autorizado: \n Nome: %s. Codigo: %i. Cia: %s. Destino: %s \n", aux->nome, aux->codigo, aux->cia, aux->destino);
        free(aux);
    }
    /*
    else{
        printf("\nFila Vazia\n");
    }
    */
    //equivalente ao else, acima
    if(filaVazia(fila) == 1)
        printf("\nFila vazia\n\n");
    
}

//Listar as caracteristicas do primeiro aviao da fila
void primeiro(item *fila){
    if(filaVazia(fila)==0){
        item *aux = fila->proximo;
        printf("\nDados do primeiro aviao na fila: Nome: %s Codigo: %i. Cia: %s. Destino: %s \n", aux->nome, aux->codigo, aux->cia, aux->destino);
    }
    if(filaVazia(fila) == 1)
        printf("\nFila vazia\n\n");
}

//Listar o numero de avioes aguardando na fila de decolagem
void mostrar(item *fila){
    if(filaVazia(fila) == 0){
        item *aux = fila->proximo;
        while (aux != NULL){
            printf("Aviao: %s. Codigo: %i. Cia: %s. Destino: %s \n", aux->nome, aux->codigo, aux->cia, aux->destino);
            aux = aux->proximo;
        }
    }
    if(filaVazia(fila) == 1)
        printf("\nFila vazia\n\n");
}

//Contar o numero de avioes aguardando na fila de decolagem
void contar(item *fila){
    int contador = 0;
    item *aux = fila->proximo;
    while(aux != NULL){
        contador++;
        aux = aux->proximo;
    }
    printf("\nNumero de Avioes na fila de espera : %i \n\n", contador);
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
            case 1: colocarNaFila(fila); break;
            case 2: mostrar(fila); break;
            case 3: retirarDaFila(fila); break;
            case 4: contar(fila); break;
            case 5: primeiro(fila); break;
            default: printf("\nOpcao Invalida\n"); break;
        }
        printf("\nDeseja continuar? [1] Sim [2] Nao: ");
        scanf("%i", &opcao);
    }
    while(opcao == 1);
    return 0;
}
