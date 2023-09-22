#include <stdio.h>
#include "data.h"

int main()
{
    int dia1, mes1, ano1, dia2, mes2, ano2, diferenca;
    scanf("%d/%d/%d", &dia1, &mes1, &ano1);
    tData data1, data2;
    data1 = CriaData(dia1, mes1,ano1);
    scanf("%d/%d/%d", &dia2, &mes2, &ano2);
    data2 = CriaData(dia2, mes2, ano2);
    if (VerificaDataValida(data1) == 1 && (VerificaDataValida(data2) == 1))
    {
        diferenca = CalculaDiferencaDias(data1, data2);
        printf("Primeira data: ");
        ImprimeDataExtenso(data1);
        printf("Segunda data: ");
        ImprimeDataExtenso(data2);
        if (ComparaData(data1, data2) == 0)
        {

            printf("As datas sao iguais\n");
        }
        else if (ComparaData(data1, data2) == 1)
        {
            printf("A primeira data eh mais antiga\n");
        }
        else
        {
            printf("A segunda data eh mais antiga\n");
        }
        printf("A diferenca em dias entre as datas eh: %02d dias\n", diferenca);
    }
    else
    {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
    }
    return 0;
}
