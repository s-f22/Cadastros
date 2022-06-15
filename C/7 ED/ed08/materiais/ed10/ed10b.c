#include <stdio.h>
#include <stdlib.h>

//lista circular
struct no{
 int valor;
 struct no *proximo;
};
//transformando o struct no em tipo item
typedef struct no item;

item *criaLista(){
	item *lista=(item*)malloc(sizeof(item)); //ponteiro e um end na memoria
	lista->proximo = NULL;
	return lista;
}

int listaVazia(item *p)
{
 	if(p->proximo==NULL){
 		return 1;	
	} else {
		return 0;
	}
}

void colocaNaLista(item *lista)
{
	item *novo=(item*)malloc(sizeof(item));
	printf("Informe um numero:"); 
	scanf("%i", &novo->valor);
	//pega o endereço do primeiro item e associa no ultimo
	novo->proximo = lista->proximo;  
	
	if(listaVazia(lista)==1){
		lista->proximo = novo;	
	} else {
		item *temp = lista->proximo;
		while(temp->proximo != novo->proximo && temp->proximo!=NULL){
			temp = temp->proximo;
		} 
		
		temp->proximo = novo;
	}
}


void colocaInicioLista(item *lista)
{
	item *novo=(item*)malloc(sizeof(item));
	printf("Informe um numero:"); 
	scanf("%i", &novo->valor);
	novo->proximo = NULL;  
	
	if(listaVazia(lista)==1){
		lista->proximo = novo;	
	} else {
		novo->proximo = lista->proximo;
		lista->proximo = novo;
	}
}




void removerLista(item *lista, int valor)
{
   if(listaVazia(lista)==0){
   		item *temp = lista->proximo; //end do primeiro item associado
		item *anterior = lista; //end da cabe?da lista
		item *primeiro = lista->proximo;
		while(temp->proximo != primeiro && temp->proximo!=NULL){
			if(temp->valor==valor){
				anterior->proximo = temp->proximo;
				printf("Item Removido %x %i \n", temp, temp->valor);
				free(temp);
				break;			
			} else {
				anterior = temp;
				temp = temp->proximo;
			}
		}
   }
}


void exibe(item *lista)
{
 	item *primeiro = lista->proximo;
   	item *temp = lista->proximo;
	do{
		printf("Item %x %i \n", temp, temp->valor);
		temp = temp->proximo;
	} while(temp != primeiro);
}

void total(item *lista)
{
	int comprimento = 0;
	item *primeiro = lista->proximo;
   	item *temp = lista->proximo;
	do{
		comprimento++;
		temp = temp->proximo;
	} while(temp != primeiro);
	
	
	printf("Total de itens : %i \n", comprimento);
}


int main(int argc, char *argv[]) {
	//vai cria end. inicial da final cabe?da fila
	item *lista = criaLista();
	colocaNaLista(lista);
	colocaNaLista(lista);
	colocaNaLista(lista);
//	colocaInicioLista(lista);
	exibe(lista);
	total(lista);
	removerLista(lista,5);
	exibe(lista);
	removerLista(lista,7);
	total(lista);
	
	return 0;
}

