/*
Aluno: Samuel Figueiredo

Instruções

4-Crie uma função para listar a menor valor para minimo de todas as ocorrencias e o maior valor para o maximo de todas as ocorrencias

*/

#include <stdio.h>

struct itm {
    int minimo;
    int maximo;
    struct itm *proximo;
} typedef item;

struct {
    item *inicio;
} typedef lista;

void adicionar(lista *p){
    item *novo = (item*)malloc(sizeof(item));    
    printf("\nInforme um minimo:");
    scanf("%i", &novo->minimo);
    printf("\nInforme um maximo:");
    scanf("%i", &novo->maximo);
    novo->proximo = NULL;
    if(p->inicio==NULL){
        p->inicio = novo;
    } else {
        item *aux = p->inicio;
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
}

void listar(lista *p){
    if(p->inicio==NULL){
        printf("\nLista Vazia !!!");
    } else {
        item *aux = p->inicio;
        item *menor = p->inicio;
        item *maior = p->inicio;
        while(aux != NULL){
            if (aux->proximo->minimo < menor->minimo )
            {
                menor->minimo = aux->proximo->minimo;
            }
            
            aux = aux->proximo;
        }
            printf("\nminimo=%i", menor->minimo);

        aux = maior;
        
        while(aux != NULL){
            if (aux->proximo->maximo > maior->maximo )
            {
                maior->maximo = aux->proximo->maximo;
            }
            aux = aux->proximo;
            printf("\nmaximo=%i", maior->maximo);
        }
    }
}


void removerMinimo(lista *p, int minimo){
    if(p->inicio==NULL){
        printf("\nLista Vazia !!!");
    } else {
        item *aux = p->inicio;
        item *penultimo; 
        while(aux != NULL){
            if(aux->minimo == minimo){
                if(aux == p->inicio) { //quando for o primeiro item
                    p->inicio = aux->proximo;
                } else { //quando for qualquer item 
                    penultimo->proximo = aux->proximo;
                }    
                free(aux);
                printf("\nminimo removido %i", minimo);
                break;
                // APAGAR 
            }
            
            penultimo = aux; 
            aux = aux->proximo;
        }
    } 
}

void removerMaximo(lista *p, int maximo){
    if(p->inicio==NULL){
        printf("\nLista Vazia !!!");
    } else {
        item *aux = p->inicio;
        item *penultimo; 
        while(aux != NULL){
            if(aux->maximo == maximo){
                if(aux == p->inicio) { //quando for o primeiro item
                    p->inicio = aux->proximo;
                } else { //quando for qualquer item 
                    penultimo->proximo = aux->proximo;
                }    
                free(aux);
                printf("\nmaximo removido %i", maximo);
                break;
                // APAGAR 
            }
            
            penultimo = aux; 
            aux = aux->proximo;
        }
    } 
}



int main()
{
	/*
	PARA TESTAR, INSERIR OS VALORES COMENTADOS:
	*/
    lista  l1 = {NULL};
    
    adicionar(&l1);
    //MIN: 1 MAX: 2
    adicionar(&l1);
    //MIN: 3 MAX: 4
    adicionar(&l1);
    //MIN: 5 MAX: 6
    adicionar(&l1);
    //MIN: 7 MAX: 8
    
      listar(&l1);

    return 0;
}


