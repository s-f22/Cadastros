    /*
    
    4- Reescreva o programa do caixa eletrônico utilizando ponteiros.
    faça um algoritmo que simule o funcionamento de um caixa eletrônico, onde será apresentado uma lista de operações:
    1-Saldo
    2-Saque
    3-Deposito
    Ao iniciar o programa determine um valor inicial para a variável saldo (utilize um ponteiro para manter o valor do saldo), se o cliente escolher a opção 1 mostre o valor do saldo, caso escolha o valor 2 leia o valor a ser sacado e verifique se existe saldo suficiente, se o saldo for maior ou igual , deduza da variável saldo o valor solicitado, caso não haja saldo suficiente mostre a mensagem “Saldo Insuficiente”, caso a opção 3 seja escolhida adicione o valor informado de deposito ao saldo. Implemente um laço faça enquanto que verifique se o usuário deseja continuar, caso a variável coletada for igual 1 reinicie o laço, mantendo o valor do saldo.
    */

#include <stdio.h>

void saldo(float *saldo){
    printf("O saldo da conta=%f\n", *saldo);
}

void saque(float *saldo){
    float valor;
    printf("Qual o valor a ser sacado:");
    scanf("%f", &valor);
    if(valor>*saldo){
        printf("Saldo Insuficiente !!!!\n");
    } else {
        *saldo = *saldo - valor;
        printf("Saque realizado !!! \n");
    }
}


void deposito(float *saldo){
    float valor;
    printf("Qual o valor a ser depositado:");
    scanf("%f", &valor);
    *saldo = *saldo + valor;
    printf("deposito realizado !!! \n");
}

int main()
{
    float valor = 500;
    saldo(&valor); 
   
    deposito(&valor);
    saque(&valor);
    saldo(&valor);
   
    deposito(&valor);
    saque(&valor);
    saldo(&valor);
    return 0;
}
