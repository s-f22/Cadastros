//3) Comente o trecho abaixo linha-a-linha e mostre o que será impresso pelo comando printf:
 
    int vet[ ] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };    
    int * p = &(vet[2]);                            
    int i;                                        
    for ( i = 1; i <= 6; i++ )                        
    {    printf ("%d -  ", *p);                        
        p++;                                                        
    }                                        

//Saída: Vai mostrar o endereço de mem correspondente a 6, e os demais com o conteudo que eventualmente houver na memoria até 14





4) Por que o primeiro scanf abaixo usa o operador '&' e o segundo não?
 
    int x;
    scanf("%d", &x);
    char nome[50];
    scanf("%s", nome);
    
    pq no primeiro eu estou informando o valor do endereço atraves da variavel x, enquanto no segundo eu ja informo o endereço diretamente atraves do indice do vetor nome



