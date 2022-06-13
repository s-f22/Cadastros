    /*
    1- Suponha que os elementos do vetor v são do tipo int e cada int
    ocupa 8 bytes no seu computador. Se o endereço de v[0] é 55000, qual o
    valor da expressão v + 3?
    v[0] = 55000 
    v[1] = 55008
    v[2] = 55016
    v[3] = 55024

    2- Escreva uma função mm que receba um vetor inteiro v[0..n-1] e os
    endereços de duas variáveis inteiras, digamos min e max, e deposite nessas
    variáveis o valor de um elemento mínimo e o valor de um elemento máximo do
    vetor.Escreva também uma função main que use a função mm.


    3- Suponha que v é um vetor. Descreva a diferença conceitual entre
    as expressões v[3] e v + 3.
    R. v[3] e o formato de acesso ao indice 3 do vetor 
       v + 3 = vai buscar o valor do indice 0 do vetor 0 e somar + 3 
       

    4- Reescreva o programa do caixa eletrônico utilizando ponteiros.
    faça um algoritmo que simule o funcionamento de um caixa eletrônico, onde será apresentado uma lista de operações:
    1-Saldo
    2-Saque
    3-Deposito
    Ao iniciar o programa determine um valor inicial para a variável saldo (utilize um ponteiro para manter o valor do saldo), se o cliente escolher a opção 1 mostre o valor do saldo, caso escolha o valor 2 leia o valor a ser sacado e verifique se existe saldo suficiente, se o saldo for maior ou igual , deduza da variável saldo o valor solicitado, caso não haja saldo suficiente mostre a mensagem “Saldo Insuficiente”, caso a opção 3 seja escolhida adicione o valor informado de deposito ao saldo. Implemente um laço faça enquanto que verifique se o usuário deseja continuar, caso a variável coletada for igual 1 reinicie o laço, mantendo o valor do saldo.
    */

#include <stdio.h>

void mm(int p[], int tam, int *min, int *max){
    int x;
    for(x=0;x<tam;x++){
        printf("V=%i min=%i max=%i \n", p[x], *min, *max);
        if(x==0){
            (*min) = p[x]; 
            (*max) = p[x]; 
        } else {
            if((*min)>(p[x])) (*min) = (p[x]); 
            if((*max)<(p[x])) (*max) = (p[x]); 
        }
    }
    
}

int main()
{
    int numeros[] = {3,6,32,234,762,2,32,45,87,23};
    int minimo, maximo;
    int tamanho = sizeof(numeros) / sizeof(int);
    mm(numeros, tamanho, &minimo, &maximo);
    printf("Min=%i, Max=%i", minimo, maximo);
    return 0;
}
