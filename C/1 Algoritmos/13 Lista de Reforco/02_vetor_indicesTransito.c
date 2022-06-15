/*

c-crie um vetor do tipo real , que armazene 24  indices de 
transito da cidade uma para cada hora do dia, em um primeiro 
laço o usuário vai informar os indices, em um segundo laço 
identifique a media dos indices do dia, o maior indice e o menor indice

*/




#include <stdio.h>

int main()
{

    int indices = 5;

    int vetor[5];
    int maior, menor;

    
    int media;
    int i, j;

    for (i = 0; i < indices; i++)
    {
        printf("Insira o %i indice: ", i + 1);
        scanf("%i", &vetor[i]);

        media = (media + vetor[i]);

    }

    media = (media / indices);

    printf("%i", media);

    for (j = 0; j < indices; j++)
    {
        if(j == 0) menor, maior = vetor[j];
        
        else
        
        	if (vetor[j] > maior && vetor[j] > menor) maior = vetor[j];
        
        	if (vetor[j] < menor && vetor[j] != maior) menor = vetor[j];
        
        

    }

    printf("\nMedia dos indices: %i%%", media);
    printf("\nMaior indice: %i%% \nMenor indice: %i%%", maior, menor);
    

    

    return 0;
}
