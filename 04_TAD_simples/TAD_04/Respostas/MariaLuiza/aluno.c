#include <stdio.h>
#include "aluno.h"

/**
 * @brief Cria um novo aluno com os dados informados.
 *
 * @param nome Nome do aluno.
 * @param matricula Matrícula do aluno.
 * @param n1 Nota da primeira avaliação.
 * @param n2 Nota da segunda avaliação.
 * @param n3 Nota da terceira avaliação.
 * @return tAluno Retorna uma estrutura tAluno com os dados do aluno criado.
 */
tAluno criar_aluno(char *nome, int matricula, int n1, int n2, int n3)
{
    tAluno novo_aluno;
    int i;
    while (nome[i] != '\0')
    {
        novo_aluno.nome[i] = nome[i];
        i++;
    }

    novo_aluno.matricula = matricula;
    novo_aluno.n1 = n1;
    novo_aluno.n2 = n2;
    novo_aluno.n3 = n3;

    return novo_aluno;
}

/**
 * @brief Compara as matrículas de dois alunos.
 *
 * @param aluno1 Primeiro aluno a ser comparado.
 * @param aluno2 Segundo aluno a ser comparado.
 * @return int Retorna 1 se a matrícula do aluno1 é maior que a do aluno2, -1 se a matrícula do aluno1 é menor que a do aluno2 e 0 se as matrículas são iguais.
 */
int comparar_matricula_aluno(tAluno aluno1, tAluno aluno2)
{
    if (aluno1.matricula > aluno2.matricula)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

/**
 * @brief Calcula a média das notas de um aluno.
 *
 * @param aluno Aluno a ter a média calculada.
 * @return int Retorna a média das notas do aluno.
 */
int calcular_media_aluno(tAluno aluno)
{
    return ((aluno.n1 + aluno.n2 + aluno.n3) / 3);
}

/**
 * @brief Verifica se um aluno foi aprovado ou reprovado.
 *
 * @param aluno Aluno a ser verificado.
 * @return int Retorna 1 se o aluno foi aprovado e 0 se foi reprovado.
 */
int aluno_aprovado(tAluno aluno)
{
    if (calcular_media_aluno(aluno) >= 7)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief Imprime os dados de um aluno.
 *
 * @param aluno Aluno a ser impresso.
 */
void imprimir_aluno(tAluno aluno)
{
    printf("%s\n", aluno.nome);
}
