#include<stdio.h>
#include"empresa.h"


int main(){
    int casos,i;
    scanf("%d", &casos); 
    tEmpresa empresa[casos];
    for(i=0;i<casos;i++){
        empresa[i] = leEmpresa();
        
    }
for(i=0;i<casos;i++){
    imprimeEmpresa(empresa[i]);
    }
    return 0;
}