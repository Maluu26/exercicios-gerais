
#include<stdlib.h>
#include<stdio.h>
#include"pacote.h"
struct pacote {
    void *msg; 
    Type tipo;
    int soma;
    int size;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote* CriaPacote(Type type, int numElem){
    tPacote *pac = malloc(sizeof(tPacote));
    pac->soma = 0;
    pac->tipo = type;
    pac->size = numElem;
    if(type == INT){
        pac->msg = malloc(sizeof(int)*numElem);      
    }
    else{
         pac->msg = malloc(sizeof(char)*numElem);
    }
    return pac;

}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote* pac){
    free(pac->msg);
    free(pac);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote* pac){
    if(pac->tipo == INT){
        for(int i = 0; i<pac->size;i++){
            scanf("%d", &((int*)pac->msg)[i]);
        }
    }else{
        scanf("%s", ((char*)pac->msg));
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote* pac){
    printf("%d  ", pac->soma);
    if(pac->tipo == INT){
        
        for(int i = 0;i<pac->size;i++){
            printf("%d ",((int*)pac->msg)[i]);
        }
        
    }else{
         printf("%s ",((char*)pac->msg));
    }
    printf("\n");
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote* pac){
    for(int i = 0;i<pac->size;i++){
        pac->soma = (((int*)pac->msg)[i])+pac->soma;

    }
}
