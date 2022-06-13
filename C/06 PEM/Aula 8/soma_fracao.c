#include <stdio.h>
float soma(int n)
{   if(n==0) return 0.0;
    else return soma(n-1) + (float)n/(n+1);
}
int main()
{
    printf("Soma Recursiva: %f\n", soma(10));
    return 0;
}
