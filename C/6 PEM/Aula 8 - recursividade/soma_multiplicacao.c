#include <stdio.h>
int pot(int base, int expoente)
{   if(expoente == 0) return 1;
    else return pot(base, expoente -1) * base ;
}
int main()
{
    printf("Potencia Recursiva: %d\n", pot(2, 10));
    return 0;
}
