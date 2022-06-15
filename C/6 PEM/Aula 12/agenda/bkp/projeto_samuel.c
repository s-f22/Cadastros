#include <stdio.h>
#include <string.h>
#include <stdlib.h>



struct ficha
{
	char nome[40];
	char telefone[20];
};



void lerArquivo(char * nomeArquivo, struct ficha vet[], int *num_fichas)
{
	FILE *fp;
	fp = fopen(nomeArquivo,"r");
	/* Arquivo ASCII, para leitura */
	
	if(!fp)
	{
		printf( "\nErro na abertura do arquivo\n\n");
		exit(-1); //substituir por: return;
	}
	
	
	
	//leia numero de fichas
	char buffer[101];
	fgets (buffer, 100, fp); //Primeira linha
	*num_fichas = atoi(buffer); //ask to integer
	int i;
	
	for(i=0; i < *num_fichas; i++)
	{
		fgets (vet[i].nome, 39, fp);
		//retirando o ENTER do nome lido
		vet[i].nome[strlen(vet[i].nome)-1] = '\0';
		fgets (vet[i].telefone, 19, fp);
		//retirando o ENTER do telefone lido
		vet[i].telefone[strlen(vet[i].telefone)-1] = '\0';
	}
	fclose(fp);
}



void escreverArquivo(char * nomeArquivo, struct ficha vet[], int num_fichas)
{
	FILE *fp;
	fp = fopen(nomeArquivo,"w");
	/* Arquivo ASCII, para escrita */
	
	if(!fp)
	{
		printf( "\nErro na abertura do arquivo\n\n");
		exit(-1);
	}
	
	
	
	//escreva o numero de fichas
	fprintf (fp, "%d\n", num_fichas);
	//escrevendo as fichas...
	//cada campo numa linha: nome e telefone
	int i;
	
	for(i=0; i<num_fichas; i++)
	{
		fprintf(fp, "%s\n", vet[i].nome);
		fprintf(fp, "%s\n", vet[i].telefone);
	}
	
	fclose(fp);
}


//Le toda a planilha, linha por linha, até não haver mais linhas, fazendo a contagem
void lerPlanilha(char * nomeArquivo, struct ficha vet[], int *num_fichas)
{
	FILE *fp;
	fp = fopen(nomeArquivo,"r");
	/* Arquivo ASCII, para leitura */
	
	if(!fp)
	{
		printf( "\nNao foi possivel abrir o BD.\n\n");
		return;
	}
	
	
	int i=0;
	while( !feof(fp) )
	{ 
		fscanf(fp, "%39[^,],", vet[i].nome); // para o limite de 40 caracteres, pego tudo até o 39 e depois pego a virgula
		fscanf(fp, "%19[^\n]\n", vet[i].telefone);
		i++;
	}
	
	*num_fichas = i;
	fclose(fp);
}



void escreverPlanilha(char * nomeArquivo, struct ficha vet[], int num_fichas)
{
	FILE *fp;
	fp = fopen(nomeArquivo,"w");
	/* Arquivo ASCII, para escrita */
	
	if(!fp)
	{
		printf( "\nErro na abertura do arquivo\n\n");
		exit(-1);
	}
	
	
	
	//escrevendo as fichas...
	//cada campo numa linha: nome e telefone
	int i;
	
	for(i=0; i<num_fichas; i++)
	{
		fprintf(fp, "%s,%s\n", vet[i].nome,
		vet[i].telefone);
	}
	
	fclose(fp);
}



void lerArquivoBinario(char * nomeArquivo, struct ficha vet[], int *num_fichas)
{ 
	FILE *fp;
	fp = fopen(nomeArquivo,"rb"); // Arquivo binário, para leitura
	
	if(!fp)
	{
		printf( "\nErro na abertura do arquivo\n\n");
		exit(-1);
	}
	
	fread(num_fichas, sizeof(int) , 1, fp);
	fread(vet, sizeof(struct ficha), *num_fichas, fp);
	fclose(fp);
}


// SERIALIZAÇÃO: GRAVAÇÃO EM BINARIO
void escreverArquivoBinario(char * nomeArquivo, struct ficha vet[], int num_fichas)
{ 
	FILE *fp;
	fp = fopen(nomeArquivo,"wb"); // Arquivo binário, para escrita; wb = write binary
	
	if(!fp)
	{ 
		printf( "\nErro na abertura do arquivo\n\n");
		exit(-1);
	}

	fwrite(&num_fichas, sizeof(int), 1, fp); //escreva o numero de fichas
	fwrite(vet, sizeof(struct ficha), num_fichas, fp); //escreva o vetor
	fclose(fp);
}



int main()
{
	struct ficha agenda[100];
	int fichas_existentes = 0;
	char opcao[10]="0";
	
	//lerArquivo("bd.csv", agenda, &fichas_existentes); 
	lerPlanilha("bd.csv", agenda, &fichas_existentes); // ------------------------ 01)
	
	while(opcao[0] != 'S')
	{
		printf("\nEntre com a opcao desejada:\n");
		printf("\n1) Inserir ficha:");
		printf("\n2) Procurar por nome:");
		printf("\n3) Listar toda a base:");
		printf("\n4) Excluir por nome:");
		printf("\n5) Gravar base em arquivo (texto):");
		printf("\n6) Ler base de arquivo (texto):");
		printf("\n7) Gravar planilha:");
		printf("\n8) Ler planilha:");
		printf("\n9) Gravar base em arquivo (binário):");
		printf("\n0) Ler base de arquivo (binário):");
		printf("\nS) Sair\n\n");
		gets(opcao);
		
		
		
		if(opcao[0] == '1') //inserir
		{
			printf("\nEntre com um nome:");
			gets(agenda[fichas_existentes].nome);
			printf("\nEntre com um telefone:");
			gets(agenda[fichas_existentes].telefone);
			fichas_existentes++;
		}
		
		if(opcao[0] == '2') //procurar
		{
			char procurado[40];
			printf("\nEntre com o nome procurado:");
			gets(procurado);
			
			int achei = 0; //nao achei
			int i;
			
			for(i=0; i<fichas_existentes; i++)
			{
				if(strcmp(procurado, agenda[i].nome) == 0)
				{
					achei = 1; //achei!!
					printf("\n\nO telefone de %s eh %s\n",
					agenda[i].nome, agenda[i].telefone);
					//depois de achar nao preciso procurar mais
					break;
				}
			}
			if(achei == 0)
			{
				printf("\n\nNome nao encontrado\n");
			}
		}
		
		if(opcao[0] == '3') //listar tudo
		{
			printf("\n\n");
			int i;
			for(i=0; i<fichas_existentes; i++)
			{
				printf("O telefone de %s eh %s\n",
				agenda[i].nome, agenda[i].telefone);
			}
			
			if(fichas_existentes == 0)
			printf("A base de dados esta vazia!\n");
		}
		
		if(opcao[0] == '4') //excluir
		{
			char procurado[40];
			printf("\nEntre com o nome que sera excluido:");
			gets(procurado);
			
			
			
			int achei = 0; 
			int i;
			for(i=0; i<fichas_existentes; i++)
			{
				if(strcmp(procurado, agenda[i].nome) == 0)
				{
					achei = 1; //achei!!
					printf("\n\nO telefone de %s, que eh %s, sera removido\n", agenda[i].nome, agenda[i].telefone);
					int j;
					
					for(j=i+1; j<fichas_existentes; j++)
					{
						agenda[j-1] = agenda[j];
					}
					fichas_existentes--;
					break;
				}
			}
			if(achei == 0)
			{
				printf("\n\nNome nao encontrado\n");
			}
		}
		if(opcao[0] == '5') //gravar (texto)
		{
			char nomeArquivo[40];
			printf("\nEntre com o nome do arquivo para gravacao:");
			gets(nomeArquivo);
			escreverArquivo(nomeArquivo, agenda, fichas_existentes);
		}
		if(opcao[0] == '6') //ler (texto)
		{
			char nomeArquivo[40];
			printf("\nEntre com o nome do arquivo para leitura:");
			gets(nomeArquivo);
			lerArquivo(nomeArquivo, agenda, &fichas_existentes);
		}
		if(opcao[0] == '7') //gravar planilha
		{
			char nomeArquivo[40];
			printf("\nEntre com o nome do arquivo para gravacao ( .csv ):");
			gets(nomeArquivo);
			escreverPlanilha(nomeArquivo, agenda, fichas_existentes);
		}
		if(opcao[0] == '8') //ler planilha
		{
			char nomeArquivo[40];
			printf("\nEntre com o nome do arquivo para leitura ( .csv ):");
			gets(nomeArquivo);
			lerPlanilha(nomeArquivo, agenda, &fichas_existentes);
		}
		if(opcao[0] == '9') //gravar (binário)
		{
			char nomeArquivo[40];
			printf("\nEntre com o nome do arquivo para gravacao:");
			gets(nomeArquivo);
			escreverArquivoBinario(nomeArquivo, agenda, fichas_existentes);
		}
		if(opcao[0] == '0') //ler (binário)
		{
			char nomeArquivo[40];
			printf("\nEntre com o nome do arquivo para leitura:");
			gets(nomeArquivo);
			lerArquivoBinario(nomeArquivo, agenda, &fichas_existentes);
		}
	}
	
	escreverPlanilha("bd.csv", agenda, fichas_existentes);
	
	return 0;
}
