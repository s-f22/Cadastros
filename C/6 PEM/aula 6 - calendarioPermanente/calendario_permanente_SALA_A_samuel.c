/*

ALUNO: SAMUEL FIGUEIREDO
ADS - IPIRANGA - NOTURNO

Instrucoes
Projeto Calendario Permanente (veja a imagem abaixo):

https://p.calameoassets.com/100318202814-34a9c063ecaf9fc19c30483d0a7f0160/p1.jpg

Abaixo esta um cadigo base para voce. As matrizes A1, A2, B e C ja estao preenchidas. 
Voce implementara a funcao procurarLinha, que varre uma matriz, em busca de um valor, e retorna somente a linha em que encontrou o elemento.

Adicionalmente, precisara terminar o main:
-Com base no ano, decida se vai fazer a primeira pesquisa em A1 (ano ate 2000) ou A2 (a partir de 2001). 
Use para a pesquisa somente os ultimos dois digitos do ano (para isso voce pode usar o resto da divisao inteira por 100: ano%100).

Esta pesquisa e feita com a chamada da funcao procurarLinha; so interessa saber em que linha da matriz esta este ano.
-Use a linha achada acima e a coluna correspondente ao mes para ler um valor da matriz B.
-Some o valor lido da matriz B ao dia: esta soma devera ser procurada na matriz C, com a chamada da funcao procurarLinha; 
so interessa saber em que linha da matriz esta esta soma. Esta linha contem o dia da semana correspondente a data em questao: 
0 para domingo, 1 para segunda, 2 para terça, 3 para quarta, 4 para quinta, 5 para sexta e 6 para sábado.


Exemplo numerico para melhorar o entendimento: vamos descobrir que dia da semana corresponde a 01/09/2018:

1) 2018 > 2000, entao procuro 18 na matriz A2: esta na 10a linha.
2) Na matriz B, 10a linha, coluna correspondente ao mes de Setembro, leio o número 6.
3) Somo 6 mais o dia (1), obtendo 7.
4) Procuro em que linha da matriz C existe o numero 7: ultima linha, correspondente a Sabado!!


Codigo de apoio:
*/

#include <stdio.h>
#include <locale.h>
#include <stdbool.h> // BIBLIOTECA COM FUNCOES BOOLEANAS

//FUNCAO EXTRA PARA VALIDAR SE, CASO O USUARIO DIGITE 29 PARA O MES DE FEVEREIRO, O ANO INFORMADO REALMENTE 
//SE TRATA DE UM BISSEXTO
bool Bissexto(int ano)
{
    if (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0)) 
        return true;
    return false;
}


int procurarLinha(int L, int C, int mat[L][C], int proc)
{
	int l, c;
//aqui você completa ....
//esta função retorna a linha em que proc aparece na matriz
//O PRIMEIRO FOR PERCORRE AS LINHAS DA MATRIZ A PARTIR DA LINHA 0
for(l = 0; l < L; l++)
{
	//O SEGUNDO FOR PERCORRE AS COLUNAS DA MATRIZ A PARTIR DA COLUNA 0
	for(c = 0; c < C; c++)
	{
		//CASO O VALOR ATUAL DA MATRIZ(LINHA E COLUNA ATUAIS) SEJA IGUAL AO PARAMETRO RECEBIDO PELA FUNCAO(PROC)
		//RETORNAMOS A LINHA ATUAL ONDE ELE SE ENCONTRA
		if(mat[l][c] == proc)
			return l;
	}
}

}

//Calendário permanente de 1901 a 2092

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

int main()
{
	
int l,c,x;
//populando a tabela A1
x=-3;
for(c=0;c<4;c++)
for(l=0;l<28;l++, x++)
if(x<1) A1[l][c]=-1;
else if(x<100) A1[l][c]=x;
else if(x==100) A1[l][c]=0;
else A1[l][c]=-1;

//populando a tabela A2
x=-19;
for(c=0;c<4;c++)
for(l=0;l<28;l++, x++)
if(x<1) A2[l][c]=-1;
else A2[l][c]=x;

//populando a tabela C
x=1;
for(c=0;c<6;c++)
for(l=0;l<7;l++, x++)
if(x>37) C[l][c]=-1;
else C[l][c]=x;

//VETOR COM A QUANTIDADE DE DIAS CORRESPONDENTE A CADA MES(INDICE DA MATRIZ) DO ANO
int qtdeDiasCadaMes[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int dia, mes, ano, resposta, linha;
setlocale(LC_ALL, "Portuguese");

printf("\nEntre com uma data no formato DD/MM/AAAA: ");
scanf("%d/%d/%d", &dia, &mes, &ano);

//VERIFICA SE A DATA INFORMADA ESTA FORA DO INTERVALO CALCULAVEL PELO PROGRAMA
if(ano<1901 || ano>2092) printf("Erro!! O ano deve ser de 1901 a 2092.\n");

//VALIDA SE O MES INFORMADO ESTA ENTRE 1 E 12;
else if (mes < 1 || mes > 12) 
	    printf("Erro!! O mês é inválido.\n");

//CASO SEJA INFORMADO O DIA 29 E MES 02, VERIFICA SE O VALOR DO ANO INFORMADO
//REALMENTE CORRESPONDE A UM BISSEXTO;
else if (Bissexto(ano) != true && mes == 02 && dia == 29)
	    printf("Erro!! O ano informado não é Bissexto.\n");

//VALIDA SE O DIA INFORMADO ESTA ENTRE 1 E 31
else if (dia < 1 || dia > 31) 
        printf("Erro!! O dia é inválido.\n");

//VALIDA A QUANTIDADE MAXIMA DE DIAS DE ACORDO COM CADA MES, IMPEDINDO QUE O USUARIO
//FORNECA MAIS DIAS DO QUE O MES REALMENTE POSSUA
else if (dia > qtdeDiasCadaMes[mes] ) 
	    printf("Erro!! O dia é inválido para esse mês.\n");

//SOMENTE APÓS NÃO ENTRAR EM NENHUMA DAS CONDICOES INVALIDAS ANTERIORES, SERAO FEITAS ENTAO AS VERIFICACOES
//DA DATA INSERIDA PELO USUARIO
else
{
	
	//EM ANOS VALIDOS ATE 2000, PROCURA A LINHA CORRESPONDENTE AO MODULO_100
	//DO ANO NA TABELA A1
	if(ano <= 2000)
		linha = procurarLinha(28, 4, A1, (ano%100));
		
	//EM ANOS VALIDOS MAIORES QUE 2000, PROCURA A LINHA CORRESPONDENTE AO MODULO_100
	//DO ANO NA TABELA A2
	else
		linha = procurarLinha(28, 4, A2, (ano%100));
	
	//IDENTIFICADA A LINHA CORRESPONDENTE AO ANO NA MATRIZ A, UTILIZAMOS O MESMO INDICE DESTA LINHA 
	//TAMBEM NA MATRIZ B, ONDE CADA COLUNA REPRESENTA UM MES, SUBTRAINDO 1 PARA CORRIGIR O MES INFORMADO PELO USUARIO.
	//DESSA FORMA, ENCONTRAMOS UM NUMERO ESPECIFICO LOCALIZADO ENTRE A LINHA E O MES, AO QUAL SOMAMOS O DIA 
	//INFORMADO PELO USUARIO NA VARIAVEL RESPOSTA
	resposta = B[linha][mes - 1] + dia;
	
	//ENCOTRADO/CALCULADO O VALOR DE RESPOSTA, UTILIZAMOS NOVAMENTE A FUNÇÃO PROCURARLINHA, AGORA PARA ENCONTRAR O INDICE
	//DA LINHA CORRESPONDENTE AO VALOR INT RESPOSTA, NA TABELA C. ESTE INDICE DE LINHA, DE ACORDO COM CADA VALOR DE RESPOSTA, EQUIVALE
	//A UM DIA DA SEMANA, PARTINDO DE DOMINGO(0) ATÉ SABADO(6);
	linha = procurarLinha(7, 6, C, resposta);
	
	//DECLARACAO DE UMA MATRIZ COM OS NOMES DE CADA DIA DA SEMANA, NA MESMA ORDEM EM QUE ESTAO ORGANIZADOS NA
	//TABELA C
	char diasSemana[7][50] = 	{ 	"Domingo",
									"Segunda-feira",
									"Terça-feira",
									"Quarta-feira",
									"Quinta-feira",
									"Sexta-feira",
									"Sabado",
								};
	
	//ENCONTRADO O INDICE DE LINHA, IMPRIMIMOS SEU VALOR, CORRESPONDENTE A DATA INFORMADA DE INICIO PELO USUARIO. FIM DO PROGRAMA.							
	printf("Dia da semana correspondente a data informada: %s", diasSemana[linha]);
	
	
}

//aqui você completa ......
//decida se vai usar A1 ou A2
//extraia os dois últimos dígitos para procurar em A1 ou A2 -----> encontrei uma linha para olhar na matriz B
//com o mês eu terei uma coluna na matriz B (Janeiro é mês 1 mas corresponde à coluna 0, Fevereiro é mês 2 mas corresponde à coluna 1, ........)
//some o dia de nascimento com o valor encontrado na matriz B
//procure este último cálculo na matriz C   ------> linha
// linha == 0 ---> Domingo
// linha == 1 ---> Segunda
// ....

return 0;
}
