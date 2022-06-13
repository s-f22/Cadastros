/*
Aluno: Samuel Figueiredo

Instruções

1. O que e e como funciona uma estrutura do tipo fila? 
Resposta: 
Fila é uma estrutura linear na qual a inserção e remoção de itens segue o principio
 FIFO (First in, First Out), primeiro a chegar, primeiro a sair. Cada unidade da fila pode ser 
 inserida a qualquer momento, mas apenas seu primeiro item pode ser removido, tornando o segundo 
 membro da fila seu substituto, ou seja, o novo primeiro membro. Os elementos somente são inseridos 
 em um "lado" da fila, o final, e somente podem ser excluídos pelo outro lado, o início da fila. 
 Cada nó (elemento da fila) contem um ponteiro para os dados e um ponteiro de ligação para o 
 próximo elemento da fila


2. Em que situações uma fila pode ser utilizada?
Resposta
Podem ser usadas em resposta a requisições de serviços compartilhados, como filas de impressão e acesso a disco;
No armazenamento de teclas digitadas no teclado;
Agendamento de tempo de cpu;
Transferência de dados assíncrona entre processos
Contadores de tíquetes, gerenciamento de filas por senhas e listas de espera em geral


3. implemente uma fila dinamica de TADs de Cliente de um banco {nome, agencia, conta, saldo} . O módulo deve conter as funções   colocarFila,  tirarFila,  filaVazia, listarFila . 


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    int conta;
    int agencia;
    float saldo;
    char nome[30];
    struct item *proximo;
} typedef cliente;

struct {
    cliente *primeiro;
} typedef fila;

void colocarFila(fila *f){
    cliente *novo = (cliente*)malloc(sizeof(cliente));
    
    printf("\nInforme o numero da conta: ");
    scanf("%i", &novo->conta);
    
    printf("Informe o numero da agencia: ");
    scanf("%i", &novo->agencia);
    
    printf("Informe o valor do saldo: ");
    scanf("%f", &novo->saldo);
    
    printf("Informe seu nome: ");
    scanf("%s", &novo->nome);
    
    novo->proximo = NULL;
    //Se a fila estiver vazia a cliente sera a primeira
    if(f->primeiro==NULL){
        f->primeiro = novo; 
        printf("Primeiro da fila\n");
    } else {
        cliente *aux = f->primeiro;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
}

void removerFila(fila *f){
    if(f->primeiro==NULL){
        printf("\nFila esta vazia!!\n");
    } else {
        cliente *aux = f->primeiro->proximo;
        printf("\nItem removido %i\n", f->primeiro->conta);
        free(f->primeiro);
        f->primeiro = aux;
    }
}

void listarFila(fila *f){
    
    if(listaVazia(&f) == 0){
    	exit(0);
    } else {
        cliente *aux = f->primeiro;
        while(aux != NULL){
            printf("\nConta: %i\nAgencia: %i\nSaldo: %.2f\nNome: %s\n", aux->conta, aux->agencia, aux->saldo, aux->nome);
            aux = aux->proximo;
        }
    }     
}

int listaVazia(fila *f)
{
	if(f->primeiro == NULL){
        printf("\nFILA VAZIA");
        return 0;
    }
}



int main()
{
    fila f = {NULL};
    colocarFila(&f);
    colocarFila(&f);
    colocarFila(&f);
    listarFila(&f);
    removerFila(&f);
    removerFila(&f);
    removerFila(&f);
    removerFila(&f);
    removerFila(&f);
    listarFila(&f);
    return 0;
}





