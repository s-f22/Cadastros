#include <stdio.h>
int soma(int n)
{   if(n==0) return 0;
    else return soma(n-1) + n;
}
int main()
{
    printf("Soma Recursiva: %d\n", soma(4));
    return 0;
}
