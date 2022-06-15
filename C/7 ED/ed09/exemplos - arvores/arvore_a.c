/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

typedef struct reg {
      int info; 
      struct noh *esq;
      struct noh *dir;
} noh; 

noh* arv_criavazia(void)
{
	return NULL;
}

noh* arv_cria(int c, noh* sae, noh* sad)
{
     noh* p=(noh*)malloc(sizeof(noh));
     if(p==NULL) exit(1);
     p->info = c;
     p->esq = sae;
     p->dir = sad;
     return p;
}

noh* arv_libera (noh* a){
 if (!arv_vazia(a)){
 	arv_libera(a->esq); /* libera sae */
 	arv_libera(a->dir); /* libera sad */
	free(a); /* libera raiz */
 }
 return NULL;
}

int arv_vazia (noh* a)
{
	return a==NULL;
}

int arv_pertence (noh* a, int c)
{
 if (arv_vazia(a))
 	return 0; /* árvore vazia: não encontrou */
 else
 	return a->info==c ||
 	arv_pertence(a->esq,c) ||
 	arv_pertence(a->dir,c);
}

void arv_imprime (noh* a)
{
 if (!arv_vazia(a)){
	 printf("%i ",a->info); /* mostra raiz */
	 arv_imprime(a->esq); /* mostra sae */
	 arv_imprime(a->dir); /* mostra sad */
 }
}




int main()
{
   /* sub-árvore 1 */
    noh* a1= arv_cria(1,arv_criavazia(),arv_criavazia());
    /* sub-árvore 2 */
    noh* a2= arv_cria(2,arv_criavazia(),a1);
    /* sub-árvore 3 */
    noh* a3= arv_cria(3,arv_criavazia(),arv_criavazia());
    /* sub-árvore 4 */
    noh* a4= arv_cria(4,arv_criavazia(),arv_criavazia());
    /* sub-árvore 5 */
    noh* a5= arv_cria(5,a3,a4);
    /* árvore 6 */
    noh* a = arv_cria(6,a2,a5 ); 
    arv_imprime(a);

    return 0;
}
