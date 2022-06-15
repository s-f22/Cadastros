#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

/*
    IASMIN MOREIRA DIAS DA COSTA | 2040482113005 
    DATA: 04-07/09/2021
    
    PROJETO CALENDÁRIO PERMANENTE DE 1901 A 2092
*/

int A1[28][4], A2[28][4];
int B[28][12]=
	{{4,0,0,3,5,1,3,6,2,4,0,2},
	 {5,1,1,4,6,2,4,0,3,5,1,3},
	 {6,2,2,5,0,3,5,1,4,6,2,4},
	 {0,3,4,0,2,5,0,3,6,1,4,6},
	 {2,5,5,1,3,6,1,4,0,2,5,0},
	 {3,6,6,2,4,0,2,5,1,3,6,1},
	 {4,0,0,3,5,1,3,6,2,4,0,2},
	 {5,1,2,5,0,3,5,1,4,6,2,4},
	 {0,3,3,6,1,4,6,2,5,0,3,5},
	 {1,4,4,0,2,5,0,3,6,1,4,6},
	 {2,5,5,1,3,6,1,4,0,2,5,0},
	 {3,6,0,3,5,1,3,6,2,4,0,2},
	 {5,1,1,4,6,2,4,0,3,5,1,3},
	 {6,2,2,5,0,3,5,1,4,6,2,4},
	 {0,3,3,6,1,4,6,2,5,0,3,5},
	 {1,4,5,1,3,6,1,4,0,2,5,0},
	 {3,6,6,2,4,0,2,5,1,3,6,1},
	 {4,0,0,3,5,1,3,6,2,4,0,2},
	 {5,1,1,4,6,2,4,0,3,5,1,3},
	 {6,2,3,6,1,4,6,2,5,0,3,5},
	 {1,4,4,0,2,5,0,3,6,1,4,6},
	 {2,5,5,1,3,6,1,4,0,2,5,0},
	 {3,6,6,2,4,0,2,5,1,3,6,1},
	 {4,0,1,4,6,2,4,0,3,5,1,3},
	 {6,2,2,5,0,3,5,1,4,6,2,4},
	 {0,3,3,6,1,4,6,2,5,0,3,5},
	 {1,4,4,0,2,5,0,3,6,1,4,6},
	 {2,5,6,2,4,0,2,5,1,3,6,1}};
int C[7][6];

int diasMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void DiaDaSemana(int indice)
{
	char week[7][100] = {"Domingo.",
				    "Segunda-Feria.",
				    "Terça-Feira.",
				    "Quarta-Feira.",
				    "Quinta-Feira.",
				    "Sexta-Feira.",
				    "Sábado."};

	printf("\nEsta data foi em ");
		
	if(indice == 0 || indice == 6) printf("um ");
	else printf("uma ");
	
	printf("%s",week[indice]);
}

int procurarLinha(int L, int C, int mat[L][C], int proc)
{
	//aqui você completa ....
	//esta função retorna a linha em que proc aparece na matriz
	int l, c;
	for(l=0; l<L; l++)
	{	
		for(c=0; c<C; c++)
		{	
			if(mat[l][c] == proc)
			{
				return l;
			}
		}
	}
}

void populaA1()
{   int l,c,x;
	x=-3;
	for(c=0;c<4;c++)
		for(l=0;l<28;l++, x++)
			if(x<1) A1[l][c]=-1;
			else if(x<100) A1[l][c]=x;
			else if(x==100) A1[l][c]=0;
			else A1[l][c]=-1;
}

void populaA2()
{   int l,c,x;
	x=-19;
	for(c=0;c<4;c++)
		for(l=0;l<28;l++, x++)
			if(x<1) A2[l][c]=-1;
			else A2[l][c]=x;
}

void populaC()
{   int l,c,x;
	x=1;
	for(c=0;c<6;c++)
		for(l=0;l<7;l++, x++)
			if(x>37) C[l][c]=-1;
			else C[l][c]=x;
}

bool Bissexto(int ano)
{
    if (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0))
    {
        
        diasMes[2] = 29;
        return true;
    }
    
    diasMes[2] = 28;
    return false;
}

void Calendario(int num, int mes, int ano)
{
    char nomeMes[13][100] = {"-","Janeiro","Fevereiro","Marco","Abril","Maio","Junho","Julho",
                                "Agosto","Setembro","Outubro","Novembro","Dezembro"};
    int l,c,cont=0;
    
    populaC();
    num = num + 1;
	num = procurarLinha(7,6,C,num);
    
    printf("\n %s de %d",nomeMes[mes],ano);
    
	mes = diasMes[mes];

	printf("\n DG  SE  TE  QA  QI  SX  SB\n");
	for(l=0;l<6;l++)
	{
	   for(c=0;c<7;c++)
        {
    	   if(l==0 && c<num)
    	   {
    	       printf("    ");
    	   } 
    	   else 
    	   {
    	       if(mes > cont)
    	        {
        	       cont++;
        	            
            	   if(cont <= 9) printf(" 0%d ",cont);
            	   else printf(" %d ",cont);
    	        }

    	   }
    	}
	    printf("\n");
	}
}

int main()
{   int dia, mes, ano, linha;
	setlocale(LC_ALL, "Portuguese");
	printf("\nEntre com uma data no formato DD/MM/AAAA: ");
	scanf("%d/%d/%d", &dia, &mes, &ano);

	if(ano<1901 || ano>2092)
	{
	    printf("Erro!! O ano deve ser de 1901 a 2092.\n");
	}
    else if (mes < 1 || mes > 12) 
	{
	    printf("Erro!! O mês é inválido.\n");
	}
	else if (Bissexto(ano) != true && mes == 02 && dia == 29)
	{
	    printf("Erro!! O ano informado nao e Bissexto.\n");
	}
    else if (dia < 1 || dia > 31) 
    {
        printf("Erro!! O dia e invalido.\n");
    }
    else if (dia > diasMes[mes] ) 
	{
	    printf("Erro!! O dia e invalido para esse mês.\n");
	}
    else
    {
    	//decida se vai usar A1 ou A2
    	//extraia os dois últimos dígitos para procurar em A1 ou A2
    	if (ano>= 1901 && ano<= 2000) 
		{
			populaA1();
			linha = procurarLinha(28,4,A1,(ano%100));
		}
    	else 
    	{
    		populaA2();
			linha = procurarLinha(28,4,A2,(ano%100));
		}
		
    	//-----> encontrei uma linha para olhar na matriz B
    	//com o mês eu terei uma coluna na matriz B
    	// (Janeiro é mês 1 mas corresponde à coluna 0,
    	// Fevereiro é mês 2 mas corresponde à coluna 1, ........)
    	//some o dia de nascimento com o valor encontrado na matriz B
    	linha = B[linha][mes-1];
    	
    	Calendario(linha,mes,ano);
    	//procure este ultimo calculo na matriz C   ------> linha
    	// linha == 0 ---> Domingo
    	// linha == 1 ---> Segunda 
    	// ....
    	populaC();
    	linha = linha + dia;
		linha = procurarLinha(7,6,C,linha);
		
		DiaDaSemana(linha);
    }
    
	return 0;
}

