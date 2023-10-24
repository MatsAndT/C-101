//
// Created by Mats on 24.10.2023.
//

#include "stdio.h"

int main(void) {
    double points[10] = {1,2,3,4,5,6,7,8,9,10};
    double sum = 0;
    int index;

    for (index = 0; index < 10; index++) {
        sum += points[index];
    }

    double avange = sum / 10;

    printf("the avarge is: %g", avange);
    return 0;
}