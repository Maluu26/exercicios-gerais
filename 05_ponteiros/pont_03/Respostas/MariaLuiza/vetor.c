#include<stdio.h>
#include"vetor.h"
/**
 * @brief Lê dados do usuário e armazena em um vetor.
 * 
 * Esta função recebe como parâmetro um vetor e seu tamanho, e lê do usuário os valores a serem armazenados no vetor.
 * 
 * @param vet Ponteiro para o vetor que receberá os valores lidos.
 * @param tam Tamanho do vetor.
 */
void LeDadosParaVetor(int * vet, int tam){
    for(int i=0;i<tam;i++){ 
        scanf("%d", &vet[i]);
        
        }
   
}

/**
 * @brief Imprime os dados de um vetor na tela.
 * 
 * Esta função recebe como parâmetro um vetor e seu tamanho, e imprime na tela os valores armazenados no vetor.
 * 
 * @param n Ponteiro para o vetor a ser impresso.
 * @param tam Tamanho do vetor.
 */
void ImprimeDadosDoVetor(int * n, int tam){
    int i;
    int *pnt;
    pnt = n;
    for(i=0;i<tam;i++){
        if(i == tam - 1){
            printf("%d\n", *(pnt+i));
        }   
        else{
        printf("%d ", *(pnt+i));
    }
    }
}

/**
 * @brief Troca o valor de duas variáveis se o segundo for menor que o primeiro.
 * 
 * Esta função recebe como parâmetro um vetor, seu tamanho e um ponteiro para uma variável que será usada para armazenar o índice do menor valor encontrado. A função percorre o vetor e, se encontrar um valor menor que o valor armazenado na variável apontada por paraTrocar, atualiza essa variável e troca os valores das posições correspondentes no vetor.
 * 
 * @param vet Ponteiro para o vetor a ser percorrido.
 * @param tam Tamanho do vetor.
 * @param paraTrocar Ponteiro para a variável que armazenará o índice do menor valor encontrado.
 */
void TrocaSeAcharMenor(int * vet, int tam, int * paraTrocar){
    int aux;
    for(int *i = paraTrocar + 1; i<tam+vet;i++){
        if(*paraTrocar> *i){
            aux = *paraTrocar;
            *paraTrocar = *i;
            *i = aux;
            
        }
    
    }
}

/**
 * @brief Ordena um vetor em ordem crescente.
 * 
 * Esta função recebe como parâmetro um vetor e seu tamanho, e ordena os valores do vetor em ordem crescente.
 * 
 * @param vet Ponteiro para o vetor a ser ordenado.
 * @param tam Tamanho do vetor.
 */
void OrdeneCrescente(int * vet, int tam){
    for(int i = 0;i<tam;i++){
            TrocaSeAcharMenor(vet, tam, &vet[i]);
    }

}

