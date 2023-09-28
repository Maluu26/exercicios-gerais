#include <stdio.h>
#include <stdlib.h>
#include "departamento.h"

int main()
{
    int num_deptos = 0, i, m1 = 0, m2 = 0, m3 = 0;
    char diretor[50], c1[50], c2[50], c3[50], nome[50];
    double media_geral = 0;
    scanf("%d", &num_deptos);
    tDepartamento deptos[num_deptos];

    for (i = 0; i < num_deptos; i++)
    {
        scanf("%s %s %s %s %s %d %d %d", nome, diretor, c1, c2, c3, &m1, &m2, &m3);
        if (validaMediaDepartamento(m1) == 0)
        {
            scanf("%d", &m1);
        }
        else if (validaMediaDepartamento(m2) == 0)
        {
            scanf("%d", &m2);
        }
        else if (validaMediaDepartamento(m2) == 0)
        {
            scanf("%d", &m3);
        }
        deptos[i] = criaDepartamento(c1, c2, c3, nome, m1, m2, m3, diretor);
    }
    ordenaPorMediaDepartamentos(deptos, num_deptos);
    for (i = 0; i < num_deptos; i++)
    {
        imprimeAtributosDepartamento(deptos[i]);
       
    }

    return 0;
}
