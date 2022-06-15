

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
/*
    cnpj -> vetor com os digitos do cnpj
    mult -> vetor com os multiplicadores, de tamanho N
    N -> Tamanho do vetor mult e tamb�m a quantidade de opera��es (12 ou 13)
*/
int calculaDigito(int cnpj[], int mult[], int N)
{
    int soma = 0, i;
    
    for (i = 0; i < N; i++)
    {
        soma = soma + cnpj[i] * mult[i];
    }
    return ((soma * 10) % 11) % 10;
}

/*
    Retorna true se todos os 14 digitos de um CNPJ forem iguais, caso contrario,
    retorna false.
*/
bool todosRepetidos(int cnpj[])
{
    int i;
    
    for (i = 1; i < 14; i++)
    {
        if (cnpj[0] != cnpj[i])
            return false;
    }
    return true;
}


/*
    Le CNPJ como string e processa adequadamente, transformando-o
    num vetor numerico, preenchendo zeros a esquerda, se necessario.
*/
void leiaCNPJ(int cnpj[])
{
    char texto[30];
    int i, j = 13;
    
    fgets(texto, 30, stdin);
    
    for (i = strlen(texto) - 1; i >= 0; i--)
    {
        if (texto[i] >= '0' && texto[i] <= '9')
        {
            cnpj[j] = texto[i] - '0';
            j--;
        }
    }

    while (j >= 0)
    {
        cnpj[j] = 0; //zero a esquerda
        j--;
    }
}

/*
    Imprime um CNPJ com pontos e hifen nas posicoes corretas 
*/
void imprimeCNPJ(int cnpj[])
{
    int i;
    
    for (i = 0; i < 14; i++)
    {
        printf("%d", cnpj[i]);
        
        if (i == 1 || i == 4)
            printf(".");
        else if (i == 7)
            printf("/");
        else if (i == 11)
            printf("-");
    }
}

int main()
{
    int cnpj[14];
    int m1[12] = {5,4,3,2,9,8,7,6,5,4,3,2};
    int m2[13] = {6,5,4,3,2,9,8,7,6,5,4,3,2};
    int i;
    
    printf("Entre com o CNPJ: ");
    leiaCNPJ(cnpj);

    if (todosRepetidos(cnpj) == false && calculaDigito(cnpj, m1, 12) == cnpj[12] &&
        calculaDigito(cnpj, m2, 13) == cnpj[13])
    {
        imprimeCNPJ(cnpj);
        
        printf("  ->  CNPJ valido.");
        
    }
    else
        printf("\nErro no CNPJ.");
        
    return 0;
}
