#include "relatorio.h"
#include"aluno.h"
#include<stdio.h>
#include<stdlib.h>

/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 * 
 * @param alunos Ponteiro para o vetor de alunos.
*/
void ImprimeRelatorio(Vector *alunos){
   float genF = 0, genM = 0, genO = 0, media = 0, aprovados = 0;
   //tAluno *aluno = (tAluno*)alunos;
   for(int i = 0; i<VectorSize(alunos); i++){
      switch(GetGeneroAluno(VectorGet(alunos, i))){
         case'O':
            genO++;
            break;
         case 'F':
            genF++;
            break;
         case 'M':    
            genM++;
            break;
      }
      media = media + GetNotaAluno(VectorGet(alunos, i));
      if(GetNotaAluno(VectorGet(alunos, i))>=6){
         aprovados++;
      }
    }
   media = media/VectorSize(alunos);
   aprovados = (aprovados/VectorSize(alunos))*100;
   genM = (genM/VectorSize(alunos))*100;
   genF = (genF/VectorSize(alunos))*100;
   genO = (genO/VectorSize(alunos))*100;
   printf("Media das notas: %.2f\n",media);
   printf("Porcentagem de alunos aprovados: %.2f%\n",aprovados);
   printf("Porcentagem de cada genero:\n");
   printf("Masculino: %.2f%\n", genM);
   printf("Feminino: %.2f%\n", genF);
   printf("Outro: %.2f%\n", genO);
   
   
   



   }
