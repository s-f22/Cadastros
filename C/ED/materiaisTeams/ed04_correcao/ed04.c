/******************************************************************************

 Crie um TAD que implemente o controle de uma 
conta bancaria, implemente funções para inicializar, 
deposito, sacar e imprimir o saldo.

*******************************************************************************/

#include <stdio.h>

struct {
    int agencia;
    int conta;
    float saldo;
} typedef contaCorrente;

void abrirConta(contaCorrente *p){
    printf("\nInforme agencia e conta:");
    scanf("%i %i", &p->agencia, &p->conta);
    
    printf("Informe o valor de deposito inicial:");
    scanf("%f", &p->saldo);
}

void imprimir(contaCorrente *p){
    printf("\n Saldo = %.2f", p->saldo);
}

void saque(contaCorrente *p){
    float valor;
    printf("\n Informe o valor a ser sacado:");
    scanf("%f", &valor);
    if(p->saldo >= valor){
        p->saldo = (p->saldo - valor);
        printf("\nSaque efetuado, saldo atual=%.2f",p->saldo);
    } else {
        printf("\nSaldo insuficiente!!!");
    }
}

void deposito(contaCorrente *p){
    float valor;
    printf("\n Informe o valor a ser depositado:");
    scanf("%f", &valor);
    p->saldo = (p->saldo + valor);
    printf("\nDeposito efetuado, saldo atual=%.2f",p->saldo);
    
}


int main()
{
    contaCorrente c1;
    
    abrirConta(&c1);
    imprimir(&c1);
    saque(&c1);
    imprimir(&c1);
    deposito(&c1);
    saque(&c1);
    imprimir(&c1);
    
    contaCorrente *p2 = 
        (contaCorrente*)malloc(sizeof(contaCorrente));
        
    abrirConta(p2);
    imprimir(p2);

    return 0;
}
