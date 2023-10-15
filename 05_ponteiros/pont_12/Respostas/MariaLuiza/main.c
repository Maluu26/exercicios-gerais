#include <stdio.h>
#include "vetor.h"
int soma(int a, int b)
{
    return a + b;
}
int multiplicação(int a, int b)
{
    return a * b;
}
int main()
{
    int quant_num = 0;
    Vetor vetor;
    int (*Operation)(int, int);
    LeVetor(&vetor);
    Operation = soma;
    int resultado = AplicarOperacaoVetor(&vetor, Operation);
    printf("Soma: %d\n", resultado);
    Operation = multiplicação;
    int resultado1 = AplicarOperacaoVetor(&vetor, Operation);
    printf("Produto: %d\n", resultado1);
    return 0;
}
