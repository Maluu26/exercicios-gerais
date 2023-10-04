#include <stdio.h>
#include "pessoa.h"

int main()
{
    int quant_pessoas = 0, associados = 0;
    scanf("%d", &quant_pessoas);
    tPessoa pessoas[quant_pessoas];
    for (int i = 0; i < quant_pessoas; i++)
    {

        pessoas[i] = CriaPessoa();
    }

    scanf("%d", &associados);
    for (int i = 0; i < associados; i++)
    {
        AssociaFamiliasGruposPessoas(pessoas);
    }

    return 0;
}
