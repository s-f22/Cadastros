/*
Aluno: Samuel Figueiredo
P1-ED
Ex-4

    Implemente uma fila dinâmica em um programa que simule o controle de uma 
    lista de pacientes em um pronto socorro. Neste programa, o usuário deve 
    ser capaz de realizar as seguintes tarefas:

    Listar os pacientes a serem atendidos;
    chamar o primeiro paciente da fila para ser atendido;
    Adicionar um novo paciente no fim da fila;
    Considere que os paciente possuem um nome e um número inteiro como identificador. (2,0)

*/


#include <stdio.h>
#include <stdlib.h>

struct paciente{
    char nome[50]; 
    int codigo; 
    struct item *proximo;
};
typedef struct paciente item;

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


void colocarNaFila(item *fila){
    item *novo=(item*)malloc(sizeof(item));
    printf("\nInforme o nome do paciente: ");
    scanf("%s", &novo->nome);

    printf("Informe o codigo: ");
    scanf("%i", &novo->codigo);

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


void retirarDaFila(item *fila){
    if(filaVazia(fila) == 0){
        item *aux = fila->proximo;
        fila->proximo = aux->proximo;
        printf("Dados do paciente: \n Nome: %s. Codigo: %i. \n", aux->nome, aux->codigo);
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


void primeiro(item *fila){
    if(filaVazia(fila)==0){
        item *aux = fila->proximo;
        printf("\nDados do primeiro paciente na fila: Nome: %s Codigo: %i. \n", aux->nome, aux->codigo);
    }
    if(filaVazia(fila) == 1)
        printf("\nFila vazia\n\n");
}


void mostrar(item *fila){
    if(filaVazia(fila) == 0){
        item *aux = fila->proximo;
        while (aux != NULL){
            printf("paciente: %s. Codigo: %i. \n", aux->nome, aux->codigo);
            aux = aux->proximo;
        }
    }
    if(filaVazia(fila) == 1)
        printf("\nFila vazia\n\n");
}


void contar(item *fila){
    int contador = 0;
    item *aux = fila->proximo;
    while(aux != NULL){
        contador++;
        aux = aux->proximo;
    }
    printf("\nNumero de pacientes na fila de espera : %i \n\n", contador);
}


int main(int menu, int opcao) {
    item *fila = criaFila();
    printf("Simulacao - controle de fila de pacientes");
    do
    {
        printf("\n-------------------------------------------------------------");

        printf("\n[1] Add um paciente na fila de espera\n");
        printf("[2] Listar pacientes aguardando na fila de espera\n");
        printf("[3] Autorizar atendimento do primeiro paciente\n");
        printf("[4] Numero de pacientes aguardando na fila de espera. \n");
        printf("[5] Dados do primeiro paciente na fila.");
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
