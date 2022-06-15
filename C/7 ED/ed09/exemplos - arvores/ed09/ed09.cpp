/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>


/***************** Arvore.h *********************/

typedef struct _no {
   int info;
   struct _no *esq;
   struct _no *dir;
} no;

typedef struct {
	no *raiz;
} arvore;



/*Cria um no em uma arvore!*/
void inserir (arvore *a, int v){
		    no *novo = (no*)malloc(sizeof(no));
	novo->info = v;
    novo->dir = NULL;
	novo->esq = NULL;   

   printf("\nADICIONANDO %i %x", v, novo);

    if(a->raiz == NULL){
       a->raiz = novo;
    } else {
		no *aux = a->raiz; 
		while(aux!=NULL){
			if(novo->info > aux->info){
				printf("->");
				//direita
				if(aux->dir==NULL){
					aux->dir = novo;
					break;
				} else {
					aux = aux->dir;
				}
			} else {
				printf("<-");
				//esquerda
				if(aux->esq==NULL){
					aux->esq = novo;
					break;
				} else {
					aux = aux->esq;
				}
			}
		}
	}
}


/*Cria um no em uma arvore!*/
void remover(arvore *a, int valor){
	printf("\nREMOVENDO %i", valor);
	if(a->raiz == NULL){
		printf("Arvore vazia !!");
	} else {
   		no *aux = a->raiz;
		no *anterior = NULL;
		    
		while(aux != NULL){
			if(valor == aux->info){
				printf("item removido !");
				free(aux);
				break;
			} else {
				anterior = aux;
				if(valor > aux->info){
					printf("->");	//direita
					aux = aux->dir;
				} else {
					printf("<-"); //esquerda
					aux = aux->esq;
				}
			}
		}
		if(anterior!=NULL && valor > anterior->info){
			anterior->dir = NULL;	
		} else {
			anterior->esq = NULL;
		}
	}
}



void listar(no *item){
	if(item != NULL){
		printf("\n %i %x", item->info, item);
		if(item->esq!=NULL) listar(item->esq);	
		if(item->esq!=NULL) listar(item->dir);
	}
}


/****************** Prog.c **********************/

int main () {

arvore a = {NULL};

inserir(&a, 50);
inserir(&a, 30);
inserir(&a, 90);
inserir(&a, 20);
inserir(&a, 40);
inserir(&a, 95);
inserir(&a, 10);
inserir(&a, 35);
inserir(&a, 45);

listar(a.raiz);

remover(&a, 10);
remover(&a, 199);
remover(&a, 45);
remover(&a, 50);
return 0;


}
