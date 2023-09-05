#include <stdio.h>
#include "matrix_utils.h"
int main()
{
    int rows1, cols1, rows2, cols2;
    scanf("%d %d", &rows1, &cols1);
    int matrix1[rows1][cols1];
    matrix_read(rows1, cols1, matrix1);
    scanf("%d %d", &rows2, &cols2);
    int matrix2[rows2][cols2];
    matrix_read(rows2, cols2, matrix2);
    int opcao = 0;

    while (opcao != 6)
    {
        printf("1 - Somar matrizes \n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\n");
        printf("Opcao escolhida: \n");
        scanf("%d", &opcao);

        if (opcao == 1 && possible_matrix_sum(rows1, cols1, rows2, cols2) == 1)
        {
            int result[rows1][cols1];
            matrix_add(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
            matrix_print(rows1, cols1, result);
        }
        else if (opcao == 2 && possible_matrix_sub(rows1, cols1, rows2, cols2) == 1)
        {
            int result[rows1][cols1];
            matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
            matrix_print(rows1, cols1, result);
        }
        else if (opcao == 3 && possible_matrix_multiply(cols1, rows2) == 1)
        {
            int result[rows1][cols1];
            matrix_multiply(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
            matrix_print(rows1, cols2, result);
        }
        else if (opcao == 3 && possible_matrix_multiply(cols1, rows2) == 0)
        {
            printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
        }
        else if ((opcao == 1 && possible_matrix_sum(rows1, cols1, rows2, cols2) == 0) || (opcao == 2 && possible_matrix_sub(rows1, cols1, rows2, cols2) == 0))
        {
            printf("Erro: as dimensoes da matriz nao correspondem\n\n");
        }
        else if (opcao == 4)
        {
            int scalar, num_matrix;
            scanf("%d %d", &scalar, &num_matrix);
            if (num_matrix == 1)
            {
                scalar_multiply(rows1, cols1, matrix1, scalar);
                matrix_print(rows1, cols1, matrix1);
            }
            else
            {
                scalar_multiply(rows2, cols2, matrix2, scalar);
                matrix_print(rows2, cols2, matrix2);
            }
        }
        else if (opcao == 5)
        {
            int result1[rows1][cols1];
            int result2[rows2][cols2];
            transpose_matrix(rows1, cols1, matrix1, result1);
            matrix_print(cols1, rows1, result1);
            transpose_matrix(rows2, cols2, matrix2, result2);
            matrix_print(cols2, rows2, result2);
        }
    }
    return 0;
}
