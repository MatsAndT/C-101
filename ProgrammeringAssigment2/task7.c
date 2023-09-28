//
// Created by Mats on 28.09.2023.
//

#include <stdio.h>
#include <math.h>

int main(void) {
    double val = (3.31 * pow(10,-8) * 2.01 * pow(10, -7)) / (7.16 * pow(10, -6) + 2.01 * pow(10, -8));
    printf("%e", val);

    return 0;
}