//
// Created by Mats on 28.09.2023.
//

#include <stdio.h>
#include <complex.h>

int main(void) {
    float x = 2;
    float y = 4;
    float z = 6;

    float res1 = (x / (y / z));
    float res2 = x + y * z;
    float res3 = x + ( y * z);
    float res4 = (x * y) + z;

    printf("x = %g, y = %g, z = %g\n", x, y, z);
    printf("%g \n", res1);
    printf("%g \n", res2);
    printf("%g \n", res3);
    printf("%g \n", res4);
    
    _Complex double complex1 = 1.0 + 3.0 * I;
    printf("%g + %gi\n", creal(complex1), cimag(complex1));

    printf("%i \n", 1 % 8);
    printf("%i \n", 1 % 3);
    printf("%i \n", 8 % 3);

    return 0;
}