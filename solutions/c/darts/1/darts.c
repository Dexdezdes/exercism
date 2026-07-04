#include "darts.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>

uint8_t score(coordinate_t landing_position){
    float distance = powf(landing_position.x,2)+powf(landing_position.y,2);
    if (distance <= 1){
        return 10;
    } else if (distance <= 25){
        return 5;
    } else if (distance <= 100){
        return 1;
    } else {
        return 0;
    }
}