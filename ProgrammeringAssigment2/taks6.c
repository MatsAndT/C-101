//
// Created by Mats on 28.09.2023.
//

#include <stdio.h>
#include <math.h>

double func(double x) {
    return 3 * pow(x,3) - 5 * pow(x, 2) + 2 * 6;
}

int main() {
    double x = 2.55;

    printf("f(%lf) = %lf\n", x, func(x));


    return 0;
}