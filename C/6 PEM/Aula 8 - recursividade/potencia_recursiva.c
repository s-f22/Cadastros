#include <stdio.h>
int pot(int base)
{   
	if(base == 1) return 1;
    else return pot((base - 1) * base) + (base * base);
}
int main()
{
    printf("Potencia Recursiva: %d\n", pot(10));
    return 0;
}
