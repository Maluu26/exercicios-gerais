#include "esfera_utils.h"
#include<math.h>

float calcula_volume(float R){
    float volume = 0;
    return (4*PI*pow(R,3))/3;
}
float calcula_area(float R){
     float area = 0;
     return 4*PI*pow(R,2);
}
