/*
Aluno: Samuel Figueiredo

1-Implemente todos os metodos de uma pilha (push, pop e topo) de um TAD chamado caixa{codigo, peso, proximo} 

*/

#include<stdio.h>
#include<stdlib.h>


struct caixa{
    int codigo;
    float peso;
    struct caixa *proximo; //endereço do proximo item   
} typedef item;

//Tenho uma variavel (struct) chamada item, do tipo caixa. Este item possui como atributos um codigo, um peso e uma referencia para o proximo item (que tambem será do tipo caixa);


struct {
    item *topo;
} typedef pilha;

//Tenho uma variavel pilha. Esta variavel possui um atributo topo. O topo é do tipo item, que dentre seus atributos, possui uma referencia para o proximo item abaixo dele;
//*OBS: Apesar do nome pilha, só estamos armazenando um unico valor que estamos chamando de topo. Para termos uma pilha, de fato, deveriamos criar outra struct que armazenasse cada valor
//inserido.

void push(pilha *p){
    item *novo = (item*)malloc(sizeof(item)); //Criamos um novo item para receber os atributos a serem informados pelo usuario
    printf("\nInforme um numero inteiro para o codigo: ");
    scanf("%i", &novo->codigo);
    printf("Informe um valor para o peso: ");
    scanf("%f", &novo->peso);
    printf("\nNovo elemento criado. Endereco de Memoria: %x", novo);
    p->topo = novo; //Push acrescenta um item ao topo da pilha.
}


void pop(pilha *p){
    item *novoTopo = p->topo->proximo; // Iniciamos criando um novo item para guardar o atributo "proximo" do atual topo, que sera removido;
    printf("\nElemento a ser removido: %x \nProximo elemento: %x", p->topo, p->topo->proximo); //mostra o topo atual e seu próximo, antes da remocao;
    free(p->topo); //remove o topo atual
    p->topo = novoTopo; //atualiza o topo com o item novo, que nada mais é do que o anterior ao elemento excluido. Lembrando que este novo item tambem possui uma referencia para o elemento
    //abaixo dele, assim como todos os items;
}

void mostrar(pilha *p){
    printf("\nTopo da pilha %x, codigo=%i, peso=%.2f", p->topo, 
    p->topo->codigo, p->topo->peso);
}



int main()
{
    pilha pilha1;
    
    push(&pilha1);
    mostrar(&pilha1);
    push(&pilha1);
    mostrar(&pilha1);
    pop(&pilha1);
    mostrar(&pilha1);

    return 0;
}