/*
ALUNO: Samuel Figueiredo

2- Escreva uma função mm que receba um vetor inteiro v[0..n-1] 
e os endereços de duas variáveis inteiras, digamos min e max, 
e deposite nessas variáveis o valor de um elemento mínimo e o 
valor de um elemento máximo do vetor. Escreva também uma função 
main que use a função mm. 
*/

#include <stdio.h> 

void mm(int v[], int *min, int *max) 
{
	int a;
    for(a = 0; a < 5; a++) //substituir "5" pelo numero de elementos do vetor "v", em main; 
    { 
        if(a == 0) 
        { 
            *max = v[a]; 
            *min = v[a]; 
        } 
        
        if(v[a] > *max) 
            *max = v[a]; 

      else 
        { 
            if(v[a] < *min) 
                *min = v[a]; 
        } 
    } 
} 


int main() 
{ 
    int v[] = {45,2,90,7,22}; 
    int min, max; 

    mm(v, &min, &max); 

    printf("Min: %i\nMax: %i", min,max); 
    
    return 0; 

} 
