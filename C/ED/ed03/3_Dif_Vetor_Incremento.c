/*
ALUNO: Samuel Figueiredo

3- Suponha que v é um vetor. Descreva a diferença conceitual entre as expressões v[3] e v + 3. 
 
*/

#include <stdio.h> 

int main() 
{ 
    int v[] = {1,2,3,4}; 
    
    printf("v[0] = %i\n", v[0]);
    printf("v[1] = %i\n", v[1]);
    printf("v[2] = %i\n", v[2]);
    printf("v[3] = %i\n\n", v[3]); // imprime o valor contido em v[3];
    printf("v = %i\n", v);
    printf("v + 1 = %i\n", v + 1);
    printf("v + 2 = %i\n", v + 2);
    printf("v + 3 = %i\n", v + 3); // mostra o endereco de memoria correspondente a quarta posicao do vetor v;
    
    return 0; 

} 
