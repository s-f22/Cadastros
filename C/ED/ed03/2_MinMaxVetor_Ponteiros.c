/*
ALUNO: Samuel Figueiredo

2- Escreva uma fun��o mm que receba um vetor inteiro v[0..n-1] 
e os endere�os de duas vari�veis inteiras, digamos min e max, 
e deposite nessas vari�veis o valor de um elemento m�nimo e o 
valor de um elemento m�ximo do vetor. Escreva tamb�m uma fun��o 
main que use a fun��o mm. 
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
