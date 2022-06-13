#include <stdio.h>

 

void
troca (int *i, int *j)
{
  int temp;            //ANTES int *temp;
  temp = *i;            //ANTES *temp = *i; 
  *i = *j;
  *j = temp;            //ANTES *j = *temp;
}

 


int
main ()
{
  int x, *p;
  x = 100;
  p = &x;            //ANTES p = x;  
  printf ("Valor de *p: %d.\n", *p);

 

  char *a, *b;
  a = &"abacate";        //ANTES a = "abacate";
  b = &"uva";            //ANTES b = "uva";
  if (a < b)
    printf ("%s vem antes de %s no dicionC!rio", a, b);
  else
    printf ("%s vem depois de %s no dicionC!rio", a, b);

 

 

  return 0;
}
