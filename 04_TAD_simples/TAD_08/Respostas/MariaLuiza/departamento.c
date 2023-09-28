#include <stdio.h>
#include "departamento.h"
#include <string.h>
#include <math.h>
/**
 * @brief Cria um departamento a partir de valores nomes dos cursos, nome do departamento, média por curso e nome do diretor.
 *
 * @param c1 Nome de um dos cursos do departamento.
 * @param c2 Nome de um dos cursos do departamento.
 * @param c3 Nome de um dos cursos do departamento.
 * @param nome Nome do departamento.
 * @param m1 Média do curso c1.
 * @param m2 Média do curso c2.
 * @param m3 Média do curso c3.
 * @param diretor Nome do diretor.
 * @return tDepartamento Departamento criado a partir dos valores nomes dos cursos, nome do departamento, média por curso e nome do diretor.
 */
tDepartamento criaDepartamento(char *c1, char *c2, char *c3, char *nome, int m1, int m2, int m3, char *diretor)
{
    tDepartamento depto;
    strcpy(depto.c1, c1);
    strcpy(depto.c2, c2);
    strcpy(depto.c3, c3);
    strcpy(depto.nome, nome);
    strcpy(depto.diretor, diretor);
    depto.m1 = m1;
    depto.m2 = m2;
    depto.m3 = m3;
    depto.media_geral = calculaMediaGeralDepartamento(depto);
    return depto;
}

/**
 * @brief Imprime os atributos do departamento, sendo eles: cursos, nome do departamento, média por curso e nome do diretor.
 *
 * @param depto Departamento cujos atributos serão impressos.
 */
void imprimeAtributosDepartamento(tDepartamento depto)
{
    printf("ATRIBUTOS:\ndepartamento => %s\ndiretor => %s\ncurso1 => %s, media1 => %d\ncurso2 => %s, media2 => %d\ncurso3 => %s, media3 => %d\nmedia geral => %.2f\ndesvio padrao => %.2f\n\n", depto.nome, depto.diretor, depto.c1, depto.m1, depto.c2, depto.m2, depto.c3, depto.m3, depto.media_geral, calculaDesvioPadraoDepartamento(depto));
}

/**
 * @brief Verifica se a media inserida é valida, ou seja, pertence à [0, 10].
 *
 * @param media Valor a ser validado.
 * @return int Se é válida (1) ou não (0).
 */
int validaMediaDepartamento(int media)
{
    if (media < 0 || media > 10)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/**
 * @brief Calcula o Desvio Padrão das médias por curso de um departamento.
 *
 * @param depto Departamento cujo Desvio Padrão de médias por curso deve ser calculado.
 * @return double Valor do cálculo do Desvio Padrão.
 */
double calculaDesvioPadraoDepartamento(tDepartamento depto)
{
    // double d1 = ;
    double desvio = sqrt((pow(depto.m1 - depto.media_geral, 2) + pow(depto.m2 - depto.media_geral, 2) + pow(depto.m3 - depto.media_geral, 2)) / 3.0);
    return desvio;
}

/**
 * @brief Calcula a média simples das notas dos cursos do departamento.
 *
 * @param depto Departamento cuja media simples deve ser calculada.
 * @return double Valor do calculo da média simples.
 */
double calculaMediaGeralDepartamento(tDepartamento depto)
{
    return (depto.m1 + depto.m2 + depto.m3) / 3.0;
}

/**
 * @brief Ordena o vetor de departamentos em ordem decrescente de acordo com as médias dos departamentos.
 *
 * @param deptos Vetor de departamentos a ser ordenado.
 * @param tamanho Tamanho do vetor a ser ordenado.
 */
void ordenaPorMediaDepartamentos(tDepartamento d[], int tamanho)
{
    int i, j;
    tDepartamento aux;
    for (i = 0; i < tamanho; i++)
    {
        for (j = i; j < tamanho; j++)
        {
            if (d[i].media_geral < d[j].media_geral)
            {
                aux = d[i];
                d[i] = d[j];
                d[j] = aux;
            }
        }
    }
}
