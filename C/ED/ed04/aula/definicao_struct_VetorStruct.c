#include <stdio.h>
#include <string.h>

 

struct {
    int ra;
    float p1;
    float p2;
    float p3;
    float media; 
} typedef avalia;

 


void mostrar(avalia *p){
    printf("\n ra=%i , p1=%f, p2=%f, p3=%f, media= %f",
    (*p).ra, (*p).p1, (*p).p2, (*p).p3, (*p).media);
}

 

 

int main()
{
    avalia maria;
    
    maria.ra = 345;
    maria.p1 = 8;
    maria.p2 = 10;
    maria.p3 = 0;
    maria.media = (maria.p1 + maria.p2) /2;
    
    mostrar(&maria);
    
    avalia alunos[5];
    
    alunos[0] = maria;
    
    mostrar(&alunos[0]);
    
    avalia joao = {234,7,9,0,0};
    joao.media = (joao.p1 + joao.p2) /2;
    mostrar(&joao);
    
    
    return 0;
}
