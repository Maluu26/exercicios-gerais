#include <stdio.h>
#include "data.h"

int main()
{
    int dia1, mes1, ano1, dia2, mes2, ano2, diferenca;
    scanf("%d/%d/%d", &dia1, &mes1, &ano1);
    scanf("%d/%d/%d", &dia2, &mes2, &ano2);
    if (verificaDataValida(dia1, mes1, ano1) == 1 && (verificaDataValida(dia2, mes2, ano2) == 1))
    {
        diferenca = calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2);
        printf("Primeira data:");
        imprimeDataExtenso(dia1, mes1, ano1);
        printf("\nSegunda data:");
        imprimeDataExtenso(dia2, mes2, ano2);
        if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 0)
        {

            printf("\nAs datas sao iguais");
        }
        else if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == -1)
        {
            printf("\nA primeira data eh mais antiga\n");
        }
        else
        {
            printf("\nA segunda data eh mais antiga\n");
        }
        printf("A diferenca em dias entre as datas eh: %02d", diferenca);
    }
    else
    {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
    }
    return 0;
}
