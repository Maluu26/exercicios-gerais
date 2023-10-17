#include<stdio.h>
#include<stdlib.h>
#include"utils.h"

int main(){
    int quant_vetor;
    scanf("%d", &quant_vetor);
    int *vetor = CriaVetor(quant_vetor);
    printf("%.2f", CalculaMedia(vetor,quant_vetor));

}