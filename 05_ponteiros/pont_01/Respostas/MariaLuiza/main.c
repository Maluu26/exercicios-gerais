#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

// Defina e implemente TrocaInterios

int main()
{
    int n1, n2;

    while (scanf("%d %d", &n1, &n2) == 2)
    { // int *pn1 = n1;
        // int *pn2 = n2;
        if (TrocaInterios(&n1, &n2))
        {
            printf("TROCADO: %d %d\n", n1, n2);
        }
        else
        {
            printf("ORIGINAL: %d %d\n", n1, n2);
        }
    }

    return 0;
}
