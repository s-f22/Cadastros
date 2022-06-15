#include<stdio.h>
void hanoi (int n, char origem, char destino, char auxiliar) 
{ 
         if(n==1) printf("Mova o disco do pino %c para o pino %c\n", origem, destino); 
         else{ 
            hanoi(n-1, origem, auxiliar, destino);  //transporto N-1 discos da origem para o auxiliar
            printf("Mova o disco do pino %c para o pino %c\n", origem, destino);  
            hanoi(n-1, auxiliar, destino, origem);  //transporto N-1 discos do auxiliar para o destino
         } 
}    
int main () 
{ 
         printf("Resolvendo a Torre de Hanoi para 3 discos:\n"); 
         hanoi(3, 'A', 'C', 'B'); 
                
         printf("Resolvendo a Torre de Hanoi para 4 discos:\n"); 
         hanoi(4, 'A', 'C', 'B');
         return 0;
} 

