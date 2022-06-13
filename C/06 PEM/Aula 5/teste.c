/*
ALUNO: Samuel Figueiredo
ADS Ipiranga - Noturno - 2ï¿½ Semestre
Disciplina: PEM
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// -------------------------------------- VERIFICAR DIGITOS REPETIDOS -----------------------------------------------

bool todosRepetidos( int cpf[] )
{
	int i;
	
	for(i = 1; i < 11; i++)
	{
		if(cpf[0] != cpf[i]) 
			return false;
	}	
	return true;
}



int calculaDigito(int cpf[], int mult[], int N)
{
	int i, soma = 0;
	
    for (i = 0; i < N; i++)
        soma = soma + cpf[i] * mult[i];
    
    return ( (soma * 10) % 11) % 10;
}

// -------------------------------------- IMPRIMIR REGIAO DE ORIGEM -----------------------------------------------

void imprimeRegiaoOrigem( int cpf[] )
{
	int i;
	
	char matriz[10][70] = 	{
	/* 0 */						"Rio Grande do Sul",
	/* 1 */						"Distrito Federal, Goias, Mato Grosso, Mato Grosso do Sul ou Tocantins",
	/* 2 */						"Amazonas, Para, Roraima, Amapa, Acre ou Rondonia",
	/* 3 */						"Ceara, Maranhao ou Piaui",
	/* 4 */						"Paraiba, Pernambuco, Alagoas ou Rio Grande do Norte",
	/* 5 */						"Bahia ou Sergipe",
	/* 6 */						"Minas Gerais",
	/* 7 */						"Rio de Janeiro ou Espirito Santo",
	/* 8 */						"Sao Paulo",
	/* 9 */						"Parana ou Santa Catarina"
							};
	
	
		printf("Origem do CPF: %s", matriz[8]);
	
	
}


// -------------------------------------- MAIN -----------------------------------------------

int main()
{
    char texto[30];
    int cpf[11];
    int m1[9] = {10, 9, 8, 7, 6, 5, 4, 3, 2};
    int m2[10] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
    int i, j=10;
    
    
    printf("Entre com os 11 digitos do CPF: ");
    fgets(texto, 30, stdin);
    
    for ( strlen(texto) - 1; i >= 0 ; i-- )
    {
    	if(texto[i] >= 48 && texto[i] <= 57)
    	{
    		cpf[j] = texto[i] - 48;
    		j--;
		}
    		
	}
	
	while(j>=0)
	{
		cpf[j] = 0;
		j--;
		
	}
	
	// posso substituir 48, 57 por '0' e '9', respectivamente. São valores da tabela ASCII
    
    
    if 	( 	
			calculaDigito(cpf, m1, 9) == cpf[9] && 
			calculaDigito(cpf, m2, 10) == cpf[10] &&
			! todosRepetidos(cpf) 
		)
	    {
	    	printf("Numero informado: ");
	    	for(i=0; i<11; i++)
	    	{
	    		
	    		printf("%d", cpf[i]);
	    		
	    		if(i == 2 || i == 5)
	    			printf(".");
	    		else if (i == 8)
	    			printf("-");
	    		
			}
	    	
	        printf("\nCPF valido.\n");
	        imprimeRegiaoOrigem(cpf);
	    }
    
    else
        printf("\nErro no CPF.");
    
    return 0;
}
