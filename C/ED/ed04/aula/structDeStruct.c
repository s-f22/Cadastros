#include <stdio.h>
#include <string.h>

 

struct {
    int ra;
    float p1;
    float p2;
    float p3;
    float media; 
} typedef dadosDoAluno;

 

struct{
    int ra;
    char nome[50];
    char email[50];
    dadosDoAluno notas;
} typedef aluno;

 


void mostrar(dadosDoAluno *p){
    //printf("\n ra=%i , p1=%f, p2=%f, p3=%f, media= %f",
    //(*p).ra, (*p).p1, (*p).p2, (*p).p3, (*p).media);
    
    printf("\n ra=%i , p1=%f, p2=%f, p3=%f, media= %f",
    p->ra, p->p1, p->p2, p->p3, p->media);
}

 

 

int main()
{
    dadosDoAluno maria;
    
    maria.ra = 345;
    maria.p1 = 8;
    maria.p2 = 10;
    maria.p3 = 0;
    maria.media = (maria.p1 + maria.p2) /2;
    
    mostrar(&maria);
    
    dadosDoAluno alunos[5];
    
    alunos[0] = maria;
    
    mostrar(&alunos[0]);
    
    dadosDoAluno joao = {234,7,9,0,0};
    joao.media = (joao.p1 + joao.p2) /2;
    mostrar(&joao);
    
    aluno jose = {34,"jose","jose@norton.net.br"};
    jose.notas.p1 = 5;
    jose.notas.p2 = 8;
    printf("\nra=%i, nome=%s, email=%s, p1=%f, p2=%f", 
    jose.ra, jose.nome, jose.email, jose.notas.p1, 
    jose.notas.p2);
    
    
    
    return 0;
}
