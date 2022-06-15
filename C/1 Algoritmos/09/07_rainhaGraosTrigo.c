/*

7 –  Uma rainha requisitou os serviços de um monge e disse-lhe 
que pagaria qualquer preço. O monge, necessitando de alimentos , 
indagou à rainha sobre o pagamento, se poderia ser feito com grãos 
de trigo dispostos em um tabuleiro de 64 casas, de tal forma que o 
primeiro quadro deveria conter apenas um grão e os quadros subsequentes, 
o dobro do quadro anterior. A rainha achou o trabalho barato e pediu 
que o serviço fosse executado, sem se dar conta de que seria impossível 
efetuar o pagamento. Faça um algoritmo para calcular o número de grãos 
que o monge esperava receber.

100.000 graos = 1kg

*/

#include <stdio.h>

int main()
{
	int i;
	long long unsigned graos = 1;
	
	for (i = 1; i <= 64; i++)
	{
		printf("O %i quadro contera %llu graos.\n", i, graos);
		
		if (i == 64)
		{
			break;
		}
		
		graos = graos * 2;
	}
	
	long long unsigned kg = (graos / 100000);
	
	long long unsigned toneladas = kg / 1000;
	
	printf("\n\nO monge esperava receber %llu graos de trigo.\n", graos);
	printf("Este numero equivaleria a %llu kgs de trigo.\n", kg);
	printf("O total seria de %llu toneladas de trigo.\n\n", toneladas);
	
	return 0;
}
