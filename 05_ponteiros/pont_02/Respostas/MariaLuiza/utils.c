#include <stdio.h>
#include "utils.h"
/**
 * @brief Lê do usuário um intervalo de números inteiros.
 *
 * Esta função recebe como parâmetro dois ponteiros para inteiros e lê do usuário os valores correspondentes ao início e fim de um intervalo.
 *
 * @param m Ponteiro para a variável que receberá o valor do início do intervalo.
 * @param n Ponteiro para a variável que receberá o valor do fim do intervalo.
 */
void LeIntervalo(int *m, int *n)
{
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    *m = n1;
    *n = n2;
}

/**
 * @brief Verifica se um número é primo.
 *
 * Esta função recebe como parâmetro um número inteiro e verifica se ele é primo.
 *
 * @param n Número a ser verificado.
 * @return 1 se o número é primo, 0 caso contrário.
 */
int EhPrimo(int n)
{

    int i = 0;
    int div = 0;
    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            div++;
        }
    }
    if (div == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief Obtém o maior e o menor número primo em um intervalo.
 *
 * Esta função recebe como parâmetro dois números inteiros que representam o início e o fim de um intervalo, e dois ponteiros para inteiros que receberão os valores do maior e do menor número primo encontrado no intervalo.
 *
 * @param m Início do intervalo.
 * @param n Fim do intervalo.
 * @param menor Ponteiro para a variável que receberá o menor número primo encontrado.
 * @param maior Ponteiro para a variável que receberá o maior número primo encontrado.
 */
void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior)
{
    int quant_primos = 0, i, primo_n;
    for (i = m; i <= n; i++)
    {
        primo_n = EhPrimo(i);
        if (primo_n == 1)
        {
            quant_primos++;
            if (quant_primos == 1)
            {
                *menor = i;
            }
            *maior = i;
        }
    }
}
