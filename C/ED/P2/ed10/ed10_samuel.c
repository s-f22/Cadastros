/*
Aluno: Samuel Figueiredo

Utilizando o exemplo ed10, implemente as seguintes funçoes 
recursivas:

1-Conte a quantidade total de elementos
2-mostre o maior valor entre todos os itens
3-mostre o menor valor entre todos os itens
*/


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


no* criarItem(int v){
	no *novo = (no*)malloc(sizeof(no));
	novo->info = v;
	novo->dir = NULL;
	novo->esq = NULL;   
   	return novo;		
}


/*Cria um no em uma arvore!*/
void inserirRecursivo(no *n, no *novo){
   if(n==NULL){
	   printf("\nADICIONANDO RECURSIVO %i %x", novo->info, novo);
   } else {
   		if(novo->info > n->info){
   			inserirRecursivo(n->dir, novo);	
		} else {
			inserirRecursivo(n->esq, novo);
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



int altura(no *item){
	if(item == NULL){
		return 0;
	} else {
		if(item->esq!=NULL) return altura(item->esq)+1;
		if(item->dir!=NULL) return altura(item->dir)+1;
	}
}



int contarNos(no *a){
   if(a == NULL)
        return 0;
   else
        return 1 + contarNos(a->esq) + contarNos(a->dir);
}



int maior(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}


int maior_ramo(no *a){
   if((a == NULL)){
        return 0;
   }
   else{
        return maior(maior_ramo(a->dir) +a-> info, maior_ramo(a->esq) + a->info);
   }
}



int min (no *a){
    if( a->esq != NULL){
        return min(a->esq);
    }
    else{
         return a->info;
    }
}

int max (no *a){
    if (a->dir != NULL){
        return max(a->dir);
    }
    else{
        return a->info;
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

int h = altura(a.raiz);
printf("\nTotal de niveis: %i", h);

printf("\nTotal de nos: %i", contarNos(a.raiz));
printf("\nMenor valor: %i", min(a.raiz));
printf("\nMaior valor: %i", max(a.raiz));


printf("\nMaior ramo: %i\n", maior_ramo(a.raiz));

/*
remover(&a, 10);
remover(&a, 199);
remover(&a, 45);
remover(&a, 50);


arvore a2 = {NULL};
a2.raiz = criarItem(34);
inserirRecursivo(a.raiz, criarItem(95));
inserirRecursivo(a.raiz, criarItem(10));
inserirRecursivo(a.raiz, criarItem(30));
inserirRecursivo(a.raiz, criarItem(50));
listar(a2.raiz);
*/

return 0;


}
