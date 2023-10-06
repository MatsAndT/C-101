//
// Created by Mats on 06.10.2023.
//

#include <stdio.h>

int triangularNumber(int n) {
    return n * (n+1) / 2;
}

int main(void) {
    int end = 50;
    int n = 5;

    printf("\n");

    for (n = 5; n <= 50; n = n+5) {
        printf("Triangular number %i is %i, \n", n, triangularNumber(n));
    }
}