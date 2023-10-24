//
// Created by Mats on 24.10.2023.
//

#include "stdio.h"

float absoluteValue(float x) {
    if (x < 0) {
        x = -x;
    }
    return x;
}

// Function to compute the square root of a number
float squareRoot(float x, float epsilon) {
    float guess = 1.0;

    while (absoluteValue(guess * guess - x) >= epsilon) {
        guess = (x / guess + guess) / 2.0;
    }

    return guess;
}

int main(void) {
    double a,b,c, discreiminant, rot1, rot2;
    printf("Regler A!=0 \n");
    printf("Hva er A B C ? ");
    scanf("%lf %lf %lf", &a, &b, &c);

    discreiminant = b*b-4*a*c;

    if (discreiminant == 0) {
        rot1 = rot2 = -b / 2*a;
        printf("rot1 = rot2 = %.2lf", rot1);

    } else if (discreiminant < 0) {
        // Blir imaginært tall
        printf("det blir imaginare tall!");
    } else {
        rot1 = ( -b + squareRoot(discreiminant, 0.0001) ) / 2 *a;
        rot2 = ( -b - squareRoot(discreiminant, 0.0001) ) / 2 *a;
        printf("rot1 = %.2lf, rot2 = %.2lf", rot1, rot2);
    }
}