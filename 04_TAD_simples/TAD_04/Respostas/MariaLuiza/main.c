#include <stdio.h>
#include "aluno.h"

int main()
{
    int num_alunos = 0, i = 0, j, k=0;
   
    scanf("%d", &num_alunos);
    tAluno aluno[num_alunos], aux;
    for (i = 0; i < num_alunos; i++)
    {
        aluno[i] = LeAluno();
    }

    for (i = 0; i < num_alunos - 1; i++)
    {
        for (j = i; j < num_alunos; j++)
        {
            if (ComparaMatricula(aluno[i], aluno[j]) == 1)
            {
                aux = aluno[i];
                aluno[i] = aluno[j];
                aluno[j] = aux;
            }
        }
    }
    for (i = 0; i < num_alunos; i++)
    {
        if (VerificaAprovacao(aluno[i]) == 1)
        {
            ImprimeAluno(aluno[i]);
        }
    }
}
