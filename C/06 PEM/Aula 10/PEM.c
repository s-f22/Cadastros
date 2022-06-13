#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>

struct ficha
{
    char nome[40];
    char telefone[20];
    char email[40];
    char naturalidade[40];
    char UF_Nasc[30];
    char dataNasc[20];
    char rua[40];
    char numero[10];
    char bairro[40];
    char municipio[40];
    bool ativo;
};

int procurarRec(char procurado[], struct ficha vetor[], int num_fichas)
{
    if (strcmp(procurado, vetor[num_fichas - 1].nome) == 0)
        return num_fichas - 1;
    else if (strcmp(procurado, vetor[num_fichas - 1].nome) > 0)
        return procurarRec(procurado, vetor, num_fichas - 1);
    else
        return -1;
}

int procurar(char procurado[], struct ficha vetor[], int num_fichas)
{
    int i;
    for (i = 0; i < num_fichas; i++)
    {
        if (strcmp(procurado, vetor[i].nome) == 0)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    struct ficha agenda[100];
    int fichas_existentes = 0, proxima = 0;
    char opcao[10] = "0";
    setlocale(LC_ALL, "Portuguese");

    while (opcao[0] != '5')
    {
        printf("\nEntre com a opção desejada:\n");
        printf("\n1) Inserir ficha:");
        printf("\n2) Procurar por nome:");
        printf("\n3) Listar toda a base:");
        printf("\n4) Excluir por nome:");
        printf("\n5) Sair\n\n");
        gets(opcao);

        if (opcao[0] == '1') //**************Inserir**************************
        {
            printf("\nEntre com um nome:");
            gets(agenda[proxima].nome);
            agenda[proxima].ativo = true;
            printf("\nEntre com um telefone:");
            gets(agenda[proxima].telefone);
            agenda[proxima].ativo = true;
            //	printf("\nEntre com um email:");
            //	gets(agenda[proxima].email);
            //  agenda[proxima].ativo = true;
            //	printf("\nEntre com o local de nascimento:");
            //	gets(agenda[proxima].naturalidade);
            //  agenda[proxima].ativo = true;
            //	printf("\nEntre com o UF de nascimento:");
            //	gets(agenda[proxima].UF_Nasc);
            //  agenda[proxima].ativo = true;
            //	printf("\nEntre com a data de nascimento:");
            //	gets(agenda[proxima].dataNasc);
            //  agenda[proxima].ativo = true;
            //	printf("\nEntre com o nome da rua:");
            //	gets(agenda[proxima].rua);
            //  agenda[proxima].ativo = true;
            //	printf("\nEntre com o numero da rua:");
            //	gets(agenda[proxima].numero);
            //  agenda[proxima].ativo = true;
            //	printf("\nEntre com o bairro:");
            //	gets(agenda[proxima].bairro);
            //  agenda[proxima].ativo = true;
            //	printf("\nEntre com o municipio:");
            //	gets(agenda[proxima].municipio);
            //  agenda[proxima].ativo = true;
            fichas_existentes++;
            proxima++;
        }
        if (opcao[0] == '2') //******************procurar************************
        {
            char procurado[40];
            printf("\nEntre com o nome procurado:");
            gets(procurado);

            int i = procurar(procurado, agenda, fichas_existentes);
            if (i >= 0)
                printf("\n\nO telefone de %s é %s\n",
                       agenda[i].nome, agenda[i].telefone);
            else
                printf("\n\nNome não encontrado\n");
        }

        if (opcao[0] == '3') //*****************Listar tudo********************
        {
            //printf("\n\n");
            printf("==== Dados existentes ====\n\n");
            int i;
            for (i = 0; i < fichas_existentes; i++)
            {

                printf("\n\nNome: %s \nTelefone: %s\n",
                       agenda[i].nome, agenda[i].telefone);
            }
            if (fichas_existentes == 0)
                printf("A base de dados está vazia!\n");
        }
        if (opcao[0] == '4') //****************Excluir****************
        {
            char procurado[40];
            printf("\nEntre com o nome que sera excluído:");
            gets(procurado);
            //agenda[proxima].ativo = false;

            int i = procurar(procurado, agenda, fichas_existentes);
            if (i >= 0)
            {
                printf("\n\nO numero %s de %s será excluido!\n",
                       agenda[i].telefone, agenda[i].nome);

                int j;
                for (j = i + 1; j < fichas_existentes; j++)
                {
                    agenda[j - 1] = agenda[j];
                }
                
                    //fichas_existentes--;
                    //  proxima--;
                    agenda[proxima]
                        .ativo = false;
            }

            else
                printf("\n\nNome não encontrado\n");
        }
    }
    return 0;
}

switch (expression)
{
case /* constant-expression */:
    /* code */
    break;

default:
    break;
}