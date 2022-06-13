#include <stdio.h>

int fib(int N)
{   if(N<=2) return 1;
    else return fib(N-1) + fib(N-2);
}

int main()
{   int i;
    for(i=1; i<=50; i++)
        printf("%d ", fib(i));
    
    printf("\nNumero de ouro: %f", (float)fib(10)/fib(9));
    printf("\nNumero de ouro: %f", (float)fib(15)/fib(14));
    return 0;
}


