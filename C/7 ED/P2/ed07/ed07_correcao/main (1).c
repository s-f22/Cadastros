/******************************************************************************
Lista simplesmente ligada
*******************************************************************************/

#include <stdio.h>

struct itm {
    int min;
    int max;
    struct itm *proximo;
} typedef item;

struct {
    item *inicio;
} typedef lista;

void adicionar(lista *p){
    printf("\n ADICIONAR========>");
    item *novo = (item*)malloc(sizeof(item));    
    printf("\nInforme um valor minimo e maximo:");
    scanf("%i %i", &novo->min, &novo->max);
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
    printf("\n LISTAR========>");
    if(p->inicio==NULL){
        printf("\nLista Vazia !!!");
    } else {
        item *aux = p->inicio;
        while(aux != NULL){
            printf("\n %x min=%i max=%i", aux, aux->min, aux->max);
            aux = aux->proximo;
        }
    }
}



void limites(lista *p){
    int varMin, varMax;
    printf("\n LIMITES========>");
    if(p->inicio==NULL){
        printf("\nLista Vazia !!!");
    } else {
        item *aux = p->inicio;
        varMax = aux->max; 
        varMin = aux->min;
        while(aux != NULL){
            if( aux->max > varMax) varMax = aux->max;
            if(aux->min < varMin ) varMin = aux->min;
            aux = aux->proximo;
        }
        printf("\n min=%i max=%i", varMin, varMax);
            
    }
}


void remover(lista *p, int valor){
    printf("\n REMOVER========>");
    if(p->inicio==NULL){
        printf("\nLista Vazia !!!");
    } else {
        item *aux = p->inicio;
        item *penultimo; 
        while(aux != NULL){
            if(aux->min == valor){
                if(aux == p->inicio) { //quando for o primeiro item
                    p->inicio = aux->proximo;
                } else { //quando for qualquer item 
                    penultimo->proximo = aux->proximo;
                }    
                free(aux);
                printf("\ncodigo removido %i", valor);
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
    lista  l1 = {NULL};
    
    adicionar(&l1);
    adicionar(&l1);
    adicionar(&l1);
    
    listar(&l1);
    limites(&l1);
    remover(&l1, 2);
    listar(&l1);
    remover(&l1, 3);
    listar(&l1);
    adicionar(&l1);
    remover(&l1, 1);
    listar(&l1);

    return 0;
}

