//ALUNO: Samuel Figueiredo
//ADS Ipiranga, Noturno

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

//Calendaio permanente de 1901 a 2092

int A1[28][4], A2[28][4];

int linha, coluna, contador;

int B[28][12] = {
	{4, 0, 0, 3, 5, 1, 3, 6, 2, 4, 0, 2} //LINHA INICIAL DA MATRIZ B; CADA NUMERO CORRESPONDE A QTD DE DIAS FALTANTES PARA UM TOTAL DE 7 (DIAS DA SEMANA)
										 //NOS ANOS DA LINHA 0 DAS MATRIZES A1 E A2;
};

int C[7][6];

void soma(int num)
{
	if (B[linha - 1][coluna] < 6 && contador < num)
		B[linha][coluna] = B[linha - 1][coluna] + 1;

	else if (B[linha - 1][coluna] < 5 && contador == num)
	{
		B[linha][coluna] = B[linha - 1][coluna] + 2;
		contador = 0;
	}

	else if (B[linha - 1][coluna] == 5 && contador == num)
	{
		B[linha][coluna] = 0;
		contador = 0;
	}

	else if (B[linha - 1][coluna] == 6 && contador == num)
	{
		B[linha][coluna] = 1;
		contador = 0;
	}

	else if (B[linha - 1][coluna] == 6 && contador < num)
		B[linha][coluna] = 0;
}

int diasMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void DiaDaSemana(int indice)
{
	char week[7][100] = {"Domingo.\n",
						 "Segunda-feira.\n",
						 "Terca-feira.\n",
						 "Quarta-feira.\n",
						 "Quinta-feira.\n",
						 "Sexta-feira.\n",
						 "Sabado.\n"};

	printf("Esta data foi em ");

	if (indice == 0 || indice == 6)
		printf("um ");
	else
		printf("uma ");

	printf("%s", week[indice]);
}

int procurarLinha(int L, int C, int mat[L][C], int proc)
{
	//aqui voce completa ....
	//esta funcao retorna a linha em que proc aparece na matriz
	int l, c;
	for (l = 0; l < L; l++)
	{
		for (c = 0; c < C; c++)
		{
			if (mat[l][c] == proc)
			{
				return l;
			}
		}
	}
}

void populaA1()
{
	int l, c, x;
	x = -3;
	for (c = 0; c < 4; c++)
		for (l = 0; l < 28; l++, x++)
			if (x < 1)
				A1[l][c] = -1;
			else if (x < 100)
				A1[l][c] = x;
			else if (x == 100)
				A1[l][c] = 0;
			else
				A1[l][c] = -1;
}

void populaA2()
{
	int l, c, x;
	x = -19;
	for (c = 0; c < 4; c++)
		for (l = 0; l < 28; l++, x++)
			if (x < 1)
				A2[l][c] = -1;
			else
				A2[l][c] = x;
}

//populando a tabela B
void populaB()
{
	for (coluna = 0; coluna < 12; coluna++)
	{
		if (coluna <= 1)
		{
			for (linha = 1, contador = 1; linha < 28; linha++, contador++)
				soma(4);
		}
		else
			for (linha = 1, contador = 1; linha < 28; linha++, contador++)
			{
				if (linha <= 3) // volta a somar 4, depois de somar o primeiro e unico 3
					soma(3);
				else
					soma(4);
			}
	}
}

void populaC()
{
	int l, c, x;
	x = 1;
	for (c = 0; c < 6; c++)
		for (l = 0; l < 7; l++, x++)
			if (x > 37)
				C[l][c] = -1;
			else
				C[l][c] = x;
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
	char nomeMes[13][100] = {"-", "Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho",
							 "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
	int l, c, cont = 0;

	populaC();
	num = num + 1;
	num = procurarLinha(7, 6, C, num);

	printf("\n %s de %d", nomeMes[mes], ano);

	mes = diasMes[mes];

	printf("\n DG  SE  TE  QA  QI  SX  SB\n");
	for (l = 0; l < 6; l++)
	{
		for (c = 0; c < 7; c++)
		{
			if (l == 0 && c < num)
			{
				printf("    ");
			}
			else
			{
				if (mes > cont)
				{
					cont++;

					if (cont <= 9)
						printf(" 0%d ", cont);
					else
						printf(" %d ", cont);
				}
			}
		}
		printf("\n");
	}
}

int main()
{
	int dia, mes, ano, linha;
	setlocale(LC_ALL, "Portuguese");
	printf("\nEntre com uma data no formato DD/MM/AAAA: ");
	scanf("%d/%d/%d", &dia, &mes, &ano);

	populaB();

	if (ano < 1901 || ano > 2092)
	{
		printf("Erro!! O ano deve ser de 1901 a 2092.\n");
	}
	else if (mes < 1 || mes > 12)
	{
		printf("Erro!! Mes invalido.\n");
	}
	else if (Bissexto(ano) != true && mes == 02 && dia == 29)
	{
		printf("Erro!! O ano informado nao e Bissexto.\n");
	}
	else if (dia < 1 || dia > 31)
	{
		printf("Erro!! Dia invalido.\n");
	}
	else if (dia > diasMes[mes])
	{
		printf("Erro!! Dia invalido para este mes.\n");
	}
	else
	{
		//decida se vai usar A1 ou A2
		//extraia os dois ultimos digitos para procurar em A1 ou A2
		if (ano >= 1901 && ano <= 2000)
		{
			populaA1();
			linha = procurarLinha(28, 4, A1, (ano % 100));
		}
		else
		{
			populaA2();
			linha = procurarLinha(28, 4, A2, (ano % 100));
		}

		//-----> encontrei uma linha para olhar na matriz B
		//com o mês eu terei uma coluna na matriz B
		// (Janeiro é mês 1 mas corresponde à coluna 0,
		// Fevereiro é mês 2 mas corresponde à coluna 1, ........)
		//some o dia de nascimento com o valor encontrado na matriz B
		linha = B[linha][mes - 1];

		Calendario(linha, mes, ano);
		//procure este último cálculo na matriz C   ------> linha
		// linha == 0 ---> Domingo
		// linha == 1 ---> Segunda
		// ....
		populaC();
		linha = linha + dia;
		linha = procurarLinha(7, 6, C, linha);

		DiaDaSemana(linha);
	}

	if (dia >= 20 && dia <= 31 && mes == 3 || dia >= 1 && dia <= 20 && mes == 4)
	{
		printf("\nSigno correspondente: Aries");
	}
	else if (dia >= 21 && dia <= 30 && mes == 4 || dia >= 1 && dia <= 20 && mes == 5)
	{
		printf("\nSigno correspondente: Touro");
	}
	else if (dia >= 21 && dia <= 31 && mes == 5 || dia >= 1 && dia <= 20 && mes == 6)
	{
		printf("\nSigno correspondente: Gemeos");
	}
	else if (dia >= 21 && dia <= 30 && mes == 6 || dia >= 1 && dia <= 21 && mes == 7)
	{
		printf("\nSigno correspondente: Cancer");
	}
	else if (dia >= 22 && dia <= 31 && mes == 7 || dia >= 1 && dia <= 22 && mes == 8)
	{
		printf("\nSigno correspondente: Leao");
	}
	else if (dia >= 22 && dia <= 31 && mes == 8 || dia >= 1 && dia <= 22 && mes == 9)
	{
		printf("\nSigno correspondente: Virgem");
	}
	else if (dia >= 22 && dia <= 30 && mes == 9 || dia >= 1 && dia <= 22 && mes == 10)
	{
		printf("\nSigno correspondente: Libra");
	}
	else if (dia >= 23 && dia <= 31 && mes == 10 || dia >= 1 && dia <= 21 && mes == 11)
	{
		printf("\nSigno correspondente: Escorpiao");
	}
	else if (dia >= 22 && dia <= 30 && mes == 11 || dia >= 1 && dia <= 21 && mes == 12)
	{
		printf("\nSigno correspondente: Sagitario");
	}
	else if (dia >= 22 && dia <= 31 && mes == 12 || dia >= 1 && dia <= 20 && mes == 1)
	{
		printf("\nSigno correspondente: Capricornio");
	}
	else if (dia >= 21 && dia <= 31 && mes == 1 || dia >= 1 && dia <= 18 && mes == 2)
	{
		printf("\nSigno correspondente: Aquario");
	}
	else if (dia >= 19 && dia <= 29 && mes == 2 || dia >= 1 && dia <= 19 && mes == 3)
	{
		printf("\nSigno correspondente: Peixes");
	}
	
	return 0;
}
