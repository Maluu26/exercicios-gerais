#include<stdio.h>
#include<stdlib.h>
#include"relatorio.h"
#include"aluno.h"
#include"vector.h"

int main(){
    int quantAlunos = 0;
    scanf("%d", &quantAlunos);
    Vector *vetor = VectorConstruct();
    for(int i = 0; i<quantAlunos;i++){
        tAluno *aluno = CriaAluno();
        LeAluno(aluno);
        VectorPushBack(vetor, aluno);
    }
    ImprimeRelatorio(vetor);
    VectorDestroy(vetor, DestroiAluno);
    return 0;
}