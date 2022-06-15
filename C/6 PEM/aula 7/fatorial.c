#include <stdio.h>
int fatorial(int N)
{
    printf("Estou tentando resolver o fatorial de %d\n", N);
    if (N == 0)
    {
        printf("Cheguei na base. O fatorial de 0 � 1\n");
        return 1;
    }
    else
    {
        int aux = N * fatorial(N - 1);
        printf("Calculei o fatorial de %d, que vale %d\n", N, aux);
        return aux;
    }
}
int main()
{
    printf("Fatorial de %d vale %d", 5, fatorial(5));
    return 0;
}
