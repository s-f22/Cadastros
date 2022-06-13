#include <stdio.h>
#include <stdlib.h>
void bomba(int n)
{   printf("%d, ", n);
    if(n > 0) bomba(n-1);
    else printf("BOOOMM!");
}

int main()
{
    bomba(10);
    return 0;
}
