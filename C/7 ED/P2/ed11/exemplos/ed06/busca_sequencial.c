#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int vet[] = {3,5,7,1,27,1,13,6,17,23};
	int n =  sizeof(vet)/sizeof(int);
	int pos = buscaSequencial(27,n,vet);
	if(pos==-1){
		printf("nao encontrado !");
	} else {
		printf("Pos=%i, valor=%i \n", pos, vet[pos]);
	}
	return 0;
}

int buscaSequencial(int x, int n, int v[]) {
   int j, p=-1;
   for (j = 0; j < n; j++){
      	if (x == v[j]){
			p = j;
			break;
		} 
   }
   return p; 
}

