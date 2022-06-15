#include <stdio.h>
#include <time.h>
int main()
{
    int i;
    for(i = 10; i >= 0; i--)
    {
        printf("%i\n",i); // Exibe a atual contagem do contador
        delay(1000); // Espera um segundo
    }
    return 0;
}
