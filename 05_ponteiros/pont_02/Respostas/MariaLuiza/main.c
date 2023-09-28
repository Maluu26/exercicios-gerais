#include <stdio.h>
#include "utils.h"

int main()
{
    int casos;

    scanf("%d", &casos);
    while (casos)
    {
        int m, n, menor, maior;
        LeIntervalo(&m, &n);

        ObtemMaiorEMenorPrimo(m, n, &menor, &maior);

        printf("%d %d\n", menor, maior);

        casos--;
    }
    return 0;
}
