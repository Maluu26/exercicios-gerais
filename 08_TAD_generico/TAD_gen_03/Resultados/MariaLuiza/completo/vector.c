#include"vector.h"
#include<stdlib.h>
#include<stdio.h>

struct Vector{
    data_type *vetor;
    int qntd;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct(){
    Vector *vetor = (Vector*)malloc(sizeof(Vector));
    vetor->vetor = NULL;
    vetor->qntd = 0;
    return vetor;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, data_type val){
    if(v!=NULL){
        v->qntd++;
        v->vetor = realloc(v->vetor,v->qntd*sizeof(data_type));
        v->vetor[v->qntd-1] = val;
    }
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return data_type Elemento do vetor
*/
data_type VectorGet(Vector *v, int i){
    if(v!=NULL){
        return v->vetor[i];
    }
}

int VectorSize(Vector *v){
    if(v!=NULL) return v->qntd;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(data_type)){
    if(v!=NULL){
        for(int i =0;i<v->qntd;i++){
            destroy(v->vetor[i]);
        }
         free(v->vetor);
         free(v);
    }
       
}

