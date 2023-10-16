#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"
float adicao(float n1, float n2)
{
    return n1 + n2;
}
float subtracao(float n1, float n2)
{
    return n1 - n2;
}
float multiplicacao(float n1, float n2)
{
    return n1 * n2;
}
float divisao(float n1, float n2)
{
    return n1 / n2;
}

int main()
{
    float a = 0, b = 0, resultado = 0;
    char op = 'b';
    float (*CalculatoraCallback)(float, float);
    while (op != 'f')
    {

        scanf("%c", &op);

        if (op == 'f')
        {
            break;
        }
        else
        {
            scanf("%f %f", &a, &b);
            if (op == 'a')
            {
                CalculatoraCallback = adicao;
                resultado = Calcular(a, b, CalculatoraCallback);
                printf("%.2f + %.2f = %.2f\n", a, b, resultado);
            }
            if (op == 's')
            {
                CalculatoraCallback = subtracao;
                resultado = Calcular(a, b, CalculatoraCallback);
                printf("%.2f - %.2f = %.2f\n", a, b, resultado);
            }
            if (op == 'm')
            {
                CalculatoraCallback = multiplicacao;
                resultado = Calcular(a, b, CalculatoraCallback);
                printf("%.2f x %.2f = %.2f\n", a, b, resultado);
            }
            if (op == 'd')
            {
                CalculatoraCallback = divisao;
                resultado = Calcular(a, b, CalculatoraCallback);
                printf("%.2f / %.2f = %.2f\n", a, b, resultado);
            }
        }
        scanf("%*c");
    }
    return 0;
}
