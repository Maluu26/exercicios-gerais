#include <stdio.h>
#include "data.h"

int main()
{
    int dia1, mes1, ano1, dia2, mes2, ano2, diferenca;
    scanf("%d/%d/%d", &dia1, &mes1, &ano1);
    if (verificaDataValida(dia1, mes1, ano1) == 1)
    {

        printf("Data informada: ");
        imprimeDataExtenso(dia1, mes1, ano1);
       
        if (verificaBissexto(ano1) == 0)
        {
            printf("O ano informado nao eh bissexto\n");
        }
        else
        {
            printf("O ano informado eh bissexto\n");
        }
        printf("O mes informado possui %d dias\n", numeroDiasMes(mes1, ano1));
        printf("A data seguinte eh: ");
        imprimeProximaData(dia1, mes1, ano1);
    }
    else
    {
        printf("A data informada eh invalida\n");
    }
    return 0;
}

