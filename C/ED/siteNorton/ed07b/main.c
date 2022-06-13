#include <stdio.h>
#include <stdlib.h>

struct Item{
 int num;
 struct Item *prox;
};
typedef struct Item item;

item *aloca();
void insere(item *FILA);
item *retira(item *FILA);
void exibe(item *FILA);
void libera(item *FILA);

int tam;
int main(int argc, char *argv[]) {
	//iniciando a fila
	item *FILA = (item *) malloc(sizeof(item));
	FILA->prox = NULL;
 	tam=0;
	
	insere(FILA);
	insere(FILA);
	insere(FILA);
	exibe(FILA);
	retira(FILA); //FIFO => First In First Out
	exibe(FILA);
retira(FILA); //FIFO => First In First Out
	exibe(FILA);
	libera(FILA);
	return 0;
}

int vazia(item *FILA)
{
 //Existe o endereço do proximo item 
 if(FILA->prox == NULL)
  return 1;
 else
  return 0;
}

//função para alocar e criar um novo item da lista na memoria
item *aloca()
{
 	item *novo=(item *) malloc(sizeof(item));
 	if(!novo){
  		printf("Sem memoria disponivel!\n");
  		exit(1);
 	}else{
  		printf("Novo elemento: "); 
		scanf("%d", &novo->num);
  	}
  	return novo;
}

void insere(item *FILA)
{
 //cria um ponteiro do novo item alocado na memoria
 item *novo=aloca();
 novo->prox = NULL;
 //verifica se e o primeiro elemento e adiciona o end. Ponteiro no proximo 	
 if(vazia(FILA)){
 	FILA->prox=novo;
 } else{
  	item *tmp = FILA->prox;
  	while(tmp->prox != NULL){
  		tmp = tmp->prox;
  	}
  	tmp->prox = novo;
 }
 tam++;
}


item *retira(item *FILA)
{
 if(FILA->prox == NULL){
  printf("Fila ja esta vazia\n");
  return NULL;
 }else{
  item *tmp = FILA->prox;
  FILA->prox = tmp->prox;
  tam--;
  return tmp;
 }
}


void exibe(item *FILA)
{
 if(vazia(FILA)){
  printf("Fila vazia!\n\n");
 } else {
 	item *tmp;
 	tmp = FILA->prox;
 	printf("Fila :\n");
 	while(tmp != NULL){
  		printf("%i \n", tmp->num);
  		tmp = tmp->prox;
 	}
 }
}



void libera(item *FILA)
{
 if(!vazia(FILA)){
  item *proxNode, *atual;
  atual = FILA->prox;
  while(atual != NULL){
   proxNode = atual->prox;
   free(atual);
   atual = proxNode;
  }
 }
}
