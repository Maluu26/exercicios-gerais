#include <stdio.h>
#include "matrix_utils.h"
int main()
{
   tMatrix matrix1;
   int opcao = 0, rows1=0, cols1=0, rows2=0, cols2=0;
   scanf("%d %d", &rows1, &cols1);
   matrix1 = MatrixCreate(rows1, cols1);
   matrix1 = MatrixRead(matrix1);
   scanf("%d %d", &rows2, &cols2);
   tMatrix matrix2;
   matrix2 = MatrixCreate(rows2, cols2);
   matrix2 = MatrixRead(matrix2);
   while (opcao != 6)
   { if(opcao!=6){
       printf("1 - Somar matrizes \n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\n");
       printf("Opcao escolhida: \n");
       scanf("%d", &opcao);


       if (opcao == 1 && PossibleMatrixSum(matrix1, matrix2) == 1)
       {
           tMatrix result;
           result = MatrixAdd(matrix1, matrix2);
           MatrixPrint(result);
       }
       else if (opcao == 2 && PossibleMatrixSub(matrix1, matrix2) == 1)
       {
           tMatrix result;
           result = MatrixSub(matrix1, matrix2);
           MatrixPrint(result);
       }
       else if (opcao == 3 && PossibleMatrixMultiply(matrix1, matrix2) == 1)
       {   tMatrix result;
           result = MatrixMultiply(matrix1, matrix2);
           MatrixPrint(result);
          
       }
       else if (opcao == 3 && PossibleMatrixMultiply(matrix1, matrix2)== 0)
       {
           printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
       }
       else if ((opcao == 1 && PossibleMatrixSum(matrix1, matrix2) == 0) || (opcao == 2 && PossibleMatrixSub(matrix1,matrix2) == 0))
       {
           printf("Erro: as dimensoes da matriz nao correspondem\n\n");
       }
       else if (opcao == 4)
       {
           int scalar, num_matrix;
           scanf("%d %d", &scalar, &num_matrix);
           if (num_matrix == 1)
           {
               matrix1 = MatrixMultiplyByScalar(matrix1, scalar);
               MatrixPrint(matrix1);
           }
           else
           {
               matrix2 = MatrixMultiplyByScalar(matrix2, scalar);
               MatrixPrint(matrix2);
           }
       }
       else if (opcao == 5)
       {
           tMatrix result1, result2;
           result1 = TransposeMatrix(matrix1);
           MatrixPrint(result1);
           result2 = TransposeMatrix( matrix2);
           MatrixPrint(result2);
       }else{
           break;
       }
       }
   }
   return 0;
}

