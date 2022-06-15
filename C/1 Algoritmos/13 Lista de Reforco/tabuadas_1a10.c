
#include <stdio.h>

int main()
{
	int i, j, result;
	
printf("Tabuadas entre 1 e 10.\n");

            for (i = 1; i <= 10; i++)
            {
                for (j = 1; j <= 10; j++)
                {
                	result = i * j;
                    printf("%i x %i = %i\n", i, j, result);
                }
                printf("\n\n");
        	}
                
                
	return 0;
}
