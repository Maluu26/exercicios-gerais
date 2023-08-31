#include <stdio.h>
#include "esfera_utils.h"

int main(){
    
    float raio = 0, volume = 0, area = 0;
    scanf("%f", &raio);
    volume = calcula_volume(raio);
    area = calcula_area(raio);
    printf("Area: %.2f\n Volume: %.2f\n", area,volume);
    return 0;
}