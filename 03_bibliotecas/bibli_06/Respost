#include<stdio.h>
#include "temperature_conversor.h"
int main(){
    float temperatura = 0, convertida = 0;
    char de, para;
    scanf("*c");
    scanf("%f %c %c", &temperatura, &de, &para);
    if(de == 'c' && para == 'k' ){
        convertida = convert_temperature(temperatura, convert_celsius_to_kelvin);
        printf("Temperature: %.2fK", convertida);
    }else if(de == 'c' && para == 'f'){
         convertida = convert_temperature(temperatura, convert_celsius_to_fahrenheit);
         printf("Temperature: %.2fF", convertida);
    }else if(de == 'k' && para == 'c'){
        convertida = convert_temperature(temperatura, convert_kelvin_to_celsius);
        printf("Temperature: %.2fC", convertida);
    }else if(de == 'k' && para == 'f'){
        convertida = convert_temperature(temperatura, convert_kelvin_to_fahrenheit);
        printf("Temperature: %.2fF", convertida);
    }else if(de == 'f' && para == 'c'){
        convertida = convert_temperature(temperatura, convert_fahrenheit_to_celsius);
        printf("Temperature: %.2fC", convertida);
    }else if(de == 'f' && para == 'k'){
        convertida = convert_temperature(temperatura, convert_fahrenheit_to_kelvin);
        printf("Temperature: %.2fK", convertida);
    }
    
}
