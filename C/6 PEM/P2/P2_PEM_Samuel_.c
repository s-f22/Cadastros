/*
ALUNO: SAMUEL FIGUEIREDO SILVEIRA
ADS - IPIRANGA - NOTURNO
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct pixel
{	int R, G, B;
} PIXEL;


PIXEL** espiral(int *pLinhas, int *pColunas, int *pMaxValor)
{	*pLinhas = 200;
    *pColunas = 300;
    *pMaxValor = 255;
	//criando a matriz
	PIXEL **mat;
	int i;
	mat = (PIXEL **) malloc(*pLinhas * sizeof(PIXEL *));
	
	for(i=0; i< *pLinhas; i++)
		mat[i] = (PIXEL *) malloc(*pColunas * sizeof(PIXEL));

	int l, c;
	for(l=0; l<*pLinhas; l++)
	{	for(c=0; c<*pColunas; c++)
		{	
			mat[l][c].R = 0;
			mat[l][c].G = 0;
			mat[l][c].B = 0;
		}
	}
	
	l=10; c=10;
	i=0;
	while(i<*pLinhas*0.5)
	{
		while(c<*pColunas*0.933-i)
		{
			mat[l][c].G = 64;
			c++;
		}
		while(l<*pLinhas*0.9-i)
		{
			mat[l][c].G = 128;
			l++;
		}
		while(c>=*pColunas*0.133+i)
		{
			mat[l][c].G = 192;
			c--;
		}
		while(l>=*pLinhas*0.2+i)
		{
			mat[l][c].G = 255;
			l--;
		}
		i+=*pLinhas*0.05;
	}

	return mat;
}



PIXEL** bandeira(int *pLinhas, int *pColunas, int *pMaxValor)
{	*pLinhas = 300;
    *pColunas = 400;
    *pMaxValor = 255;
	//criando a matriz
	PIXEL **mat;
	int i;
	mat = (PIXEL **) malloc(*pLinhas * sizeof(PIXEL *));
	
	for(i=0; i< *pLinhas; i++)
		mat[i] = (PIXEL *) malloc(*pColunas * sizeof(PIXEL));

	int l, c;
	for(l=0; l<*pLinhas*0.33333; l++)
	{	for(c=0; c<*pColunas; c++)
		{	mat[l][c].R = 255;
			mat[l][c].G = 255;
			mat[l][c].B = 255;
		}
	}
	for(l=100; l<*pLinhas*0.66666; l++)
	{	for(c=0; c<*pColunas; c++)
		{	mat[l][c].R = 0;
			mat[l][c].G = 0;
			mat[l][c].B = 255;
		}
	}
	for(l=200; l<*pLinhas; l++)
	{	for(c=0; c<*pColunas; c++)
		{	mat[l][c].R = 255;
			mat[l][c].G = 0;
			mat[l][c].B = 0;
		}
	}

	return mat;
}

PIXEL** lerImagem(char * nomeArquivo, int *pLinhas, int *pColunas, int *pMaxValor)
{	FILE *fp;
	fp = fopen(nomeArquivo,"r");
	/* Arquivo ASCII, para leitura */
	if(!fp)
	{	printf( "\nErro na abertura do arquivo\n\n");
		exit(-1);
	}

	//leia tipo do arquivo
	char buffer[1001];
	fgets (buffer, 1000, fp); //Primeira linha
	if(strstr(buffer, "P3") == NULL) // o tipo de arquivo eh diferente de P3?
	{	printf( "\nErro no tipo do arquivo\n\n");
		exit(-2);
	}

	//leia comentario
	fgets (buffer, 1000, fp);
	
	//leia dados da imagem
	fscanf(fp, "%d%d%d", pColunas, pLinhas, pMaxValor);

	//criando a matriz
	PIXEL **mat;
	int i;
	mat = (PIXEL **) malloc(*pLinhas * sizeof(PIXEL *));
	for(i=0; i< *pLinhas; i++)
		mat[i] = (PIXEL *) malloc(*pColunas * sizeof(PIXEL));

	int l, c;
	for(l=0; l<*pLinhas; l++)
	{	for(c=0; c<*pColunas; c++)
		{	fscanf(fp, "%d", &mat[l][c].R);
			fscanf(fp, "%d", &mat[l][c].G);
			fscanf(fp, "%d", &mat[l][c].B);
		}
	}
	fclose(fp);
	return mat;
}

void escreverImagem(char * nomeArquivo, PIXEL ** mat, int linhas, int colunas, int maxValor)
{	FILE *fp;
	fp = fopen(nomeArquivo,"w");
	// Arquivo ASCII, para leitura
	if(!fp)
	{	printf( "\nErro na abertura do arquivo\n\n");
		exit(-1);
	}

	//escreva tipo do arquivo
	fprintf (fp, "P3\n");
	//escreva comentario
	fprintf (fp, "#Figura modificada...\n");
	//colunas, linhas
	fprintf(fp, "%d %d\n", colunas, linhas);
	//maxValor
	fprintf(fp, "%d\n", maxValor);

	int l, c;
	for(l=0; l<linhas; l++)
	{	for(c=0; c<colunas; c++)
			fprintf(fp, "%d\n%d\n%d\n", mat[l][c].R, mat[l][c].G, mat[l][c].B);
	}
	fclose(fp);
}

int main(int argc, char * argv[])
{	char opcao[10]="0";
	int linhas=0, colunas=0, maxValor=0;
	PIXEL **mat=NULL;
	int tamanhoBorrao = 8;
	char nomeArquivo[100]="";
	char nomeArquivoLeitura[100]="";
	char nomeArquivoEscrita[100]="";
	while(opcao[0] != '9')
	{	printf("\n\nMini-photoshop\n\n");
		printf("1) Ler imagem\n");	
		printf("2) Gravar imagem\n");		
		printf("3) Bandeira da Russia\n");
		printf("4) Espiral\n");
		printf("9) Sair\n");
		printf("\nEntre a opcao desejada: ");	
		fgets(opcao, 10, stdin);
		switch(opcao[0])
		{	case '1':
				printf("\n\nEntre com o nome da imagem (sem extensao): ");
				fgets(nomeArquivo, 100, stdin);
				nomeArquivo[strlen(nomeArquivo)-1]='\0';
				strcpy (nomeArquivoLeitura, nomeArquivo);
				strcat (nomeArquivoLeitura, ".ppm");
				mat = lerImagem(nomeArquivoLeitura, &linhas, &colunas, &maxValor);
				break;
			case '2':
				strcpy (nomeArquivoEscrita, nomeArquivo);
				strcat (nomeArquivoEscrita, "imagem.ppm");
				printf("\n\nA imagem sera salva como %s\n", nomeArquivoEscrita);
				escreverImagem(nomeArquivoEscrita, mat, linhas, colunas, maxValor);
				break;
			
			case '3':
				mat =  bandeira(&linhas, &colunas, &maxValor);
				break;
			case '4':
				mat =  espiral(&linhas, &colunas, &maxValor);
				break;
			
		}
	}
	return 0;
}
