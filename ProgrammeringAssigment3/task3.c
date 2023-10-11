//
// Created by Mats on 11.10.2023.
//

#include "stdio.h"

int main(void) {
    double x, y;

    while (1) {
        printf("verdi en: ");
        scanf("%lf", &x);
        printf("verdi to: ");
        scanf("%lf", &y);

        if (x == 0 || y == 0) {
            printf("\n fuk you, try agan!!!\n ");
        } else {
            break;
        }
    }

    double val = x / y;
    printf("%g / %g = %.2g", x, y, val);
}