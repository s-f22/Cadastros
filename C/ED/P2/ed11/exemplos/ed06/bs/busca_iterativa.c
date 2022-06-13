#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	 int t[] = {2,4,5,7,9,11,16,27,42,45,50};
	 int tamanho = sizeof(t)/sizeof(int);
	 int pos = buscaInt(45, tamanho, t);
	if(pos==-1){
		printf("nao encontrado !");
	} else {
		printf("Pos=%i, valor=%i \n", pos, t[pos]);
	}
	return 0;
}

int buscaInt(int c, int n, int * v){
	int meio, cmp, ini=0;
	int fim=n-1;
	while (ini <= fim) {
		meio=(ini+fim)/2;
		cmp = compInt(c,v[meio]);
		if (cmp < 0) {
			fim=meio-1;
		} else {
			if (cmp > 0) {
				ini=meio+1;
			} else {
				return meio;
			}
		} 
	}
   return -1;
}


int compInt(int c, int b)
{
	if (c < b)
		return -1;
	else if (c > b)
		return 1;
	else
	return 0;
}

