#include <stdio.h>
#include "aluno.h"

int main()
{
    int num_alunos = 0, i = 0, j;
    char nome[50];
    int matricula = 0, n1 = 0, n2 = 0, n3 = 0;
    scanf("%d", &num_alunos);
    tAluno aluno[num_alunos], aux;
    for (i = 0; i < num_alunos; i++)
    {
        scanf("%s %d %d %d %d", nome, &matricula, &n1, &n2, &n3);
        aluno[i] = criar_aluno(nome, &matricula, &n1, &n2, &n3);
    }

    for (i = 0; i < num_alunos; i++)
    {
        for (j = i; j < num_alunos; j++)
        {
            if (comparar_matricula_aluno(aluno[i], aluno[j]) == 1)
            {
                aux = aluno[i];
                aluno[i] = aluno[j];
                aluno[j] = aux;
            }
        }
    }
    for (i = 0; i < num_alunos; i++)
    {
        if (aluno_aprovado(aluno[i]) == 1)
        {
            imprimir_aluno(aluno[i]);
        }
    }
}
