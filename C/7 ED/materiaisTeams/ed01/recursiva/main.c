#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int fatorial(int num)
{
  printf("num=%i \n", num);
  if (num == 0) {
    return 1;
  }
  else {
    return num * fatorial(num-1);
  }
}

//3 =>  3*2 = 6 * 1 = 6 
//4 => 4*3 = 12 * 2 = 24 * 1 = 24

int main(int argc, char *argv[]) {
	printf("fatorial 3 %i \n", fatorial(3));
	printf("fatorial 4 %i \n", fatorial(4));
	printf("fatorial 5 %i \n", fatorial(5));
	return 0;
}
